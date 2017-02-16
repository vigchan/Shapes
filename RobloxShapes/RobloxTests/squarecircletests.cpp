#include "squarecircletests.h"

SquareCircleTests::SquareCircleTests()
{

}

void SquareCircleTests::initTestCase() {
    m_shapeManager = ShapeManager::getInstance();
    m_square = new Square(Point(0,0), 100);
    m_circle = new Circle(50, Point(160, 160));
    bool isSuccess = m_shapeManager->TryToAddShape(m_square);
    QVERIFY2(isSuccess == true, "Failed to add initial square");
    isSuccess = m_shapeManager->TryToAddShape(m_circle);
    QVERIFY2(isSuccess == true, "Failed to add initial circle");
}

void SquareCircleTests::cleanupTestCase() {
    delete m_square;
    delete m_circle;
    m_shapeManager->ClearShapes();
}

void SquareCircleTests::insideIntersectionTests() {
    Circle* circle = new Circle(50, Point(60,60));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Inner circle intersects with outer square");

    Square* square = new Square(Point(170,170), 60);
    isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Inner square intersects with outer circle");
}

void SquareCircleTests::insideTests() {
    Circle* circle = new Circle(10, Point(20,20));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Inner circle does not intersect with outer square");

    Square* square = new Square(Point(170,170), 10);
    isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Inner square does not intersect with outer circle");
}

void SquareCircleTests::insideTouchTests() {
    Circle* circle = new Circle(10, Point(90,90));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "circle touches the square internally");

    circle = new Circle(5, Point(250,250));
    bool success = m_shapeManager->TryToAddShape(circle);
    QVERIFY2(success == true, "circle not added in an empty space successfully");

    Square* square = new Square(Point(250 - 5/sqrt(2), 250 - 5/sqrt(2)), 5 * sqrt(2));
    isCollision = m_shapeManager->checkCollision(square);
    delete square;
    m_shapeManager->removeShape(circle);
    delete circle;
    QVERIFY2(isCollision == true, "square touches the circle internally");
}

void SquareCircleTests::outsideIntersectionTests() {
    Circle* circle = new Circle(30, Point(120,120));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "circle intersects with square externally");

    Square* square = new Square(Point(105,105), 20);
    isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Inner square intersects with externally");
}

void SquareCircleTests::outsideTouchTests() {
    Circle* circle = new Circle(5, Point(100,105));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "circle touches the square externally");

    Square* square = new Square(Point(160,210), 20);
    isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "square touches with externally");
}
