#include "triangletests.h"

TriangleTests::TriangleTests() {

}

void TriangleTests::initTestCase() {
    m_shapeManager = ShapeManager::getInstance();
    m_triangle = new Triangle(Point(0,0), Point(100,100), Point(200,20));
    bool status = m_shapeManager->TryToAddShape(m_triangle);
    QVERIFY2(status == true, "Failed to add initial triangle");
}

void TriangleTests::cleanupTestCase() {
    delete m_triangle;
    m_shapeManager->ClearShapes();
}

void TriangleTests::testInnerTriangle() {
    Triangle* triangle = new Triangle(Point(40,30), Point(45,40), Point(42,25));
    bool isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "Test Case failed for inner triangle.");
}

void TriangleTests::testInnerToOuterTriangle() {
    Triangle* triangle = new Triangle(Point(5,10), Point(40,30), Point(190,10));
    bool isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "Test Case failed for innerToOuter triangle.");
}

void TriangleTests::testOuterTriangle() {
    Triangle* triangle = new Triangle(Point(220,30), Point(240, 30), Point(230,40));
    bool isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == false, "Test Case failed for inner triangle.");
}

void TriangleTests::testTouchingTriangle() {
    Triangle* triangle = new Triangle(Point(0,0), Point(50,50), Point(0,50));
    bool isCollision = m_shapeManager->checkCollision(triangle);
    delete triangle;
    QVERIFY2(isCollision == true, "Test Case failed for touching triangle.");
}
