#include "Canvas.h"
#include "Circle.h"
#include "Polygon.h"
#include "Scribble.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/types/FILE.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h), selectedShape(nullptr) {
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

    if (selectedShape != nullptr) {
        std::cout << "Deselecting shape during clear" << std::endl;
        selectedShape = nullptr;
    }
    else {
        std::cout << "No selected shape to deselect during clear" << std::endl;
    }
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
    
    std::cout << "=== Checking selection at (" << mx << "," << my << ") ===" << std::endl;

    for (unsigned int i = 0; i < shapes.size(); i++) {
        if (shapes[i]->contains(mx, my)) {
            shapes[i]->selected = true; 
            selectedShape = shapes[i];
            return selectedShape;
        }
       
    }

     for (unsigned int i = 0; i < scribbles.size(); i++){
        if (scribbles[i]->contains(mx,my)){
            std::cout << "Clicked on scribble["<< i << "]" << std::endl;
            selectedShape = scribbles[i];
            break;
        }
    }
    std::cout << "No selected shape or scribble" << std::endl;
    return nullptr; 
}



void Canvas::eraseShapeAt(float x, float y){
    //erases shapes
    bool wasSelectedShapeErased = false;

    for (int i = shapes.size() - 1; i >= 0; i--){
        if (shapes[i] && shapes[i]->contains(x,y)){
            if (shapes[i] == selectedShape) {
                selectedShape = nullptr;
            }
            delete shapes[i];
            shapes.erase(shapes.begin() + i);
        }
    }
    //Erase scribbles
    for (int i = scribbles.size()-1; i >= 0; i--) {
        if (scribbles[i] && scribbles[i]->contains(x, y)) {
            if (scribbles[i] == selectedShape) {
                selectedShape = nullptr;
            }
            delete scribbles[i];
            scribbles.erase(scribbles.begin() + i);
            
        }
        
    }

    if (wasSelectedShapeErased) {
        selectedShape = nullptr;
    }
}

//shape front and back plus index counter
int Canvas::findShapeIndex(Shape* shape) {
    for (size_t i = 0; i < shapes.size(); ++i) {
        if (shapes[i] == shape) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void Canvas::moveShapeToFront(Shape* shape) {
    int index = findShapeIndex(shape);
    if (index != -1) {
        // Erase from current position
        Shape* temp = shapes[index];
        shapes.erase(shapes.begin() + index);
        // Add to end
        shapes.push_back(temp);
        redraw();
    }
}

void Canvas::moveShapeToBack(Shape* shape) {
    int index = findShapeIndex(shape);
    if (index != -1) {
        // Erase from current position
        Shape* temp = shapes[index];
        shapes.erase(shapes.begin() + index);
        // Insert at beginning
        shapes.insert(shapes.begin(), temp);
        redraw();
    }
}
