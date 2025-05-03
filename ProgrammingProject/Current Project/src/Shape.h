#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>

class Shape {
protected:
    float x, y;        // Position coordinates
    float r, g, b;     // Color components
    float width;       // Bounding box dimensions
    float height;

public:
    Shape(float x, float y, float r, float g, float b) 
        : x(x), y(y), r(r), g(g), b(b), width(0), height(0) {}
    
    virtual ~Shape() = default;

    // Pure virtual functions (must be implemented by derived classes)
    virtual void draw() const = 0;
    virtual bool contains(float mx, float my) const = 0;
    
    // Virtual functions (can be overridden by derived classes)
    virtual float getWidth() const { return width; }
    virtual float getHeight() const { return height; }
    
    // Position accessors
    float getX() const { return x; }
    float getY() const { return y; }
    void setPosition(float newX, float newY) { x = newX; y = newY; }
    void move(float dx, float dy) { x += dx; y += dy; }
    
    // Color accessors
    void setColor(float newR, float newG, float newB) { 
        r = newR; g = newG; b = newB; 
    }
    void getColor(float &outR, float &outG, float &outB) const {
        outR = r; outG = g; outB = b;
    }

    // Bounding box utilities
    virtual void updateBoundingBox() {
        // Default implementation, override in derived classes
        width = 10.0f;
        height = 10.0f;
    }
};

#endif