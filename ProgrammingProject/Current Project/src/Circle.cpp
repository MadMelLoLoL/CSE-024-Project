#include "Circle.h"
#include <GL/freeglut.h>
#include <cmath>

Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Circle::Circle(float x, float y, float radius, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Circle::draw() {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        float inc = 2 * M_PI / 60;
        for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
            glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
        }
    glEnd();
}