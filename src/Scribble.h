#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include <cmath>

#include "Point.h"
#include "Shape.h"


class Scribble : public Shape {
    Point points[5000];
    int pCounter;

    float x;
    float y;
    float r;
    float g;
    float b;
    float left;
    float right;
    float top;
    float bottom;
    bool finalized = false;
    bool selected = false;

    public:

        bool isFinalized() const { return finalized; }
        void finalize() { finalized = true; }

        Scribble() {
            pCounter = 0;
            selected = false;
            left = 0;
            right = 0;
            top = 0;
            bottom = 0;
        }

        void addPoint(float x, float y, float r, float g, float b, int size) {
            if (pCounter >= 5000) return;  //safety check
            if (pCounter == 0) {
                this->x = x;
                this->y = y;

                
            }
            selected = false;
            if (this->x - x > left) left = this->x - x;
            if (x - this->x > right) right = x - this->x;
            if (y - this->y > top) top = y - this->y;
            if (this->y - y > bottom) bottom = this->y - y;

            points[pCounter] = Point(x - this->x, y - this->y, r, g, b , size);
            pCounter++;
        }

        void draw() {
            if (selected) {
                glLineWidth(2);
                glColor3f(0.66, 0.66, 0.66);

                glBegin(GL_LINE_LOOP);
                glVertex2f(x - left - 0.04, y + top + 0.04);
                glVertex2f(x + right + 0.04, y + top + 0.04);
                glVertex2f(x + right + 0.04, y - bottom - 0.04);
                glVertex2f(x - left - 0.04, y - bottom - 0.04);
                glEnd();

                glLineWidth(1);
            }

            for (int i = 0; i < pCounter; i++) {
                float currX = x + points[i].getX();
                float currY = y + points[i].getY();
                float currR = getR();
                float currG = getG();
                float currB = getB();
                Point temp(currX, currY, currR, currG, currB, 7);
                temp.draw();
            }  
        }

        bool contains(float mx, float my) {
            if (!(mx >= x - left && mx <= x + right &&my <= y + top && my >= y - bottom)) {
                return false;
            }

            //checks individual points
            const float outerBorder = 10.0f;
            const float outerBorder_SQ = outerBorder * outerBorder;
            
            for (int i = 0; i < pCounter; i++) {
                float px = x + points[i].getX();
                float py = y + points[i].getY();
                float dx = px - mx;
                float dy = py - my;
                float distanceSq = dx*dx + dy*dy;
                
                if (distanceSq <= outerBorder_SQ) {
                    return true;
                }
            }
            return false;
        }

        void setColor(float r, float g, float b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }

        void setPosition(float x, float y){
            this->x = x;
            this->y = y;
        }
};

#endif