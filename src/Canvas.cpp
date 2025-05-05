#include "Canvas.h"
#include "Circle.h"
#include "Polygon.h"
#include "Scribble.h"
#include <GL/freeglut.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    // 
}


//scribble instead of points
void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
    if (scribbles.empty() || scribbles.back()->isFinalized()) {
        Scribble* newScribble = new Scribble();
        newScribble->setColor(r, g, b);
        scribbles.push_back(newScribble);
    }
    // Add point using scribble's color instead of individual colors
    scribbles.back()->addPoint(x, y, r, g, b, size);
}
void Canvas::addRectangle(float x, float y, float width, float height, float r, float g, float b) {
    shapes.push_back(new Rectangle(x, y,width, height, r, g, b));
}

void Canvas::addCircle(float x, float y, float radius, float r, float g, float b) {
    shapes.push_back(new Circle(x, y, radius, r, g, b));
}

void Canvas::addPolygon(float x, float y, float radius, int n, float rot, float r, float g, float b){
    shapes.push_back(new Polygon(x, y, radius, n, rot, r, g, b));
}

void Canvas::clear() {
    for (unsigned int i = 0 ; i < points.size(); i++) {
        delete points[i];
    }
    points.clear();

    for (unsigned int i = 0 ; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();

    //scribble clear
    for (unsigned int i = 0 ; i < scribbles.size(); i++) {
        delete scribbles[i];
    }
    scribbles.clear();
}

void Canvas::render() {
    for (unsigned int i = 0 ; i < points.size(); i++) {
        points[i]->draw();
    }

    for (unsigned int i = 0 ; i < shapes.size(); i++) {
        shapes[i]->draw();
    }

    for (unsigned int i = 0 ; i < scribbles.size(); i++){
        scribbles[i]->draw();
    }
}

Shape* Canvas::getSelectedShape(float mx, float my) {
    Shape* selectedShape = nullptr;

    for (unsigned int i = 0; i < shapes.size(); i++) {
        // ask every shape if we clicked on it
        if (shapes[i]->contains(mx, my)) {
            std::cout << "Clicked on shape[" << i << "]" << std::endl;
            selectedShape = shapes[i];
            break;
        }
    }

    for (unsigned int i = 0; i < scribbles.size(); i++){
        if (scribbles[i]->contains(mx,my)){
            std::cout << "Clicked on scribble["<< i << "]" << std::endl;
            selectedShape = scribbles[i];
            break;
        }
    }
    if (selectedShape == nullptr) {
        std::cout << "No selected shape or scribble" << std::endl;
    }

    return selectedShape;
}

void Canvas::eraseShapeAt(float x, float y){
    //erases shapes
    for (int i = shapes.size() - 1; i >= 0; i--){
        if (shapes[i] && shapes[i]->contains(x,y)){
            if (selectedShape == i) selectedShape = -1;

            delete shapes[i];
            shapes.erase(shapes.begin() + i);

            if (selectedShape > i) selectedShape--;
            return;
        }
    }

    // Erase scribbles
    for (int i = scribbles.size()-1; i >= 0; i--) {
        if (scribbles[i] && scribbles[i]->contains(x, y)) {
            if (selectedShape == i) selectedShape = -1;
            delete scribbles[i];
            scribbles.erase(scribbles.begin() + i);
            
        }
        
    }
}