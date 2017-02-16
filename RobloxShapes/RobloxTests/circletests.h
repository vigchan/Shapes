#ifndef CIRCLETESTS_H
#define CIRCLETESTS_H

#include<QtTest>
#include "../boundingrectangle.h"
#include "../shapemanager.h"
#include "../circle.h"

class CircleTests: public QObject
{
    Q_OBJECT
public:
    CircleTests();
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testInnerCircle();
    void testInnerToOuterCircle();
    void testOuterToInnerCircle();
    void testOuterCircle();
    void testTouchingCircleOuter();
    void testTouchingCircleInner();
private:
    ShapeManager* m_shapeManager;
    Circle* m_circle;
};

#endif // CIRCLETESTS_H
