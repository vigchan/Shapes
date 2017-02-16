#include "triangle.h"
#include "constants.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "triangle.h"

#include<QtMath>
#include<QDebug>

Triangle::Triangle(Point leftPos, Point middlePos, Point rightPos)
{
    m_vertices.append(leftPos);
    m_vertices.append(middlePos);
    m_vertices.append(rightPos);
    std::sort(m_vertices.begin(), m_vertices.end());
    InitShapeData(Constants::TRIANGLE_DESC);
    m_shapeType = ShapeType::triangle;
}

Triangle::~Triangle() {

}

bool Triangle::doesCollideWithTriangle(Triangle *triangle) {
    return checkCollisionForLines(triangle);
}

bool Triangle::doesCollideWithCircle(Circle *circle) {
    return circle->doesCollideWithShapeLines(this);
}

bool Triangle::doesCollideWithSquare(Square *square) {
    return checkCollisionForLines(square);
}

bool Triangle::doesCollideWithRectangle(Rectangle* rectangle) {
    return checkCollisionForLines(rectangle);
}

QVector<Line> Triangle::getLines() {
    return m_lines;
}

void Triangle::InitShapeData(QString shapeDescription) {
    m_shapeDescription = shapeDescription;
    m_leftPoint = m_vertices[0];
    m_distance = m_leftPoint.getX() * m_leftPoint.getX() + m_leftPoint.getY() * m_leftPoint.getY();
    m_lines.push_back(Line(m_vertices[0], m_vertices[1]));
    m_lines.push_back(Line(m_vertices[1], m_vertices[2]));
    m_lines.push_back(Line(m_vertices[0], m_vertices[2]));
    m_area = calculateArea();
    m_boundingRect = calculateBoundingRect();

}

void Triangle::updateShapeForMove(Point source, Point destination) {
    double xDisplacement = destination.getX() - source.getX();
    double yDisplacement = destination.getY() - source.getY();
    for(int i=0; i < m_vertices.size(); i++) {
        m_vertices[i] = Point(m_vertices[i].getX() + xDisplacement, m_vertices[i].getY() + yDisplacement);
    }
    std::sort(m_vertices.begin(), m_vertices.end());
    m_lines.clear();
    InitShapeData(Constants::TRIANGLE_DESC);
}

bool Triangle::isPointInside(Point point) {
    bool status = false;
    for(int i=0; i < m_vertices.size(); i++) {
        if(m_vertices[i] == point) {
            status = true;
            break;
        }
    }
    return status || isPointInsideForLines(point);
}

BoundingRectangle Triangle::calculateBoundingRect() {
    Point leftTop(qMin(m_vertices[0].getX(), qMin(m_vertices[1].getX(), m_vertices[2].getX())),
        qMin(m_vertices[0].getY(), qMin(m_vertices[1].getY(), m_vertices[2].getY()) ));
    Point rightBottom(qMax(m_vertices[0].getX(), qMax(m_vertices[1].getX(), m_vertices[2].getX())),
            qMax(m_vertices[0].getY(), qMax(m_vertices[1].getY(), m_vertices[2].getY()) ));
    return BoundingRectangle(leftTop.getX(), leftTop.getY(), rightBottom.getX() - leftTop.getX(),
                             rightBottom.getY() - leftTop.getY());

}

double Triangle::calculateArea() {
    QVector<double> sides;
    double sum = 0;
    for(int i =0; i < m_lines.size(); i++) {
        double ax = m_lines[i].getEndPoint().getX() - m_lines[i].getStartPoint().getX();
        double ay = m_lines[i].getEndPoint().getY() - m_lines[i].getEndPoint().getY();
        sides.push_back(sqrt(ax*ax + ay* ay));
        sum += sides[i];
    }
    sum = sum/2;
    return sqrt(sum* (sum-sides[0]) * (sum-sides[1]) * (sum-sides[2]));
}
