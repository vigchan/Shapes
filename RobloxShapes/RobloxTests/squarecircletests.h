#ifndef SQUARECIRCLETESTS_H
#define SQUARECIRCLETESTS_H

#include<QtTest>
#include "../shapemanager.h"
#include "../square.h"
#include "../circle.h"

class SquareCircleTests : public QObject
{
    Q_OBJECT
public:
    SquareCircleTests();
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
    Square* m_square;
    Circle* m_circle;

};

#endif // SQUARECIRCLETESTS_H
