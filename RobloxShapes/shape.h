#ifndef SHAPE_H
#define SHAPE_H

#include "shapetype.h"
#include "boundingrectangle.h"
#include "point.h"

#include <QString>
#include <QVector>


class Rectangle;
class Square;
class Circle;
class Triangle;
class Line;
class Point;
class BoundingRectangle;

class Shape {
protected:
    QString m_shapeDescription;
    ShapeType m_shapeType;
    BoundingRectangle m_boundingRect;
    Point m_leftPoint;
    double m_distance;
    double m_area;
    QVector<Line> m_lines;

    virtual bool doesCollideWithRectangle(Rectangle* rectangle) = 0;
    virtual bool doesCollideWithSquare(Square* square) = 0;
    virtual bool doesCollideWithTriangle(Triangle* triangle) = 0;
    virtual bool doesCollideWithCircle(Circle*  circle) = 0;
    virtual void InitShapeData(QString shapeDescription) = 0;

    bool isPointInsideForLines(Point point);

 public:
    bool doesCollideWith(Shape* shape, bool ignoreContains);
    bool checkCollisionForLines(Shape* shape);
    bool operator <(Shape* shape);
    virtual QVector<Line> getLines();
    virtual bool isPointInside(Point point) = 0;
    virtual void updateShapeForMove(Point sourcePoint, Point destinationPoint) = 0;
    double getArea();
    ShapeType getShapeType();
    bool Equals(Shape* shape);
    Point getLeftPoint();
    BoundingRectangle getBoundingRectangle();
    virtual ~Shape();
};

#endif // SHAPE_H
