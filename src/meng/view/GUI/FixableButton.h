//
// Created by TriD on 14.01.2016.
//

#ifndef OBAKE_REAL_ESTATE_FIXABLEBUTTON_H
#define OBAKE_REAL_ESTATE_FIXABLEBUTTON_H

#include <SFML/Graphics.hpp>
#include "Widget.h"
#include "Label.h"

namespace MEng {
namespace View {
namespace GUI {

    class FixableButton: public Widget {
    private:
        using Callback = std::function<void()>;

        bool pressed{false};

        Callback callback;
        std::string text;
        sf::Font& font;
        tgui::Label::Ptr label{nullptr};
    public:
        bool isPressed() { return pressed; }
    };

}}}

#endif //OBAKE_REAL_ESTATE_FIXABLEBUTTON_H
