#ifndef TRIANGLERECTANGLETESTS_H
#define TRIANGLERECTANGLETESTS_H

#include <QtTest>
#include "../rectangle.h"
#include "../triangle.h"
#include "../shapemanager.h"

class TriangleRectangleTests : public QObject
{
    Q_OBJECT
public:
    TriangleRectangleTests();
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
public:
    ShapeManager* m_shapeManager;
    Triangle* m_triangle;
    Rectangle* m_rectangle;
};

#endif // TRIANGLERECTANGLETESTS_H
