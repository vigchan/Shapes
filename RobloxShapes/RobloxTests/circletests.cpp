#include "circletests.h"

CircleTests::CircleTests()
{

}

void CircleTests::initTestCase() {
    m_shapeManager = ShapeManager::getInstance();
    m_circle = new Circle(50, Point(50,50));
    bool status = m_shapeManager->TryToAddShape(m_circle);
    QVERIFY2(status == true, "Failed to add initial circle");
}

void CircleTests::cleanupTestCase() {
    delete m_circle;
    m_shapeManager->ClearShapes();
}

void CircleTests::testInnerCircle() {
    Circle *circle = new Circle(20, Point(45,45));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Test Case failed for inner circle. Should not be detected as a collision.");
}

void CircleTests::testInnerToOuterCircle() {
    Circle *circle = new Circle(60, Point(60,60));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Test case failed for inner-outer circle. Should be detected as collision.");
}

void CircleTests::testOuterToInnerCircle() {
    Circle *circle = new Circle(60, Point(110,110));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Test case failed for outer-inner circle. Should be detected as collision.");
}

void CircleTests::testOuterCircle() {
    Circle *circle = new Circle(10, Point(110,110));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == false, "Test Case failed for outer circle. Should not be detected as a collision.");
}

void CircleTests::testTouchingCircleOuter() {
    Circle * circle = new Circle(10, Point(110, 50));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Test Case failed for touching circle. Should not be detected as a collision.");
}

void CircleTests::testTouchingCircleInner() {
    Circle * circle = new Circle(10, Point(90, 50));
    bool isCollision = m_shapeManager->checkCollision(circle);
    delete circle;
    QVERIFY2(isCollision == true, "Test Case failed for touching circle. Should not be detected as a collision.");
}




