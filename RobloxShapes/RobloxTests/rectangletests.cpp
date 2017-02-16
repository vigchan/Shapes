#include "rectangletests.h"

RectangleTests::RectangleTests()
{
}

void RectangleTests::initTestCase()
{
    BoundingRectangle boundingRectangle(0, 0, 100, 100);
    m_shapeManager = ShapeManager::getInstance();
    m_rectangle = new Rectangle(boundingRectangle);
    bool status = m_shapeManager->TryToAddShape(m_rectangle);
    QVERIFY2(status == true, "Failed to add initial rectangle");
}

void RectangleTests::cleanupTestCase()
{
    delete m_rectangle;
    m_shapeManager->ClearShapes();
}

void RectangleTests::testInnerRectangle()
{
    BoundingRectangle boundingRectangle(10, 10, 30, 30);
    Rectangle* rectangle = new Rectangle(boundingRectangle);
    bool isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "Test Case failed for inner rectangle.");
}

void RectangleTests::testInnerToOuterRectangle()
{
    BoundingRectangle boundingRectangle(10, 10, 110, 110);
    Rectangle* rectangle = new Rectangle(boundingRectangle);
    bool isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "Test Case failed for inner-outer rectangle. Should be detected as a collision.");
}

void RectangleTests::testOuterRectangle()
{
    BoundingRectangle boundingRectangle(101, 101, 20, 20);
    Rectangle* rectangle = new Rectangle(boundingRectangle);
    bool isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == false, "Test Case failed for outer rectangle. Should not be detected as a collision.");
}

void RectangleTests::testTouchingRectangle() {
    BoundingRectangle boundingRectangle(100, 100, 1, 1);
    Rectangle* rectangle = new Rectangle(boundingRectangle);
    bool isCollision = m_shapeManager->checkCollision(rectangle);
    delete rectangle;
    QVERIFY2(isCollision == true, "Test Case failed for touching rectangle. Should be detected as a collision.");
}
