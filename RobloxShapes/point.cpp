#include "point.h"

Point::Point(double x, double y)
{
    m_x = x;
    m_y = y;
}

Point::Point() {

}

double Point::getX() const {
    return m_x;
}

double Point::getY() const {
    return m_y;
}

bool Point::operator == (Point p) {
    return m_x == p.getX() && m_y == p.getY();
}

bool Point::operator<(const Point &p)  const{
    return m_x < p.getX() || (m_x == p.getX() && m_y < p.getY());
}
