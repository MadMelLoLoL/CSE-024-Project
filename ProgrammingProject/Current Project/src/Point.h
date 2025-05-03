#ifndef POINT_H
#define POINT_H

#include "Shape.h"

class Point : public Shape {
private:
    int size;

public:
    // Constructors
    Point();
    Point(float x, float y);
    Point(float x, float y, float r, float g, float b);
    Point(float x, float y, float r, float g, float b, int size);

    // Shape interface implementation
    void draw() const override;
    bool contains(float mx, float my) const override;
    
    // Simple size-based dimensions for selection
    float getWidth() const override { return size * 2.0f; }
    float getHeight() const override { return size * 2.0f; }

    // Getters
    int getSize() const { return size; }
    
    // Setters
    void setSize(int newSize) { size = newSize; }

    friend struct AppTest;
};

#endif