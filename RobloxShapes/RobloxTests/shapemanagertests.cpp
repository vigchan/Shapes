#include "shapemanagertests.h"
#include "../line.h"

ShapeManagerTests::ShapeManagerTests()
{

}

void ShapeManagerTests::initTestCase() {
    m_shapeManager = ShapeManager::getInstance();
    m_width = 350;
    m_height = 150;
    m_shapeManager->setBoundingRectangle(BoundingRectangle(0,0, m_width, m_height));
    Rectangle* rectangle = new Rectangle(BoundingRectangle(0,0, 50, 50));
    m_shapes.append(rectangle);
    Circle* circle = new Circle(50, Point(125, 50));
    m_shapes.append(circle);
    Triangle* triangle = new Triangle(Point(250, 50), Point(200,0), Point(250, 0));
    m_shapes.append(triangle);
    Square* square = new Square(Point(275,0), 50);
    m_shapes.append(square);

    bool status = false;
    m_totalShapesArea = 0;
    for(int i=0; i < m_shapes.size(); i++) {
        status = m_shapeManager->TryToAddShape(m_shapes[i]);
        m_totalShapesArea += m_shapes[i]->getArea();
        QVERIFY2(status == true, "Failed to add initial shape");
    }
}

void ShapeManagerTests::cleanupTestCase() {
    for(int i=0; i < m_shapes.size(); i++) {
        m_totalShapesArea -= m_shapes[i]->getArea();
        m_shapeManager->removeShape(m_shapes[i]);

        // Try adding back the same shape and validate the success
        bool status = m_shapeManager->TryToAddShape(m_shapes[i]);
        QVERIFY2(status == true, "Add shape after remove should succeed");
        m_shapeManager->removeShape(m_shapes[i]);

        // Validate the running area
        QVERIFY2(m_shapeManager->getAreaRemaining() == (m_width * m_height) - m_totalShapesArea, "Area not consistent");
        delete m_shapes[i];
    }
    // Validate the end area
    QVERIFY2(m_shapeManager->getAreaRemaining() == (m_width * m_height), "Area not clear of all shapes");
    m_shapes.clear();
}

void ShapeManagerTests::validateOversizedShapes() {
    QVector<Shape*> shapes;
    Rectangle* rectangle = new Rectangle(BoundingRectangle(
                                             0,0, m_width+10, m_height+10));
    shapes.append(rectangle);
    Square* square = new Square(Point(0,0), m_width+10);
    shapes.append(square);
    Triangle* triangle = new Triangle(Point(m_width+10, 50),Point(m_height+10, 0),
                                      Point(250,250));
    shapes.append(triangle);
    Circle* circle = new Circle(m_width + 10, Point(50,50));
    shapes.append(circle);
    for(int i=0; i < shapes.size(); i++) {
        bool status = m_shapeManager->TryToAddShape(shapes[i]);
        QVERIFY2(status == false, "Should not able able to add oversized shapes" );
        delete shapes[i];
    }
    shapes.clear();
}

void ShapeManagerTests::validateGetShapeFromPoint() {

    for(int i = 0; i < m_shapes.size(); i++) {
        Point leftPos = m_shapes[i]->getLeftPoint();
        Shape* shape = m_shapeManager->getShapeForPoint(Point(leftPos.getX()+1, leftPos.getY()));

        QVERIFY2(shape != NULL && shape->getShapeType() == m_shapes[i]->getShapeType(),
            "Point should correspond to the right shape");

        shape = m_shapeManager->getShapeForPoint(Point(leftPos.getX(), leftPos.getY()));
        QVERIFY2(shape != NULL && shape->getShapeType() == m_shapes[i]->getShapeType(),
            "Point should correspond to the right shape");

        shape = m_shapeManager->getShapeForPoint(Point(leftPos.getX()-1, leftPos.getY()));
        QVERIFY2(shape == NULL, "Should not be able to find shape by point");
    }
}

void ShapeManagerTests::validateShapeMove() {

    for(int i =0; i < m_shapes.size(); i++) {
        Point leftPos = m_shapes[i]->getLeftPoint();
        BoundingRectangle rect = m_shapes[i]->getBoundingRectangle();

        Point moveStartPos(leftPos.getX()+1, leftPos.getY());
        Shape* shape = m_shapeManager->getShapeForPoint(moveStartPos);
        Q_ASSERT(shape != NULL && shape->getShapeType() == m_shapes[i]->getShapeType());

        double displacement = 10;

        // Displace horizontally
        Point moveEndPosHorizontal(moveStartPos.getX() + displacement, moveStartPos.getY());
        bool status = m_shapeManager->tryMove(moveStartPos, moveEndPosHorizontal);
        Q_ASSERT(status == true);

        Point newLeftPoint = shape->getLeftPoint();
        BoundingRectangle newRect = m_shapes[i]->getBoundingRectangle();
        validateValuesForShapeMove(newLeftPoint, leftPos, newRect, rect, displacement, 0);

        leftPos = newLeftPoint;
        rect = newRect;

        // Displace vertically
        Point moveEndPosVertical = Point(newLeftPoint.getX(), newLeftPoint.getY()+displacement);
        status = m_shapeManager->tryMove(leftPos, moveEndPosVertical);
        Q_ASSERT(status == true);

        newLeftPoint = shape->getLeftPoint();
        newRect = shape->getBoundingRectangle();
        validateValuesForShapeMove(newLeftPoint, leftPos, newRect, rect, 0, displacement);

        // Displace to a place where shape exists
        displacement += 50;
        status = m_shapeManager->tryMove(newLeftPoint, Point(newLeftPoint.getX()+displacement,
            newLeftPoint.getY()));
        QVERIFY2(status == false, "Shape exists and should instersect with the current shape but did not.");

    }

}

void ShapeManagerTests::validateValuesForShapeMove(Point newPoint, Point oldPoint,
    BoundingRectangle newRect, BoundingRectangle oldRect, double xDisplacement, double yDisplacement) {

    QVERIFY2(newPoint.getX() == oldPoint.getX() + xDisplacement, "X position of moved object not equal");
    QVERIFY2(newPoint.getY() == oldPoint.getY() + yDisplacement, "Y Position of moved object not equal");
    QVERIFY2(newRect.getLeft() == oldRect.getLeft() + xDisplacement, "Left of bounding rectangle not equal");
    QVERIFY2(newRect.getTop() == oldRect.getTop() + yDisplacement, "Top of bounding rectangle not equal");
    QVERIFY2(newRect.getWidth() == oldRect.getWidth() , "Top of bounding rectangle not equal");
    QVERIFY2(newRect.getHeight() == oldRect.getHeight(), "Top of bounding rectangle not equal");
}
