#include "Application.h"

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->addPoint(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
    else if (tool == CIRCLE) {
        canvas->addCircle(mx, my, 0.1, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(mx, my, 0.2, 0.2, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, 0.2, 0.2, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == POLYGON) {
        canvas->addPolygon(mx, my, 6, 0.1, color.getR(), color.getG(), color.getB());
        canvas->redraw();
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
        canvas->addPoint(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
    if (action == UNDO) {
        canvas->undo();
        canvas->redraw();
    }
}

Application::Application() {
    window = new Window(25, 75, 400, 400, "Paint Application Shapes");

    toolbar = new Toolbar(0, 0, 50, 400);
    canvas = new Canvas(50, 0, 350, 350);
    colorSelector = new ColorSelector(50, 350, 350, 50);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);

    window->show();
}