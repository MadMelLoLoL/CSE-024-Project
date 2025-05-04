#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Point*> points;
    std::vector<Shape*> shapes;
    int selectedShape;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addRectangle(float x, float y,float width, float height, float r, float g, float b);

    void addCircle(float x, float y, float radius, float r, float g, float b);

    void addPolygon(float x, float y, float radius, int n, float rot, float r, float g, float b);

    void clear();

    void render();

    Shape* getSelectedShape(float mx, float my);
};

#endif