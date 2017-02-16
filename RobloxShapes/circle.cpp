#include "circle.h"
#include "shape.h"
#include "constants.h"
#include "line.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"
#include <QDebug>
#include <QtMath>

Circle::Circle(double radius, Point center)
{
    m_radius = radius;
    m_center = center;
    InitShapeData(Constants::CIRCLE_DESC);
    m_shapeType = ShapeType::circle;
}
Circle::~Circle() {

}

bool Circle::doesCollideWithTriangle(Triangle *triangle) {
    return doesCollideWithShapeLines(triangle);
}

bool Circle::doesCollideWithCircle(Circle *circle) {
    double xdist = m_center.getX() - circle->m_center.getX();
    double ydist = m_center.getY() - circle->m_center.getY();
    double dist  = xdist * xdist + ydist * ydist;
    double radiusDistanceSquared = (circle->m_radius + m_radius);
    radiusDistanceSquared = radiusDistanceSquared * radiusDistanceSquared;

    // Centers coincide
    if(m_center.getX() == circle->m_center.getX() && m_center.getY() == circle->m_center.getY()
            && m_radius == circle->m_radius) {
        return true;
    }

    // Circle externally don't touch each other
    if(dist > radiusDistanceSquared) {
        return false;
    }

    // Circles touching each other externally
    if( dist  == radiusDistanceSquared ) {
        return true;
    }

    // One circle is inside the other
    unsigned int minRadius = qMin(m_radius, circle->m_radius);
    unsigned int maxRadius = qMax(m_radius, circle->m_radius);
    if( (2* minRadius) < maxRadius) {
        radiusDistanceSquared = (maxRadius - minRadius);
        radiusDistanceSquared = radiusDistanceSquared * radiusDistanceSquared;
        // Smaller circle touching the bigger circle
        if( radiusDistanceSquared == dist) {
            return true;
        }
        return false;
    }

    // Circles intersect externally
    return true;
}

bool Circle::doesCollideWithSquare(Square *square) {
    return doesCollideWithShapeLines(square);
}

bool Circle::doesCollideWithRectangle(Rectangle* rectangle) {
    return doesCollideWithShapeLines(rectangle);
}

bool Circle::doesCollideWithShapeLines(Shape *shapeWithLines) {
    QVector<Line> lines = shapeWithLines->getLines();
    bool doesCollide = false;
    for(int i =0; i < lines.size(); i++) {
        doesCollide = doesCollideWithLine(lines[i]);
        if(doesCollide) {
            break;
        }
    }
    return doesCollide;
}

bool Circle::doesCollideWithLine(Line line) {
    Point start = line.getStartPoint();
    Point end = line.getEndPoint();

    double lineDiffX = start.getX() - end.getX();
    double lineDiffY = start.getY() - end.getY();
    double a = lineDiffX * lineDiffX + lineDiffY * lineDiffY;

    double centerDiffX = end.getX() - m_center.getX();
    double centerDiffY = end.getY() - m_center.getY();
    double b = centerDiffX * lineDiffX + centerDiffY * lineDiffY;
    b = b*2;

    double c = centerDiffX * centerDiffX + centerDiffY * centerDiffY - m_radius*m_radius;
    if((b*b - (4*a*c)) < 0) {
        return false;
    }

    double t1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
    double t2 = (-b - sqrt(b*b - 4*a*c))/(2*a);

    if(t1 >= 0 && t1 <= 1) {
        return true;
    }

    if(t2 >= 0 && t2 <= 1) {
        return true;
    }
    return false;
}

bool Circle::isPointInside(Point point) {
    double diffX = m_center.getX() - point.getX();
    double diffY = m_center.getY() - point.getY();

    if(diffX*diffX + diffY*diffY <= (m_radius*m_radius))
        return true;
    return false;
}

void Circle::InitShapeData(QString shapeDescription) {
   m_shapeDescription = shapeDescription;
   m_leftPoint = Point(m_center.getX() - m_radius, m_center.getY());
   m_distance = m_leftPoint.getX() * m_leftPoint.getX() + m_leftPoint.getY() * m_leftPoint.getY();
   m_boundingRect = BoundingRectangle(m_center.getX() - m_radius, m_center.getY() - m_radius, 2*m_radius, 2*m_radius);
   m_area = (22/7) * m_radius * m_radius;
}

void Circle::updateShapeForMove(Point source, Point destination) {
    double xDisplacement = destination.getX() - source.getX();
    double yDisplacement = destination.getY() - source.getY();
    m_center = Point(m_center.getX() + xDisplacement, m_center.getY() + yDisplacement);
    InitShapeData(Constants::CIRCLE_DESC);
}
