#ifndef SQUARETESTS_H
#define SQUARETESTS_H
#include <QString>
#include <QtTest>

#include "../shapemanager.h"
#include "../square.h"

class SquareTests : public QObject
{
    Q_OBJECT
public:
    SquareTests();
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testInnerSquare();
    void testInnerToOuterSquare();
    void testOuterSquare();
    void testTouchingSquare();
private:
    ShapeManager* m_shapeManager;
    Square* m_square;
};

#endif // SQUARETESTS_H
