#ifndef LINE_H
#define LINE_H

#include "point.h"
#include "orientationtype.h"

class Circle;

class Line
{
private:
    Point m_start;
    Point m_end;
    static OrientationType getOrientation(Point p1, Point p2, Point p3);
public:
    Line(Point start, Point end);
    Line();
    bool doesIntersect(Line line);
    double getSlope();
    Point getStartPoint();
    Point getEndPoint();

    static bool IsCollinearWithLine(Line line, Point point);

};

#endif // LINE_H
