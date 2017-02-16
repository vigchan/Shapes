#ifndef SHAPEMANAGERTESTS_H
#define SHAPEMANAGERTESTS_H

#include<QtTest>
#include "../shapemanager.h"
#include "../square.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "../circle.h"
#include "../boundingrectangle.h"

class ShapeManagerTests :public QObject
{
    Q_OBJECT
public:
    ShapeManagerTests();
private Q_SLOTS:
    void initTestCase();
    // Cleans up the shapes and does suitable validations while doing so.
    void cleanupTestCase();
    // Tests for validating oversized shapes
    void validateOversizedShapes();
    // Tests for fetching shape corresponding to a point inside it.
    void validateGetShapeFromPoint();
    // Tests for moving shape
    void validateShapeMove();
private:
    ShapeManager* m_shapeManager;
    QVector<Shape*> m_shapes;
    double m_width;
    double m_height;
    double m_totalShapesArea;
    void validateValuesForShapeMove(Point newPoint, Point oldPoint,
        BoundingRectangle newRect, BoundingRectangle oldRect, double xDisplacement, double yDisplacement);
};

#endif // SHAPEMANAGERTESTS_H
