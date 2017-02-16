#include "squaretests.h"

SquareTests::SquareTests()
{
}

void SquareTests::initTestCase()
{
    m_shapeManager = ShapeManager::getInstance();
    m_square = new Square(Point(0,0), 100);
    bool status = m_shapeManager->TryToAddShape(m_square);
    QVERIFY2(status == true, "Failed to add initial square");
}

void SquareTests::cleanupTestCase()
{
    delete m_square;
    m_shapeManager->ClearShapes();
}

void SquareTests::testInnerSquare()
{
    Square* square = new Square(Point(10, 10), 20);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Test Case failed for inner square.");
}

void SquareTests::testInnerToOuterSquare()
{
    Square* square = new Square(Point(10, 10), 110);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Test Case failed for inner-outer square. Should be detected as a collision.");
}

void SquareTests::testOuterSquare()
{
    Square* square = new Square(Point(101, 101), 20);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == false, "Test Case failed for outer square. Should not be detected as a collision.");
}

void SquareTests::testTouchingSquare() {
    Square* square = new Square(Point(100,100), 1);
    bool isCollision = m_shapeManager->checkCollision(square);
    delete square;
    QVERIFY2(isCollision == true, "Test Case failed for touching square. Should be detected as a collision.");
}
