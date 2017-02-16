#include "line.h"
#include "orientationtype.h"
#include "circle.h"
#include <QtMath>
#include <QtDebug>

Line::Line(Point start, Point end)
{
    m_start = start;
    m_end = end;
}

Line::Line() {

}

Point Line::getStartPoint() {
    return m_start;
}

Point Line::getEndPoint() {
    return m_end;
}

double Line::getSlope() {
    return (m_end.getY() - m_start.getY()) / (m_end.getY() - m_start.getX());
}

OrientationType Line::getOrientation(Point p1, Point p2, Point p3) {
    int value = ((p2.getY() - p1.getY()) * (p3.getX() - p2.getX())) -
      ((p2.getX() - p1.getX()) * (p3.getY() - p2.getY()));
    if(value == 0) {
        return OrientationType::collinear;
    }
    if(value < 0) {
        return OrientationType::counterclockwise;
    }
    return OrientationType::clockwise;
}

bool Line::IsCollinearWithLine(Line line,Point p) {
    if(p.getX() <= qMax(line.m_start.getX(), line.m_end.getX()) &&
        p.getX() >= qMin(line.m_start.getX(), line.m_end.getX()) &&
        p.getY() <= qMax(line.m_start.getY(), line.m_end.getY()) &&
        p.getY() >= qMin(line.m_start.getY(), line.m_end.getY()))
        return true;

    return false;
}


bool Line::doesIntersect(Line line) {
    OrientationType o1 = getOrientation(m_start, m_end, line.m_start);
    OrientationType o2 = getOrientation(m_start, m_end, line.m_end);
    OrientationType o3 = getOrientation(line.m_start, line.m_end, m_start);
    OrientationType o4 = getOrientation(line.m_start, line.m_end, m_end);

    if(o1 != o2 && o3 != o4) {
        return true;
    }
    if(o1 == OrientationType::collinear && Line::IsCollinearWithLine(*this, line.m_start)) {
        return true;
    }
    if(o2 == OrientationType::collinear && Line::IsCollinearWithLine(*this, line.m_end)) {
        return true;
    }
    if(o3 == OrientationType::collinear && Line::IsCollinearWithLine(line, m_start)) {
        return true;
    }
    if(o4 == OrientationType::collinear && Line::IsCollinearWithLine(line, m_end)) {
        return true;
    }
    return false;
}
