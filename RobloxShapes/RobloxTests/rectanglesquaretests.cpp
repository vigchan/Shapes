#include "rectanglesquaretests.h"

RectangleSquareTests::RectangleSquareTests()
{

}

void RectangleSquareTests::initTestCase() {
    m_shapeManager = ShapeManager::getInstance();
    BoundingRectangle boundingRect(0,0, 50, 60);
    m_rectangle = new Rectangle(boundingRect);
    m_square = new Square(Point(110, 0), 60);
    bool isSuccess = m_shapeManager->TryToAddShape(m_rectangle);
    QVERIFY2(isSuccess == true, "Failed to add initial rectangle");
    isSuccess = m_shapeManager->TryToAddShape(m_square);
    QVERIFY2(isSuccess == true, "Failed to add initial square");
}

void RectangleSquareTests::cleanupTestCase() {
    delete m_rectangle;
    delete m_square;
    m_shapeManager->ClearShapes();
}

void RectangleSquareTests::insideIntersectionTests() {
    Square* square = new Square(Point(20,20), 60);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Inner square intersects with outer rectangle");

    Rectangle* rectangle = new Rectangle(BoundingRectangle(120,20, 30,80));
    isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "Inner rectangle intersects with outer square");

}

void RectangleSquareTests::insideTests() {
    Square* square = new Square(Point(20,30), 20);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Square touches rectangle internally but is not");

    Rectangle* rectangle = new Rectangle(BoundingRectangle(120,20, 30,20));
    isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "rectangle touches square internally but is not");
}

void RectangleSquareTests::insideTouchTests() {
    Square* square = new Square(Point(20,20), 60);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Inner square intersects with outer rectangle");

    Rectangle* rectangle = new Rectangle(BoundingRectangle(120,20, 30,50));
    isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "Inner rectangle intersects with outer square");
}

void RectangleSquareTests::outsideTouchTests() {
    Square* square = new Square(Point(50,0), 20);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Inner square intersects with outer rectangle");

    Rectangle* rectangle = new Rectangle(BoundingRectangle(170,0, 30,20));
    isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "Inner rectangle intersects with outer square");
}

void RectangleSquareTests::outsideIntersectionTests() {
    Square* square = new Square(Point(40,0), 30);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Inner square intersects with outer rectangle");

    Rectangle* rectangle = new Rectangle(BoundingRectangle(160,0, 30,20));
    isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "Inner rectangle intersects with outer square");
}
