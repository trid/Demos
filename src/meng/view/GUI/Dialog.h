//
// Created by TriD on 27.05.2015.
//

#ifndef FAMILY_BUSINESS_MENU_H
#define FAMILY_BUSINESS_MENU_H

#include "Widget.h"
#include "UILayout.h"
#include "Panel.h"

#include <memory>
#include <vector>

namespace MEng {
    namespace View {
        namespace GUI {

            using Widgets = std::vector<WidgetPtr>;

            class Dialog : public Panel {
            private:
                Widgets widgets;
                sf::Color backgroundColor{0, 0, 0, 0};
                UILayout &layout;

            public:
                Dialog(int x, int y, int w, int h, UILayout &layout) : Panel(tgui::Layout2d{w, h}),
                                                                       layout(layout) {
                    setPosition(x, y);
                    Widget::hide();
                }

                void addWidget(WidgetPtr widget);

                void removeWidget(WidgetPtr widget);

                void clearWidgets();

                sf::Color getBgColor() const { return backgroundColor; }

                void setBgColor(sf::Color color) { Dialog::backgroundColor = color; }

                virtual void show() override {
                    Widget::show();
                }

                virtual void hide() override {
                    Widget::hide();
                }
            };

        }
    }
}
#endif //FAMILY_BUSINESS_MENU_H
