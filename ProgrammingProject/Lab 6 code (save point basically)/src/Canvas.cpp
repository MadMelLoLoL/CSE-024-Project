#include "Canvas.h"
#include <GL/freeglut.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    // 
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
    points.push_back(new Point(x, y, r, g, b, size));
    shapes.push_back(PENCIL);
}

void Canvas::addCircle(float x, float y, float radius, float r, float g, float b) {
    circles.push_back(new Circle(x, y, radius, r, g, b));
    shapes.push_back(CIRCLE);
}

void Canvas::addTriangle(float x, float y, float base, float height, float r, float g, float b) {
    triangles.push_back(new Triangle(x, y, base, height, r, g, b));
    shapes.push_back(TRIANGLE);
}

void Canvas::addRectangle(float x, float y, float width, float height, float r, float g, float b) {
    rectangles.push_back(new Rectangle(x, y, width, height, r, g, b));
    shapes.push_back(RECTANGLE);
}

void Canvas::addPolygon(float x, float y, int sides, float length, float r, float g, float b) {
    polygons.push_back(new Polygon(x, y, sides, length, r, g, b));
    shapes.push_back(POLYGON);
}

void Canvas::undo() {
    if(shapes.empty()){
        return;
    }

    TOOL lastShape = shapes.back();

    if(lastShape == PENCIL){
        if(!points.empty()){
            delete points.back();
            points.pop_back();
        }
    }
    else if(lastShape == CIRCLE){
        if(!circles.empty()){
            delete circles.back();
            circles.pop_back();
        }
    }
    else if (lastShape == TRIANGLE){
        if(!triangles.empty()){
            delete triangles.back();
            triangles.pop_back();
        }
    }
    else if (lastShape == RECTANGLE){
        if(!rectangles.empty()){
            delete rectangles.back();
            rectangles.pop_back();
        }
    }
    else if (lastShape == POLYGON){
        if(!polygons.empty()){
            delete polygons.back();
            polygons.pop_back();
        }
    }
    shapes.pop_back();
}

void Canvas::clear() {
    for (unsigned int i = 0 ; i < points.size(); i++) {
        delete points[i];
    }
    points.clear();

    for (unsigned int i = 0 ; i < circles.size(); i++) {
        delete circles[i];
    }
    circles.clear();

    for (unsigned int i = 0 ; i < triangles.size(); i++) {
        delete triangles[i];
    }
    triangles.clear();

    for (unsigned int i = 0 ; i < rectangles.size(); i++) {
        delete rectangles[i];
    }
    rectangles.clear();

    for (unsigned int i = 0 ; i < polygons.size(); i++) {
        delete polygons[i];
    }
    polygons.clear();
    
    shapes.clear();
}

void Canvas::render() {
    for (unsigned int i = 0 ; i < points.size(); i++) {
        points[i]->draw();
    }

    for (unsigned int i = 0 ; i < circles.size(); i++) {
        circles[i]->draw();
    }

    for (unsigned int i = 0 ; i < triangles.size(); i++) {
        triangles[i]->draw();
    }

    for (unsigned int i = 0 ; i < rectangles.size(); i++) {
        rectangles[i]->draw();
    }

    for (unsigned int i = 0 ; i < polygons.size(); i++) {
        polygons[i]->draw();
    }
}