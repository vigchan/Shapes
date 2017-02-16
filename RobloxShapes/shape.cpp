#include "shape.h"
#include "shapetype.h"
#include "circle.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "line.h"
#include <QDebug>

Shape::~Shape() {
    m_lines.clear();
}

bool Shape::doesCollideWith(Shape *shape, bool ignoreContains) {

    // Check of this shape is inside an existing one
    if(!ignoreContains && (m_boundingRect.contains(shape->getBoundingRectangle())
        || shape->getBoundingRectangle().contains(m_boundingRect))) {
        return true;
    }

    bool doesCollide = false;
    if(shape->m_shapeType == ShapeType::rectangle) {
        Rectangle* rectangle = dynamic_cast<Rectangle*>(shape);
        doesCollide = doesCollideWithRectangle(rectangle);
    }
    else if(shape->m_shapeType == ShapeType::square) {
        Square* square = dynamic_cast<Square*>(shape);
        doesCollide = doesCollideWithSquare(square);
    }
    else if(shape->m_shapeType == ShapeType::circle) {
        Circle* circle = dynamic_cast<Circle*>(shape);
        doesCollide = doesCollideWithCircle(circle);
    }
    else if(shape->m_shapeType == ShapeType::triangle) {
        Triangle* triangle = dynamic_cast<Triangle*>(shape);
        doesCollide = doesCollideWithTriangle(triangle);
    }
    return doesCollide;
}

bool Shape::operator <(Shape* shape) {
    Point leftPoint = getLeftPoint();
    Point targetLeftPoint = shape->getLeftPoint();

    unsigned long long givenDistance = leftPoint.getX()* leftPoint.getX() +
            leftPoint.getY() * leftPoint.getY();
    unsigned long long targetDistance = targetLeftPoint.getX() * targetLeftPoint.getX() +
            targetLeftPoint.getY() * targetLeftPoint.getY();

    return givenDistance < targetDistance;
}

QVector<Line> Shape::getLines() {
    return QVector<Line>();
}

Point Shape::getLeftPoint() {
    return m_leftPoint;
}

bool Shape::checkCollisionForLines(Shape *shape) {
    QVector<Line> currShapeLines = getLines();
    QVector<Line> targetShapeLines = shape->getLines();

    bool status = false;
    for(int i =0; i < currShapeLines.size() && !status; i++) {
        for(int j=0; j < targetShapeLines.size(); j++) {
            Line line = currShapeLines.at(i);
            status = line.doesIntersect(targetShapeLines.at(j));
            if(status) {
                break;
            }
        }
    }
    return status;
}

bool Shape::isPointInsideForLines(Point point) {

    // Check if the point is collinear with either of the lines
    for(int i=0; i < m_lines.size(); i++) {
        if(Line::IsCollinearWithLine(m_lines[i], point)) {
            return true;
        }
    }

    Point outPoint;
    if(m_leftPoint.getX() -1 < 0) {
        outPoint = Point(m_boundingRect.getLeft()+m_boundingRect.getWidth()+1, m_boundingRect.getTop());
    }
    else {
        outPoint = Point(m_leftPoint.getX()-1, m_leftPoint.getY());
    }

    Line line(point, outPoint);
    int intersectionPoints = 0;
    for(int i=0; i < m_lines.size(); i++) {
        if(line.doesIntersect(m_lines[i])) {
            intersectionPoints++;
        }
    }
    if(intersectionPoints == 1) {
        return true;
    }
    return false;
}

double Shape::getArea() {
    return m_area;
}

bool Shape::Equals(Shape *shape) {
    return m_leftPoint == shape->getLeftPoint() && m_shapeType == shape->getShapeType() &&
        m_boundingRect.Equals(shape->getBoundingRectangle());
}

ShapeType Shape::getShapeType() {
    return m_shapeType;
}

BoundingRectangle Shape::getBoundingRectangle() {
    return m_boundingRect;
}
