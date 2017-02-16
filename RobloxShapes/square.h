#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square: public Shape
{
private:
    double m_side;
    double m_left;
    double m_top;
    QVector<Point> m_points;
protected:
    bool doesCollideWithSquare(Square* square);
    bool doesCollideWithRectangle(Rectangle* rectangle);
    bool doesCollideWithCircle(Circle* circle);
    bool doesCollideWithTriangle(Triangle* triangle);
    void InitShapeData(QString shapeDescription);


public:
    Square(Point leftPos, double m_side);
    bool isPointInside(Point point);
    void updateShapeForMove(Point source, Point destination);
    QVector<Line> getLines();
};

#endif // SQUARE_H
