//
// Created by TriD on 24.05.2015.
//

#include "Screen.h"

#include <iostream>

#include "View.h"
#include "../Application.h"

using std::cout;
using std::endl;

using namespace MEng::View;

Screen::Screen() {
    window.create(sf::VideoMode(width, height), "meng Window");
}

void Screen::draw() {
    Application &application = Application::getInstance();
    if (application.hasState()) {
        application.getCurrentState().getView().draw(window);
    }
    window.display();
}
