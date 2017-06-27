//
// Created by TriD on 26.06.2015.
//

#ifndef FAMILY_BUSINESS_KEYBOARDEVENTLISTENER_H
#define FAMILY_BUSINESS_KEYBOARDEVENTLISTENER_H

#include <memory>

namespace MEng {

    class KeyboardEventListener {
    public:
        virtual void onKeyDown(int key) = 0;
        virtual void onKeyUp(int key) = 0;
    };

    using KeyboardEventListenerPtr = std::shared_ptr<KeyboardEventListener>;
}

#endif //FAMILY_BUSINESS_KEYBOARDEVENTLISTENER_H
