#ifndef POLYGON_H
#define POLYGON_H

class Polygon {
    float x;
    float y;
    int sides;
    float length;
    float r;
    float g;
    float b;

public:
    Polygon();
    Polygon(float x, float y, int sides, float length, float r, float g, float b);

    void draw();

    friend struct AppTest;
};

#endif