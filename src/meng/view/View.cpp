//
// Created by dmitry-khovyakov on 5/25/15.
//

#include <iostream>

#include <TGUI/TGUI.hpp>

#include "View.h"

#include "Screen.h"

using MEng::Point;
using namespace MEng::View;

void View::draw(sf::RenderWindow &renderer) {
    for (auto item: drawables) {
        renderer.draw(*item);
    }

    gui->draw();
}

void View::onClick(const Point &point, int button) {
}

void View::update(int timeDelta) {
    for (auto animation: animations) {
        animation->update(timeDelta);
    }

    std::for_each(animations.begin(), animations.end(), [](AnimationPtr animationPtr) { if (animationPtr->isFinished()) animationPtr->finalize(); });
    auto iter = std::remove_if(animations.begin(), animations.end(), [](AnimationPtr animationPtr){ return animationPtr->isFinished();});
    animations.erase(iter, animations.end());
}

void View::onMouseMove(const MEng::Point point) {

}

bool View::onKeyUp(int key) {
}

bool View::onKeyDown(int key) {
}

View::View() {
    Screen &screen = Screen::getInstance();
    gui.reset(new tgui::Gui(screen.getWindow()));
}

View::~View() {
}
