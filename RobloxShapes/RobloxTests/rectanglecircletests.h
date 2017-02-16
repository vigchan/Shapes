#ifndef RECTANGLECIRCLETESTS_H
#define RECTANGLECIRCLETESTS_H

#include<QtTest>

#include "../shapemanager.h"
#include "../circle.h"
#include "../rectangle.h"

class RectangleCircleTests: public QObject
{
    Q_OBJECT
public:
    RectangleCircleTests();
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
    Rectangle* m_rectangle;
    Circle* m_circle;
};

#endif // RECTANGLECIRCLETESTS_H
