#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    float x;
    float y;
    float width;
    float height;
    float r;
    float g;
    float b;

public:
    Rectangle();
    Rectangle(float x, float y, float width, float height, float r, float g, float b);

    void draw();

    friend struct AppTest;
};

#endif