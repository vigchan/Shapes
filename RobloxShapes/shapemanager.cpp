#include "shapemanager.h"
#include "constants.h"
#include "rectangle.h"
#include <QtDebug>

ShapeManager* ShapeManager:: m_instance = NULL;

ShapeManager* ShapeManager::getInstance() {
    if(m_instance == NULL) {
        m_instance = new ShapeManager();
    }
    return m_instance;
}

ShapeManager::ShapeManager()
{
    m_boundingRectangle = new Rectangle(BoundingRectangle(0, 0, Constants::MaxCanvasWidth,
                                                          Constants::MaxCanvasHeight));
}

ShapeManager::~ShapeManager() {
    delete m_instance;
    m_instance = NULL;
}

bool ShapeManager::checkCollision(Shape *shape) {
   QSet<Shape*>::iterator it = m_shapes.begin();
   bool status = false;
   while( it != m_shapes.end()) {
       if(!((*it)->Equals(shape)) && (*it)->doesCollideWith(shape, false)) {
           status = true;
           break;
       }
       it++;
   }
   return status;
}

Shape* ShapeManager::getShapeForPoint(Point point) {
    QSet<Shape*>::iterator it = m_shapes.begin();
    while( it != m_shapes.end()) {
        if((*it)->isPointInside(point)) {
            break;
        }
        it++;
    }
    if(it != m_shapes.end()) {
        return *it;
    }
    return NULL;
}

bool ShapeManager::tryMove(Point sourcePoint, Point destinationPoint) {

    if(!m_boundingRectangle->isPointInside(destinationPoint)) {
        qDebug() << "Point ("<<destinationPoint.getX()<<","<<destinationPoint.getY()<<") beyond canvas";
        return false;
    }

    Shape* shapeToMove = getShapeForPoint(sourcePoint);
    if(shapeToMove == NULL) {
        qDebug() <<" Unable to find a shape at Point ("<<sourcePoint.getX()<<","<<sourcePoint.getY()<<")";
        return false;
    }

    Shape* shapeAtDestination = getShapeForPoint(destinationPoint);
    if(shapeAtDestination != NULL && shapeAtDestination != shapeToMove) {
        qDebug() <<" Found shape at destination Point ("<<destinationPoint.getX()<<","<<destinationPoint.getY()<<")";
        return false;
    }

    shapeToMove->updateShapeForMove(sourcePoint, destinationPoint);

    // The shape collides with the boundaries of the coordinate system.
    if(m_boundingRectangle->doesCollideWith(shapeToMove,true) &&
            !m_boundingRectangle->isTouching(shapeToMove->getBoundingRectangle())) {
        shapeToMove->updateShapeForMove(destinationPoint, sourcePoint);
        return false;
    }

    // The shape collides with another shape in coordinare system
    if(checkCollision(shapeToMove)) {
        shapeToMove->updateShapeForMove(destinationPoint, sourcePoint);
        return false;
    }
    return true;
}

bool ShapeManager::TryToAddShape(Shape* shape) {

    if(m_boundingRectangle->doesCollideWith(shape,true) &&
            !m_boundingRectangle->isTouching(shape->getBoundingRectangle())) {
        return false;
    }
    bool status = checkCollision(shape);
    if(!status) {
        m_shapes.insert(shape);
    }
    return !status;
}

double ShapeManager::getAreaRemaining() {
    QSet<Shape*>::iterator it = m_shapes.begin();
    double shapesArea = 0;
    while( it != m_shapes.end()) {
        shapesArea += (*it)->getArea();
        it++;
    }
    return (m_boundingRectangle->getArea() - shapesArea);
}

double ShapeManager::getCanvasArea() {
    return m_boundingRectangle->getArea();
}

void ShapeManager::removeShape(Shape* shape) {
    m_shapes.remove(shape);
}

void ShapeManager::ClearShapes() {
    m_shapes.clear();
}

void ShapeManager::setBoundingRectangle(BoundingRectangle rectangle) {
    if(m_boundingRectangle != NULL) {
        delete m_boundingRectangle;
    }
    m_boundingRectangle = new Rectangle(rectangle);
}
