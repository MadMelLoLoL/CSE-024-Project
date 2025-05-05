#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"
#include "Scribble.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Point*> points;
    std::vector<Shape*> shapes;
    std::vector<Scribble*> scribbles;
    Shape* selectedShape = nullptr;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addRectangle(float x, float y,float width, float height, float r, float g, float b);

    void addCircle(float x, float y, float radius, float r, float g, float b);

    void addPolygon(float x, float y, float radius, int n, float rot, float r, float g, float b);

    //scribble management
    void startNewScribble(float r, float g, float b, int size);
    void addToCurrentScribble(float x, float y);
    void finalizeCurrentScribble();

    void render();

    //front and back buttons
    void moveShapeToFront(Shape* shape);
    void moveShapeToBack(Shape* shape);
    int findShapeIndex(Shape* shape);//finds shape placement

//eraser tool 
    void eraseShapeAt(float x, float y);
    void clear();

    void clearSelection();

    Shape* getSelectedShape(float mx, float my);
};

#endif