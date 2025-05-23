#include "Rectangle.h"
#include <GL/freeglut.h>

Rectangle::Rectangle() {
    x = 0.0;
    y = 0.0;
    width = 0.3;
    height = 0.3;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    selected = false;
}

Rectangle::Rectangle(float x, float y, float width, float height, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    selected = false;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Rectangle::draw() {
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();

}

bool Rectangle::contains(float mx, float my) {
    if (mx >= x - width/2 && mx <= x + width/2 && my <= y + height/2 && my >= y - height/2) {
        return true;
    }
    return false;
}

void Rectangle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Rectangle::setPosition(float x, float y){
    this->x = x;
    this->y = y;
}

void Rectangle::resize(float factor){
    width*=factor;
    height*=factor;
}

float Rectangle::getSize() const{
    return (width + height) / 2.0f;
}