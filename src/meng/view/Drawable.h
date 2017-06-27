//
// Created by TriD on 22.07.2015.
//

#ifndef FAMILY_BUSINESS_DRAWABLE_H
#define FAMILY_BUSINESS_DRAWABLE_H

#include <memory>
#include <SFML/Graphics.hpp>

namespace MEng {
    namespace View {

        using Drawable = sf::Drawable;

        using DrawablePtr = std::shared_ptr<Drawable>;

    }
}

#endif //FAMILY_BUSINESS_DRAWABLE_H
