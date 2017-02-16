#ifndef RECTANGLESQUARETESTS_H
#define RECTANGLESQUARETESTS_H

#include<QtTest>
#include "../shapemanager.h"
#include "../rectangle.h"
#include "../square.h"

class RectangleSquareTests : public QObject
{
    Q_OBJECT
public:
    RectangleSquareTests();
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
    ShapeManager *m_shapeManager;
    Rectangle* m_rectangle;
    Square* m_square;
};

#endif // RECTANGLESQUARETESTS_H
