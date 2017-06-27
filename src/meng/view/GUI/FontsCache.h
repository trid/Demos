//
// Created by TriD on 13.07.2015.
//

#ifndef FAMILY_BUSINESS_FONTSCACHE_H
#define FAMILY_BUSINESS_FONTSCACHE_H

#include <string>
#include <sstream>
#include <unordered_map>
#include <SFML/Graphics/Font.hpp>

namespace MEng {
    namespace View {
        namespace GUI {

            using FontsMap = std::unordered_map<std::string, sf::Font>;

            class FontsCache {
            private:
                FontsCache() { }

                FontsMap fontsMap;
            public:
                static FontsCache &getInstance() {
                    static FontsCache fontsCache;
                    return fontsCache;
                }

                sf::Font& getFont(std::string name, int size) {
                    std::stringstream ss;
                    ss << name << "," << size;

                    const std::string &fontName = ss.str();
                    if (fontsMap.find(fontName) == fontsMap.end()) {
                        fontsMap[fontName].loadFromFile(name);
                    }
                    return fontsMap[fontName];
                }
            };

        }
    }
}
#endif //FAMILY_BUSINESS_FONTSCACHE_H
