//
// Created by TriD on 27.05.2015.
//

#include "Dialog.h"

#include <algorithm>

using namespace MEng::View::GUI;

void Dialog::addWidget(WidgetPtr widget) {
    widgets.push_back(widget);
}

void Dialog::removeWidget(WidgetPtr widget) {
    auto iter = std::remove(begin(widgets), end(widgets), widget);
    widgets.erase(iter, widgets.end());
}

void Dialog::clearWidgets() {
    widgets.clear();
}


