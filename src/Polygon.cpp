#include "Polygon.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>

Polygon::Polygon(){
    x = 0;
    y = 0;
    n = 3;
    radius = 0.2;
    selected = false;
    rot = 0;
}

Polygon::Polygon(float x, float y, float radius, int n , float rot, float r, float g, float b){
    this->x = x;
    this->y = y;
    this->radius = radius;
    selected = false;
    this->n = n;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Polygon::draw(){
    glColor3f(r, g, b);

    float inc = (2 * M_PI) / n;
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++){
        float theta = i * inc + rot + M_PI/2;
        glVertex2f(radius * cos(theta) + x, radius * sin(theta) + y);
    }
    glEnd();

}

bool Polygon::contains(float mx, float my){
    int numIntersections = 0;
    const float inc = (2 * M_PI) / n;

    for (int i = 0; i < n; i++){
        float x1 = radius * cos(i * inc + rot + M_PI/2) + x;
        float y1 = radius * sin(i * inc + rot + M_PI/2) + y;
        float x2 = radius * cos(((i +1) % n) * inc + rot + M_PI/2) + x;
        float y2 = radius * sin(((i +1) % n) * inc + rot + M_PI/2) + y;

        if ((my < y1) != (my < y2) && mx < x1 + ((my - y1) / (y2 - y1)) * (x2 - x1)){
            const float xIntersect = (my - y1) * (x2 - x1) / (y2- y1) + x1;
            if ( mx< xIntersect){
                numIntersections++;
            }
        }
    }

    return numIntersections % 2 == 1;
}

void Polygon::setColor(float r, float g, float b){
    this->r = r;
    this->g = g;
    this->b = b;
}

void Polygon::setPosition(float x, float y){
    this->x = x;
    this->y = y;
}

void Polygon::resize(float factor){
    radius*=factor;
}

float Polygon::getSize() const{
    return radius;
}