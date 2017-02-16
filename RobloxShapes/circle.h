#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
class Circle : public Shape
{
private:
    double m_radius;
    Point m_center;

protected:
    bool doesCollideWithSquare(Square* square);
    bool doesCollideWithRectangle(Rectangle* rectangle);
    bool doesCollideWithCircle(Circle* circle);
    bool doesCollideWithTriangle(Triangle* triangle);
    bool doesCollideWithLine(Line line);
    void InitShapeData(QString shapeDescription);

public:
    Circle(double radius, Point m_center);
    bool isPointInside(Point point);
    void updateShapeForMove(Point sourcePoint, Point destinationPoint);
    bool doesCollideWithShapeLines(Shape* shape);
    ~Circle();
};

#endif // CIRCLE_H
