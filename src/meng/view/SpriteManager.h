//
// Created by TriD on 19.07.2015.
//

#ifndef FAMILY_BUSINESS_SPRITEMANAGER_H
#define FAMILY_BUSINESS_SPRITEMANAGER_H

#include <boost/log/trivial.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Screen.h"

namespace MEng {
    namespace View {

        using SpriteCache = std::unordered_map<std::string, sf::Texture>;

        class SpriteManager {
        private:
            std::string directory{};
            SpriteCache spriteCache;
        public:
            static SpriteManager &getInstance() {
                static SpriteManager instance;
                return instance;
            }

            sf::Texture& getTexture(std::string name) {
                if (spriteCache.find(name) == spriteCache.end()) {
                    if (!spriteCache[name].loadFromFile(directory + name)) {
                        BOOST_LOG_TRIVIAL(error) << "Can not load file '" << directory << name << "'";
                    }
                }
                auto& item = spriteCache[name];
                return item;
            }

            void addTexture(const std::string& name, const sf::Texture& texture) {
                spriteCache[name] = texture;
            }

            void setDirectory(const std::string& directory) {
                this->directory = directory;
            }
        };

    }
}

#endif //FAMILY_BUSINESS_SPRITEMANAGER_H
