#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <GL/gl.h>

#include "Color.h"


// Abstract Data Type
class Shape{
float x;
float y;
float r = 1.0f;  // Default to red
    float g = 0.0f;
    float b = 0.0f;


public:
    bool selected;
    virtual void draw() = 0;
    virtual bool contains(float mx, float my) = 0;
    virtual void setColor(float r, float g, float b) = 0;
    virtual void resize(float factor) = 0;
    virtual float getSize() const = 0;

    void select() {selected = true; }
    void deselect() {selected = false; }
    bool isSelected() {return selected;}
    
    float getX() { return x; }
    float getY() { return y; }
    float getR() { return r; }
    float getG() { return g; }
    float getB() { return b; }

    virtual void setPosition(float x, float y) = 0;

    virtual ~Shape(){}
};

#endif