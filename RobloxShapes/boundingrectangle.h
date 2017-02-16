#ifndef BOUNDINGRECTANGLE_H
#define BOUNDINGRECTANGLE_H

class BoundingRectangle
{
private:
    double m_left;
    double m_top;
    double m_width;
    double m_height;
    double m_area;

public:
    BoundingRectangle(double left, double top, double width, double height);
    BoundingRectangle();
    double getLeft();
    double getTop();
    double getWidth();
    double getHeight();
    double getArea();
    bool contains(BoundingRectangle boundingRectangle);
    bool Equals(BoundingRectangle boundingRectangle);
};

#endif // BOUNDINGRECTANGLE_H
