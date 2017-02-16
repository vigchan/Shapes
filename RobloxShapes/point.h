#ifndef POINT_H
#define POINT_H


class Point
{
private:
    double m_x;
    double m_y;
public:
    Point(double x, double y);
    Point();
    double getX() const;
    double getY() const;
    bool operator==(Point p);
    bool operator<(const Point& p) const;
};

#endif // POINT_H
