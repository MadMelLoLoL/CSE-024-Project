#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

class Polygon : public Shape{
    float x;
    float y;
    float radius;
    float rot;
    float r;
    float g;
    float b;
    int n;
protected:
    bool selected;

public: 
    Polygon();
    Polygon(float x, float y, float radius, int n, float rot,  float r, float g, float b);
    void draw();
    bool contains(float mx, float my);
    void setColor(float r, float g, float b);
    void setSelected(bool s) { selected = s;}
};

#endif