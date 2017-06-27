//
// Created by TriD on 24.05.2015.
//

#ifndef FAMILY_BUSINESS_STATE_H
#define FAMILY_BUSINESS_STATE_H


#include <memory>
#include <vector>
#include "Point.h"
#include "view/View.h"
#include "MouseEventListener.h"
#include "KeyboardEventListener.h"
#include "StateProcess.h"

namespace MEng {

    class State {
    private:
        std::vector<StateProcess::ProcessPtr> processes;

        View::ViewPtr view;
        std::vector<MEng::MouseEventListenerPtr> mouseEventListeners;
        std::vector<MEng::KeyboardEventListenerPtr> keyboardEventListeners;

        sf::Clock clock;
    protected:
        void setView(View::ViewPtr viewPtr) { view = viewPtr; }

    public:
        View::View& getView() { return *view; }

        virtual void onActivate() { };

        virtual void onDeactivate() { };

        virtual void onClick(const MEng::Point &point, int button);

        virtual void onMouseMove(Point position);

        virtual void onKeyDown(int keyCode);

        virtual void onKeyUp(int keyCode);

        virtual void run();

        void addMouseEventListener(MEng::MouseEventListenerPtr mouseEventListener);

        void addKeyboardEventListener(MEng::KeyboardEventListenerPtr keyboardEventListener);

        void addProcess(StateProcess::ProcessPtr processPtr) { processes.push_back(processPtr); }

        void removeMouseEventListener(MEng::MouseEventListenerPtr mouseEventListener);

        void removeKeyboardEventListener(MEng::KeyboardEventListenerPtr keyboardEventListener);

        void clearListeners();

        virtual void save(std::ofstream& out);

        virtual void load(std::ifstream& in);

        State(View::ViewPtr view = nullptr): view(view) {}
        virtual ~State() { };
    };

    using StatePtr = std::shared_ptr<State>;

}
#endif //FAMILY_BUSINESS_STATE_H
