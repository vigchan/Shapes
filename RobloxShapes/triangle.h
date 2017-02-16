#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QVector>
#include "shape.h"

class Line;

class Triangle : public Shape
{
private:
    QVector<Point> m_vertices;
    double calculateArea();
    BoundingRectangle calculateBoundingRect();
protected:

    bool doesCollideWithSquare(Square* square);
    bool doesCollideWithRectangle(Rectangle* rectangle);
    bool doesCollideWithCircle(Circle* circle);
    bool doesCollideWithTriangle(Triangle* triangle);
    void InitShapeData(QString shapeDescription);

public:
    Triangle(Point leftPos, Point middlePos, Point rightPos);
    ~Triangle();
    bool isPointInside(Point point);
    void updateShapeForMove(Point source, Point destination);
    bool doesCollideWith(Shape* shape);
    QVector<Line> getLines();
};

#endif // TRIANGLE_H
