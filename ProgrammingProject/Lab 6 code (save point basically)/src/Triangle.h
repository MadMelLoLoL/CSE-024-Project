#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
    float x;
    float y;
    float base;
    float height;
    float r;
    float g;
    float b;

public:
    Triangle();
    Triangle(float x, float y, float base, float height, float r, float g, float b);

    void draw();

    friend struct AppTest;
};

#endif