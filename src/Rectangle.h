#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
    float x;
    float y;
    float width;
    float height;
    float r;
    float g;
    float b;
protected:
    bool selected;

public:
    Rectangle();
    Rectangle(float x, float y, float width, float height, float r, float g, float b);
    void draw();
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);
    void setPosition(float x, float y);
    void resize(float factor);
    float getSize() const;
};

#endif