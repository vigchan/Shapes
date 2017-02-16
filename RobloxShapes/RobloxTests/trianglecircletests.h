#ifndef TRIANGLECIRCLETESTS_H
#define TRIANGLECIRCLETESTS_H

#include <QtTest>
#include "../shapemanager.h"
#include "../triangle.h"
#include "../circle.h"

class TriangleCircleTests : public QObject
{
    Q_OBJECT
public:
    TriangleCircleTests();
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();

    // When either of the shapes is inside the other
    void insideTests();
    // When either shapes is inside the other and intersects
    void insideIntersectionTests();
    // When both shapes intersect externally.
    void outsideIntersectionTests();
    // When either shapes is touching the other from inside
    void insideTouchTests();
    // When either shapes is touching the other from outside
    void outsideTouchTests();
private:
    ShapeManager* m_shapeManager;
    Triangle* m_triangle;
    Circle* m_circle;
};

#endif // TRIANGLECIRCLETESTS_H
