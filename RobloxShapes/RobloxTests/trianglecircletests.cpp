#include "trianglecircletests.h"

TriangleCircleTests::TriangleCircleTests()
{

}

void TriangleCircleTests::initTestCase() {
    m_shapeManager = ShapeManager::getInstance();
    m_triangle = new Triangle(Point(0,0), Point(50,50), Point(100,0));
    m_circle = new Circle(50, Point(160, 160));
    bool isSuccess = m_shapeManager->TryToAddShape(m_triangle);
    QVERIFY2(isSuccess == true, "Failed to add initial triangle");
    isSuccess = m_shapeManager->TryToAddShape(m_circle);
    QVERIFY2(isSuccess == true, "Failed to add initial circle");
}

void TriangleCircleTests::cleanupTestCase() {
    delete m_triangle;
    delete m_circle;
    m_shapeManager->ClearShapes();
}

void TriangleCircleTests::insideIntersectionTests() {
    Circle* circle = new Circle(50, Point(40,40));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Inner circle intersects with outer triangle");

    Triangle* triangle = new Triangle(Point(130,160), Point(160,230), Point(190,160));
    isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "Inner triangle intersects with outer circle");
}

void TriangleCircleTests::insideTests() {
    Circle* circle = new Circle(10, Point(20,20));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Inner circle does not intersect with outer triangle");

    Triangle* triangle = new Triangle(Point(130,160), Point(160,190), Point(190,160));
    isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "Inner triangle intersects with outer circle");
}

void TriangleCircleTests::insideTouchTests() {
    Circle* circle = new Circle(10, Point(50,10));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Inner circle does not touch with outer triangle");

    Triangle* triangle = new Triangle(Point(130,160), Point(160,210), Point(190,160));
    isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "Inner triangle touches with outer circle");
}

void TriangleCircleTests::outsideIntersectionTests() {
    Circle* circle = new Circle(20, Point(50,60));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "circle does not intersect with triangle");

    Triangle* triangle = new Triangle(Point(130,240), Point(160,160), Point(190,240));
    isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "triangle does not intersect with circle");
}

void TriangleCircleTests::outsideTouchTests() {
    Circle* circle = new Circle(10, Point(50,60));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "circle does not touch with outer triangle");

    Triangle* triangle = new Triangle(Point(130,240), Point(160,210), Point(190,240));
    isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "triangle does not touch the circle externally");
}
