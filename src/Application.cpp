#include "Application.h"
#include "Enums.h"

using namespace bobcat;
using namespace std;
float offsetX = 0;
float offsetY = 0;
bool isDraggingShape = false;


void Application::eraseAt(float x, float y){
    canvas->eraseShapeAt(x, y);
}

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        eraseAt(mx,my);
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my,0.3, 0.3, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == CIRCLE) { 
        canvas->addCircle(mx, my, 0.2, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == TRIANGLE){
        canvas->addPolygon(mx, my, 0.15, 3, M_PI / 6, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == POLYGON){
        canvas->addPolygon(mx, my, 0.15, 5, M_PI / 2, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == MOUSE) {
        selectedShape = canvas->getSelectedShape(mx, my);
        if(selectedShape){
            isDraggingShape = true;
        }
    }
    else if (tool == TO_FRONT){
        if (selectedShape) {
            canvas->moveShapeToFront(selectedShape);
        }
    }
    else if (tool == TO_BACK){
        if (selectedShape) {
            canvas->moveShapeToBack(selectedShape);
        }
    }
    else if (tool == BIG || tool == SMALL) {
        selectedShape = canvas->getSelectedShape(mx, my);
        if (selectedShape) {
            float resizeFactor = (tool == BIG) ? 1.1f : 0.9f;  // 10% bigger/smaller
            selectedShape->resize(resizeFactor);
            canvas->redraw();
        }
    }


}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        eraseAt(mx, my);
        canvas->redraw();
    }
    else if(tool == MOUSE && isDraggingShape && selectedShape){
        selectedShape->setPosition(mx, my);
        canvas->redraw();
    }
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
}

void Application::onColorSelectorChange(bobcat::Widget* sender) {
    Color color = colorSelector->getColor();

    if (selectedShape) {
        cout << "Update selected shape color" << endl;
        selectedShape->setColor(color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my){
    isDraggingShape = false;
}


Application::Application() {
    window = new Window(25, 75, 400, 600, "Paint Simulator");

    selectedShape = nullptr;

    toolbar = new Toolbar(0, 0, 50, 600);
    canvas = new Canvas(50, 0, 350, 475);
    colorSelector = new ColorSelector(50, 475, 350, 125);

    colorSelector->box(FL_BORDER_BOX);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    ON_CHANGE(colorSelector, Application::onColorSelectorChange);

    window->show();
}