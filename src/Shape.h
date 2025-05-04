#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <GL/gl.h>


// Abstract Data Type
class Shape{
protected:
float x;
float y;
bool selected;
float r;
float g;
float b;


public:
    virtual void draw() = 0;
    virtual bool contains(float mx, float my) = 0;
    virtual void setColor(float r, float g, float b) = 0;

    void select() {selected = true; }
    void deselect() {selected = false; }
    bool isSelected() {return selected;}
    
    float getX() { return x; }
    float getY() { return y; }
    float getR() { return r; }
    float getG() { return g; }
    float getB() { return b; }

    void setX(float x){ this->x = x; }
    void setY(float y){ this->y = y; }
    

    virtual ~Shape(){}
};

#endif