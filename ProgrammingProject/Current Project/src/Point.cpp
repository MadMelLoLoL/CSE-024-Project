#include "Point.h"
#include <GL/freeglut.h>

// Constructors
Point::Point() : Shape(0, 0, 0, 0, 0), size(1) {}

Point::Point(float x, float y) : Shape(x, y, 0, 0, 0), size(1) {}

Point::Point(float x, float y, float r, float g, float b) 
    : Shape(x, y, r, g, b), size(1) {}

Point::Point(float x, float y, float r, float g, float b, int size) 
    : Shape(x, y, r, g, b), size(size) {}

// Drawing implementation
void Point::draw() const {
    glColor3f(r, g, b);
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

// Hit detection - makes point selectable in a small area around it
bool Point::contains(float mx, float my) const {
    // Calculate distance from mouse to point
    float dx = mx - x;
    float dy = my - y;
    float distanceSquared = dx*dx + dy*dy;
    
    // Consider point "hit" if within 2x visual size
    float hitRadius = size * 2.0f;
    return distanceSquared <= (hitRadius * hitRadius);
}

// Simple dimension getters for selection highlighting
float Point::getWidth() const { 
    return size * 4.0f; // Double the hit radius for visible selection box
}

float Point::getHeight() const { 
    return size * 4.0f; // Double the hit radius for visible selection box
}