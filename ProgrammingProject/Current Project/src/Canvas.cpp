#include "Canvas.h"
#include "Circle.h"
#include <GL/freeglut.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    // 
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
    Point* p = new Point(x, y, r, g, b, size);
    points.push_back(p);
    allShapes.push_back(p);
    shapeTypes.push_back(PENCIL);
}

void Canvas::addCircle(float x, float y, float radius, float r, float g, float b) {
    Circle* c = new Circle(x, y, radius, r, g, b);
    circles.push_back(c);
    allShapes.push_back(c);
    shapeTypes.push_back(CIRCLE);
}

void Canvas::addTriangle(float x, float y, float base, float height, float r, float g, float b) {
    Triangle* t = new Triangle(x, y, base, height, r, g, b);
    triangles.push_back(t);
    allShapes.push_back(t);
    shapeTypes.push_back(TRIANGLE);
}

void Canvas::addRectangle(float x, float y, float width, float height, float r, float g, float b) {
    Rectangle* rect = new Rectangle(x, y, width, height, r, g, b);
    rectangles.push_back(rect);
    allShapes.push_back(rect);
    shapeTypes.push_back(RECTANGLE);
}

void Canvas::addPolygon(float x, float y, int sides, float length, float r, float g, float b) {
    Polygon* p = new Polygon(x, y, sides, length, r, g, b);
    polygons.push_back(p);
    allShapes.push_back(p);
    shapeTypes.push_back(POLYGON);
}

void Canvas::undo() {
    if (allShapes.empty()) return;

    Shape* lastShape = allShapes.back();
    TOOL lastType = shapeTypes.back();

    // Remove from type-specific vector
    switch (lastType) {
        case PENCIL:
            for (size_t i = 0; i < points.size(); i++) {
                if (points[i] == lastShape) {
                    points.erase(points.begin() + i);
                    break;
                }
            }
            break;
        case CIRCLE:
            for (size_t i = 0; i < circles.size(); i++) {
                if (circles[i] == lastShape) {
                    circles.erase(circles.begin() + i);
                    break;
                }
            }
            break;
        // Similar cases for other shape types...
    }

    // Remove from unified storage
    allShapes.pop_back();
    shapeTypes.pop_back();
    
    // Clean up if this was the selected shape
    if (selectedShape == lastShape) {
        selectedShape = nullptr;
    }
    
    delete lastShape;
}

void Canvas::clear() {
    // Delete all shapes through the unified vector
    for (Shape* shape : allShapes) {
        delete shape;
    }
    
    // Clear all containers
    allShapes.clear();
    points.clear();
    circles.clear();
    triangles.clear();
    rectangles.clear();
    polygons.clear();
    shapeTypes.clear();
    
    selectedShape = nullptr;
}

void Canvas::render() {
    // Draw all shapes
    for (Shape* shape : allShapes) {
        shape->draw();
    }
    
    // Draw selection highlight if needed
    if (selectedShape) {
        glColor3f(1, 1, 0); // Yellow selection color
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
        
        // Get bounding box (implement this in your Shape class)
        float left = selectedShape->x;
        float right = selectedShape->x + selectedShape->getWidth();
        float top = selectedShape->y;
        float bottom = selectedShape->y + selectedShape->getHeight();
        
        // Add some padding
        float padding = 5.0f;
        glVertex2f(left - padding, top - padding);
        glVertex2f(right + padding, top - padding);
        glVertex2f(right + padding, bottom + padding);
        glVertex2f(left - padding, bottom + padding);
        
        glEnd();
    }
}

// Selection methods
Shape* Canvas::getSelectedShape(float mx, float my) {
    // Check from newest to oldest (top to bottom in Z-order)
    for (int i = allShapes.size() - 1; i >= 0; i--) {
        if (allShapes[i]->contains(mx, my)) {
            return allShapes[i];
        }
    }
    return nullptr;
}

void Canvas::selectShapeAt(float x, float y) {
    selectedShape = getSelectedShape(x, y);
}

void Canvas::moveSelectedShape(float dx, float dy) {
    if (selectedShape) {
        selectedShape->x += dx;
        selectedShape->y += dy;
    }
}

void Canvas::deselect() {
    selectedShape = nullptr;
}