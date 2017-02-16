#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include <QSet>

#include "shape.h"
class Rectangle;

class ShapeManager
{
private:
    ShapeManager();
    ~ShapeManager();
    static ShapeManager* m_instance;
    QSet<Shape*> m_shapes;
    Rectangle* m_boundingRectangle;
public:
    static ShapeManager* getInstance();
    bool TryToAddShape(Shape* shape);
    void removeShape(Shape* shape);
    bool checkCollision(Shape* shape);
    Shape* getShapeForPoint(Point point);
    bool tryMove(Point sourcePoint, Point destinationPoint);
    double getAreaRemaining();
    double getCanvasArea();
    void ClearShapes();
    void setBoundingRectangle(BoundingRectangle rectangle);
};

#endif // SHAPEMANAGER_H
