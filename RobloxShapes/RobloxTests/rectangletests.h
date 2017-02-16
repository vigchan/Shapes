#ifndef RECTANGLETESTS_H
#define RECTANGLETESTS_H
#include <QString>
#include <QtTest>

#include "../boundingrectangle.h"
#include "../shapemanager.h"
#include "../rectangle.h"

class RectangleTests : public QObject
{
    Q_OBJECT

public:
    RectangleTests();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testInnerRectangle();
    void testInnerToOuterRectangle();
    void testOuterRectangle();
    void testTouchingRectangle();
private:
    ShapeManager* m_shapeManager;
    Rectangle* m_rectangle;
};

#endif // RECTANGLETESTS_H
