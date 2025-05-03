#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Shape.h"  // Base class header
#include "Point.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Enums.h"

class Canvas : public bobcat::Canvas_ {
private:
    // Unified storage (NEW)
    std::vector<Shape*> allShapes;
    
    // Existing type-specific storage
    std::vector<Point*> points;
    std::vector<Circle*> circles;
    std::vector<Triangle*> triangles;
    std::vector<Rectangle*> rectangles;
    std::vector<Polygon*> polygons;
    
    // Existing type tracking
    std::vector<TOOL> shapeTypes;
    
    // Selection support
    Shape* selectedShape = nullptr;

public:
    Canvas(int x, int y, int w, int h);
    ~Canvas();

    // Existing methods...
    void addPoint(float x, float y, float r, float g, float b, int size);
    // Other add methods...
    
    // Modified methods
    void undo();
    void clear();
    void render();
    
    // Selection methods
    Shape* getSelectedShape(float mx, float my);
    void selectShapeAt(float x, float y);
    void moveSelectedShape(float dx, float dy);
    void deselect();

    friend struct AppTest;
};
#endif