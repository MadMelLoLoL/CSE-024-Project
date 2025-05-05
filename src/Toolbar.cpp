#include "Toolbar.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/image.h>
using namespace bobcat;

void Toolbar::deselectAllTools() {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    polygonButton->color(FL_BACKGROUND_COLOR);
    mouseButton->color(FL_BACKGROUND_COLOR);
    toFrontButton->color(FL_BACKGROUND_COLOR);
    toBackButton->color(FL_BACKGROUND_COLOR);
    biggerButton->color(FL_BACKGROUND_COLOR);
    smallerButton->color(FL_BACKGROUND_COLOR);
}

void Toolbar::visualizeSelectedTool() {
    if (tool == PENCIL) {
        pencilButton->color(FL_WHITE);
    }
    else if (tool == ERASER) {
        eraserButton->color(FL_WHITE);
    }
    else if (tool == CIRCLE) {
        circleButton->color(FL_WHITE);
    }
    else if (tool == TRIANGLE) {
        triangleButton->color(FL_WHITE);
    }
    else if (tool == RECTANGLE) {
        rectangleButton->color(FL_WHITE);
    }
    else if (tool == POLYGON) {
        polygonButton->color(FL_WHITE);
    }
    else if (tool == MOUSE) {
        mouseButton->color(FL_WHITE);
    }
    else if(tool == TO_FRONT){
        toFrontButton->color(FL_WHITE);
    }
    else if (tool == TO_BACK){
        toBackButton->color(FL_WHITE);
    }
    else if(tool == BIG){
        biggerButton->color(FL_WHITE);
    }
    else if (tool == SMALL){
        smallerButton->color(FL_WHITE);
    }
}

void Toolbar::onClick(bobcat::Widget* sender) {
    deselectAllTools();
    Fl_Widget* below = Fl::belowmouse();
    printf("clicked: %p | below mouse: %p\n", sender, below);

    action = NONE;

    if (sender == pencilButton) {
        tool = PENCIL;
    }
    else if (sender == eraserButton) {
        tool = ERASER;
    }
    else if (sender == circleButton) {
        tool = CIRCLE;
    }
    else if (sender == triangleButton) {
        tool = TRIANGLE;
    }
    else if (sender == rectangleButton) {
        tool = RECTANGLE;
    }
    else if (sender == polygonButton) {
        tool = POLYGON;
    }
    else if (sender == clearButton) {
        action = CLEAR;
    }
    else if (sender == mouseButton) {
        tool = MOUSE;
    }
    else if (sender == toFrontButton){
        tool = TO_FRONT;
    }
    else if (sender == toBackButton){
        tool = TO_BACK;
    }
    else if (sender == biggerButton){
        tool = BIG;
    }
    else if (sender == smallerButton){
        tool = SMALL;
    }


    if (onChangeCb) {
        onChangeCb(this);
    }

    visualizeSelectedTool();
    redraw();
}

TOOL Toolbar::getTool() const {
    return tool;
}

ACTION Toolbar::getAction() const {
    return action;
}

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
    pencilButton = new Image(x, y, 50, 50, "./assets/pencil.png");
    eraserButton = new Image(x, y + 50, 50, 50, "./assets/eraser.png");
    circleButton = new Image(x, y + 100, 50, 50, "./assets/circle.png");
    triangleButton = new Image(x, y + 150, 50, 50, "./assets/triangle.png");
    rectangleButton = new Image(x, y + 200, 50, 50, "./assets/rectangle.png");
    polygonButton = new Image(x, y + 250, 50, 50, "./assets/polygon.png");
    clearButton = new Image(x, y + 300, 50, 50, "./assets/clear.png");
    mouseButton = new Image(x, y + 350, 50, 50, "./assets/mouse.png");
    toFrontButton = new Image(x,y+400,50,50, "./assets/bring-to-front.png");
    toBackButton = new Image(x, y + 450, 50,50, "./assets/send-to-back.png");
    biggerButton = new Image(x, y + 500,50,50, "./assets/plus.png");
    smallerButton = new Image(x, y + 550, 50,50, "./assets/minus.png");


    tool = PENCIL;
    action = NONE;

    pencilButton->box(FL_BORDER_BOX);
    eraserButton->box(FL_BORDER_BOX);
    circleButton->box(FL_BORDER_BOX);
    triangleButton->box(FL_BORDER_BOX);
    rectangleButton->box(FL_BORDER_BOX);
    polygonButton->box(FL_BORDER_BOX);
    clearButton->box(FL_BORDER_BOX);
    mouseButton->box(FL_BORDER_BOX);
    toFrontButton->box(FL_BORDER_BOX);
    toBackButton->box(FL_BORDER_BOX);
    biggerButton->box(FL_BORDER_BOX);
    smallerButton->box(FL_BORDER_BOX);

    visualizeSelectedTool();

    ON_CLICK(pencilButton, Toolbar::onClick);
    ON_CLICK(eraserButton, Toolbar::onClick);
    ON_CLICK(circleButton, Toolbar::onClick);
    ON_CLICK(triangleButton, Toolbar::onClick);
    ON_CLICK(rectangleButton, Toolbar::onClick);
    ON_CLICK(polygonButton, Toolbar::onClick);
    ON_CLICK(clearButton, Toolbar::onClick);
    ON_CLICK(mouseButton, Toolbar::onClick);
    ON_CLICK(toFrontButton, Toolbar::onClick);
    ON_CLICK(toBackButton, Toolbar::onClick);
    ON_CLICK(biggerButton, Toolbar::onClick);
    ON_CLICK(smallerButton, Toolbar::onClick);
}