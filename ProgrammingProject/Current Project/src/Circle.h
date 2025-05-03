#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
    float x;
    float y;
    float radius;
    float r;
    float g;
    float b;

public:

    float getX() const { return x; }
    float getY() const { return y; }
    float getRadius() const { return radius; }
    float getR() const;
    float getG() const;
    float getB() const;

    Circle();
    Circle(float x, float y, float radius, float r, float g, float b);

    void draw();

    friend struct AppTest;
};

#endif