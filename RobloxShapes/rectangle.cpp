#include "rectangle.h"
#include "constants.h"
#include "boundingrectangle.h"
#include "line.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

Rectangle::Rectangle(const BoundingRectangle& position)
{
    m_position = position;
    m_shapeType = ShapeType::rectangle;
    InitShapeData(Constants::RECTANGLE_DESC);
}

Rectangle::~Rectangle() {

}

bool Rectangle::doesCollideWithTriangle(Triangle *triangle) {
    return checkCollisionForLines(triangle);
}

bool Rectangle::doesCollideWithCircle(Circle *circle) {
    return circle->doesCollideWithShapeLines(this);
}

bool Rectangle::doesCollideWithSquare(Square *square) {
    return checkCollisionForLines(square);
}

bool Rectangle::doesCollideWithRectangle(Rectangle* rectangle) {
    return checkCollisionForLines(rectangle);
}

bool Rectangle::isPointInside(Point point) {
    bool status = false;
    for(int i=0; i < m_points.size(); i++) {
        if(m_points[i] == point) {
            status = true;
            break;
        }
    }
    return status || isPointInsideForLines(point);
}

void Rectangle::InitShapeData(QString shapeDescription) {
    m_shapeDescription = shapeDescription;
    m_leftPoint = Point(m_position.getLeft(), m_position.getTop());
    m_distance = m_leftPoint.getX() * m_leftPoint.getX() + m_leftPoint.getY() * m_leftPoint.getY();
    m_area = m_position.getArea();
    m_boundingRect = m_position;
    Point leftTop(m_position.getLeft(), m_position.getTop());
    Point rightTop(m_position.getLeft() + m_position.getWidth(), m_position.getTop());
    Point leftBottom(m_position.getLeft(), m_position.getTop() + m_position.getHeight() );
    Point rightBottom(m_position.getLeft() + m_position.getWidth(), m_position.getTop() + m_position.getHeight());

    m_points.push_back(leftTop);
    m_points.push_back(rightTop);
    m_points.push_back(leftBottom);
    m_points.push_back(rightBottom);

    m_lines.push_back(Line(leftTop, rightTop));
    m_lines.push_back(Line(leftTop, leftBottom));
    m_lines.push_back(Line(rightTop, rightBottom));
    m_lines.push_back(Line(leftBottom, rightBottom));
}

void Rectangle::updateShapeForMove(Point source, Point destination) {
    double xDisplacement = destination.getX() - source.getX();
    double yDisplacement = destination.getY() - source.getY();
    m_position = BoundingRectangle(m_position.getLeft() + xDisplacement, m_position.getTop() + yDisplacement,
        m_position.getWidth(), m_position.getHeight());
    m_lines.clear();
    m_points.clear();
    InitShapeData(Constants::RECTANGLE_DESC);
}

bool Rectangle::isTouching(BoundingRectangle rectangle) {
    Rectangle* rectanglePtr = new Rectangle(rectangle);
    QVector<Line> lines = rectanglePtr->getLines();
    delete rectanglePtr;
    bool isTouching = true;
    for(int i=0; i < m_lines.size(); i++) {
        for(int j=0; j < lines.size(); j++ ) {
            if(m_lines[i].doesIntersect(lines[j]) && !Line::IsCollinearWithLine(m_lines[i], lines[j].getStartPoint())
                && !Line::IsCollinearWithLine(m_lines[i], lines[j].getEndPoint())) {
                isTouching = false;
                break;
            }
        }
    }
    return isTouching;
}

bool Rectangle::isTouching(Point p) {
    bool isTouching = false;
    for(int i=0; i < m_lines.size(); i++) {
        if(Line::IsCollinearWithLine(m_lines[i], p)) {
            isTouching = true;
        }
    }
    return isTouching;
}

QVector<Line> Rectangle::getLines() {
    return m_lines;
}
