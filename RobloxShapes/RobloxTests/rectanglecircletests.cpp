#include "rectanglecircletests.h"

RectangleCircleTests::RectangleCircleTests()
{

}

void RectangleCircleTests::initTestCase() {
    m_shapeManager = ShapeManager::getInstance();
    BoundingRectangle boundingRect(0,0, 100, 100);
    m_rectangle = new Rectangle(boundingRect);
    m_circle = new Circle(50, Point(160, 160));
    bool isSuccess = m_shapeManager->TryToAddShape(m_rectangle);
    QVERIFY2(isSuccess == true, "Failed to add initial rectangle");
    isSuccess = m_shapeManager->TryToAddShape(m_circle);
    QVERIFY2(isSuccess == true, "Failed to add initial circle");

}

void RectangleCircleTests::cleanupTestCase() {
    delete m_rectangle;
    delete m_circle;
    m_shapeManager->ClearShapes();
}

void RectangleCircleTests::insideTests() {
    Circle* circle = new Circle(10, Point(20,20));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Inner circle does not intersect with outer rectangle");

    Rectangle* rectangle = new Rectangle(BoundingRectangle(170,170, 10, 10));
    isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "Inner rectangle does not intersect with outer circle");
}

void RectangleCircleTests::insideIntersectionTests() {
    Circle* circle = new Circle(50, Point(60,60));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Inner circle intersects with outer rectangle");

    Rectangle* rectangle = new Rectangle(BoundingRectangle(170,170, 60, 60));
    isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "Inner rectangle intersects with outer circle");
}

void RectangleCircleTests::outsideIntersectionTests() {
    Circle* circle = new Circle(30, Point(120,120));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "circle intersects with rectangle externally");

    Rectangle* rectangle = new Rectangle(BoundingRectangle(105,105, 20, 20));
    isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "Inner rectangle intersects with externally");
}

void RectangleCircleTests::insideTouchTests() {
    Circle* circle = new Circle(10, Point(90,90));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "circle touches the rectangle internally");

    circle = new Circle(5, Point(250,250));
    bool success = m_shapeManager->TryToAddShape(circle);
    QVERIFY2(success == true, "circle not added in an empty space successfully");

    Rectangle* rectangle = new Rectangle(BoundingRectangle(246, 243, 8, 6));
    isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    m_shapeManager->removeShape(circle);
    delete circle;
    QVERIFY2(isCollision == true, "rectangle touches the circle internally");

}

void RectangleCircleTests::outsideTouchTests() {
    Circle* circle = new Circle(5, Point(100,105));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "circle touches the rectangle externally");

    Rectangle* rectangle = new Rectangle(BoundingRectangle(160,210, 20, 20));
    isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "rectangle touches with externally");
}
