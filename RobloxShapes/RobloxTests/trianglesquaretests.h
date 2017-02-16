#ifndef TRIANGLESQUARETESTS_H
#define TRIANGLESQUARETESTS_H

#include <QtTest>
#include "../triangle.h"
#include "../square.h"
#include "../shapemanager.h"

class TriangleSquareTests : public QObject
{
    Q_OBJECT
public:
    TriangleSquareTests();
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
    Square* m_square;
};

#endif // TRIANGLESQUARETESTS_H
