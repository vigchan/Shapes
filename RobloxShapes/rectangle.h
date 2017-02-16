#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle: public Shape
{
private:
    BoundingRectangle m_position;
    QVector<Point> m_points;

protected:
    bool doesCollideWithSquare(Square* square);
    bool doesCollideWithCircle(Circle* circle);
    bool doesCollideWithTriangle(Triangle* triangle);
    bool doesCollideWithRectangle(Rectangle* rectangle);
    void InitShapeData(QString shapeDescription);

public:
    Rectangle(const BoundingRectangle& position);
    ~Rectangle();
    bool isPointInside(Point point);
    void updateShapeForMove(Point sourcePoint, Point destinationPoint);
    QVector<Line> getLines();
    bool isTouching(BoundingRectangle rectangle);
    bool isTouching(Point p);
};

#endif // RECTANGLE_H
