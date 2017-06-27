//
// Created by TriD on 10.08.2015.
//

#ifndef FAMILY_BUSINESS_SPRITE_H
#define FAMILY_BUSINESS_SPRITE_H

#include <memory>

#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "../Point.h"

namespace MEng {
    namespace View {

        class Sprite : public MEng::View::Drawable {
        private:
            Point frameSize;
            int currentFrame{0};

            sf::Sprite sprite;

            void updateFrame();

        public:
            Sprite(const Point &frameSize, const Point &position, sf::Texture& texture) : frameSize(frameSize),
                                                                                          sprite(texture) {
                sprite.setPosition(position.asVector2f());
            }

            void nextFrame();
            void resetFrame();
            void setPosition(Point position) { sprite.setPosition(position.asVector2f()); }

        protected:
            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
        };

        using SpritePtr = std::shared_ptr<Sprite>;

    }
}
#endif //FAMILY_BUSINESS_SPRITE_H
