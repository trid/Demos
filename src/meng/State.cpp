//
// Created by TriD on 24.05.2015.
//

#include <algorithm>

#include "State.h"

using namespace MEng;

void State::addMouseEventListener(MouseEventListenerPtr mouseEventListener) {
    mouseEventListeners.push_back(mouseEventListener);
}

void State::addKeyboardEventListener(KeyboardEventListenerPtr keyboardEventListener) {
    keyboardEventListeners.push_back(keyboardEventListener);
}

void State::removeMouseEventListener(MouseEventListenerPtr mouseEventListener) {
    std::remove(mouseEventListeners.begin(), mouseEventListeners.end(), mouseEventListener);
}

void State::removeKeyboardEventListener(KeyboardEventListenerPtr keyboardEventListener) {
    std::remove(keyboardEventListeners.begin(), keyboardEventListeners.end(), keyboardEventListener);
}

void State::clearListeners() {
    keyboardEventListeners.clear();
    mouseEventListeners.clear();
}

void State::run() {
    auto time = clock.restart();

    for (auto process: processes) {
        process->update(time.asMilliseconds());
    }

    auto iter = std::remove_if(processes.begin(), processes.end(), [](StateProcess::ProcessPtr ptr){ return ptr->isFinished(); });
    processes.erase(iter, processes.end());

    view->update(time.asMilliseconds());
}

void State::save(std::ofstream &out) {

}

void State::load(std::ifstream &in) {

}

void State::onClick(const MEng::Point &point, int button) {
    view->onClick(point, button);
    for (auto listener: mouseEventListeners) {
        listener->click(point, button);
    }
}

void State::onKeyDown(int keyCode) {
    view->onKeyDown(keyCode);
    for (auto listener: keyboardEventListeners) {
        listener->onKeyDown(keyCode);
    }
}

void State::onKeyUp(int keyCode) {
    view->onKeyUp(keyCode);
    for (auto listener: keyboardEventListeners) {
        listener->onKeyUp(keyCode);
    }
}

void State::onMouseMove(Point position) {
    view->onMouseMove(position);
    for (auto listener: mouseEventListeners) {
        listener->move(position);
    }
}
