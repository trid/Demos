//
// Created by TriD on 26.06.2015.
//

#ifndef FAMILY_BUSINESS_MOUSEEVENTLISTENER_H
#define FAMILY_BUSINESS_MOUSEEVENTLISTENER_H

#include <memory>
#include "Point.h"

namespace MEng {

    class MouseEventListener {
    public:
        virtual void click(Point point, int button) = 0;
        virtual void move(Point position) = 0;
    };

    using MouseEventListenerPtr = std::shared_ptr<MouseEventListener>;

}

#endif //FAMILY_BUSINESS_MOUSEEVENTLISTENER_H
