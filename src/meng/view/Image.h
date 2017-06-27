//
// Created by TriD on 04.08.2015.
//

#ifndef FAMILY_BUSINESS_IMAGE_H
#define FAMILY_BUSINESS_IMAGE_H

#include <memory>

#include <SFML/Graphics.hpp>

#include "Drawable.h"
#include "../Point.h"

namespace MEng {
    namespace View {

        using Image = sf::Sprite;

        using ImagePtr = std::shared_ptr<Image>;

    }
}

#endif //FAMILY_BUSINESS_IMAGE_H
