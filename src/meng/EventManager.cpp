//
// Created by TriD on 25.05.2015.
//

#include <SFML/Graphics.hpp>
#include <TGUI/Gui.hpp>

#include "EventManager.h"
#include "Application.h"
#include "view/Screen.h"

using namespace MEng;

void EventManager::process() {
    sf::Event event;

    auto& screen = View::Screen::getInstance();

    while (screen.getWindow().pollEvent(event)) {
        //Store state for cases when state will be popped in event processing time. Yes, dear me, I have a problem here.
        StatePtr currentState = Application::getInstance().lockCurrentState();

        // Handle events on GUI. If event was handled, don't pass it further;
        if (currentState) {
            if (currentState->getView().getGui().handleEvent(event)) {
                continue;
            }
        }

        switch (event.type) {
            case sf::Event::Closed:
                Application::getInstance().finish();
                break;
            case sf::Event::MouseButtonPressed:
                currentState->onClick(Point{event.mouseButton.x, event.mouseButton.y}, event.mouseButton.button);
                break;
            case sf::Event::MouseMoved:
                currentState->onMouseMove(Point{event.mouseMove.x, event.mouseMove.y});
                break;
            case sf::Event::KeyReleased:
                currentState->onKeyUp(event.key.code);
                break;
            case sf::Event::KeyPressed:
                currentState->onKeyDown(event.key.code);
                break;
            default:
                break;
        }
    }
}
