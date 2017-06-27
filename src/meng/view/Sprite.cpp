//
// Created by TriD on 10.08.2015.
//

#include "Sprite.h"

using namespace MEng::View;

void Sprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void Sprite::nextFrame() {
    ++currentFrame;
    updateFrame();
}

void Sprite::resetFrame() {
    currentFrame = 0;
    updateFrame();
}

void Sprite::updateFrame() {
    sprite.setTextureRect({currentFrame * frameSize.x, 0, frameSize.x, frameSize.y});
}
