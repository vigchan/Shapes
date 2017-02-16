#include "boundingrectangle.h"

BoundingRectangle::BoundingRectangle() {

}

BoundingRectangle::BoundingRectangle(double left, double top, double width, double height)
{
    m_left = left;
    m_top = top;
    m_width = width;
    m_height = height;
    m_area = width * height;
}

double BoundingRectangle::getLeft() {
    return m_left;
}

double BoundingRectangle::getTop() {
    return m_top;
}

double BoundingRectangle::getWidth() {
    return m_width;
}

double BoundingRectangle::getHeight() {
    return m_height;
}

double BoundingRectangle::getArea() {
    return m_area;
}

bool BoundingRectangle::contains(BoundingRectangle rectangle) {
    double rectRight = rectangle.getLeft() + rectangle.getWidth();
    double rectBottom = rectangle.getTop() + rectangle.getHeight();
    double right = m_left + m_width;
    double bottom = m_top + m_height;

    if(rectangle.getLeft() > m_left && rectangle.getTop() > m_top &&
        rectRight < right && rectBottom < bottom) {
        return true;
    }
    return false;
}

bool BoundingRectangle::Equals(BoundingRectangle boundingRectangle) {
    return m_left == boundingRectangle.getLeft() && m_top == boundingRectangle.getTop() &&
        m_width == boundingRectangle.getWidth() && m_height == boundingRectangle.getHeight();
}
