#ifndef TRIANGLETESTS_H
#define TRIANGLETESTS_H

#include <QtTest>
#include "../shapemanager.h"
#include "../triangle.h"
class TriangleTests : public QObject {
    Q_OBJECT

public:
    TriangleTests();
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testInnerTriangle();
    void testInnerToOuterTriangle();
    void testOuterTriangle();
    void testTouchingTriangle();
private:
    ShapeManager* m_shapeManager;
    Triangle* m_triangle;
};
#endif // TRIANGLETESTS_H
