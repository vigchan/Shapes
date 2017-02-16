#include "trianglesquaretests.h"

TriangleSquareTests::TriangleSquareTests()
{
}

void TriangleSquareTests::initTestCase() {
    m_shapeManager = ShapeManager::getInstance();
    m_triangle = new Triangle(Point(0,0), Point(50,50), Point(100,0));
    m_square = new Square(Point(160, 0), 50);
    bool isSuccess = m_shapeManager->TryToAddShape(m_triangle);
    QVERIFY2(isSuccess == true, "Failed to add initial triangle");
    isSuccess = m_shapeManager->TryToAddShape(m_square);
    QVERIFY2(isSuccess == true, "Failed to add initial square");
}

void TriangleSquareTests::cleanupTestCase() {
    delete m_triangle;
    delete m_square;
    m_shapeManager->ClearShapes();
}

void TriangleSquareTests::insideIntersectionTests() {
    Square* square = new Square(Point(40,40), 50);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Inner square intersects with outer triangle");

    Triangle* triangle = new Triangle(Point(160,10), Point(180,10), Point(165,60));
    isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "Inner triangle intersects with outer square");
}

void TriangleSquareTests::insideTests() {
    Square* square = new Square(Point(50,10), 10);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "square is inside triangle");

    Triangle* triangle = new Triangle(Point(180,10), Point(190,10), Point(190,20));
    isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "triangle is inside square");

}

void TriangleSquareTests::insideTouchTests() {
    Square* square = new Square(Point(50,0), 10);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "square touches triangle internally");

    Triangle* triangle = new Triangle(Point(180,0), Point(190,0), Point(180,10));
    isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "triangle touches with square internally");
}

void TriangleSquareTests::outsideIntersectionTests() {
    Square* square = new Square(Point(30,40), 30);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "square touches triangle externally");

    Triangle* triangle = new Triangle(Point(130,10), Point(130,40), Point(160,10));
    isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "triangle touches with square externally");
}

void TriangleSquareTests::outsideTouchTests() {
    Square* square = new Square(Point(50,50), 10);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "square touches triangle externally");

    Triangle* triangle = new Triangle(Point(160,50), Point(190,60), Point(210,50));
    isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "triangle touches with square externally");
}
