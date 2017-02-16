#include "square.h"
#include "point.h"
#include "constants.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

Square::Square(Point leftPosition, double side)
{
    m_left = leftPosition.getX();
    m_top = leftPosition.getY();
    m_side = side;
    m_shapeType = ShapeType::square;
    InitShapeData(Constants::SQUARE_DESC);
}

bool Square::doesCollideWithTriangle(Triangle *triangle) {
    return checkCollisionForLines(triangle);
}

bool Square::doesCollideWithCircle(Circle *circle) {
    return circle->doesCollideWithShapeLines(this);
}

bool Square::doesCollideWithSquare(Square *square) {
    return checkCollisionForLines(square);
}

bool Square::doesCollideWithRectangle(Rectangle* rectangle) {
    return checkCollisionForLines(rectangle);
}

bool Square::isPointInside(Point point) {
    bool status = false;
    for(int i=0; i < m_points.size(); i++) {
        if(m_points[i] == point) {
            status = true;
            break;
        }
    }
    return status || isPointInsideForLines(point);
}

void Square::InitShapeData(QString shapeDescription) {
   m_shapeDescription = shapeDescription;
   m_leftPoint = Point(m_left, m_top);
   m_distance = m_leftPoint.getX() * m_leftPoint.getX() + m_leftPoint.getY() * m_leftPoint.getY();
   m_boundingRect = BoundingRectangle(m_left, m_top, m_side, m_side);
   m_area = m_side * m_side;
   Point leftTop(m_left, m_top);
   Point rightTop(m_left + m_side, m_top);
   Point leftBottom(m_left, m_top + m_side );
   Point rightBottom(m_left + m_side, m_top + m_side);

   m_points.append(leftTop);
   m_points.append(rightTop);
   m_points.append(leftBottom);
   m_points.append(rightBottom);

   m_lines.push_back(Line(leftTop, rightTop));
   m_lines.push_back(Line(leftTop, leftBottom));
   m_lines.push_back(Line(rightTop, rightBottom));
   m_lines.push_back(Line(leftBottom, rightBottom));
}

void Square::updateShapeForMove(Point source, Point destination) {
    double xDisplacement = destination.getX() - source.getX();
    double yDisplacement = destination.getY() - source.getY();
    m_left = m_left + xDisplacement;
    m_top = m_top + yDisplacement;
    m_lines.clear();
    m_points.clear();
    InitShapeData(Constants::SQUARE_DESC);
}

QVector<Line> Square::getLines(){
    return m_lines;
}
