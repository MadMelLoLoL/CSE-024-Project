#include "Circle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>
#include <bits/types/FILE.h>
#include <iostream>

Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = 0.1;
    selected = false;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Circle::Circle(float x, float y, float radius,float r, float g, float b) {
    this->x = x; 
    this->y = y; 
    this->radius = radius;
    selected = false;
    this->r = r; 
    this->g = g; 
    this->b = b; 
}

void Circle::draw() {
    glColor3f(r, g, b);

    float inc = M_PI / 32;
    glBegin(GL_POLYGON);
        for (float theta = 0; theta <= 2 * M_PI; theta += inc){
            glVertex2d(x + cos(theta) * radius, y + sin(theta) * radius);
        }
    glEnd();

}

bool Circle::contains(float mx, float my) {
    float dx = mx- x;
    float dy = my - y;
    float distanceSquared = dx * dx + dy * dy;
    return distanceSquared <= (radius * radius);
}

void Circle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Circle::setPosition(float x, float y){
    this->x = x;
    this->y = y;
}

void Circle::resize(float factor){
    radius *= factor;

    radius = std::max(0.01f, radius);
    radius = std::min(2.0f, radius);
}

float Circle::getSize() const{
    return radius;
}