//
// Created by TriD on 24.05.2015.
//

#ifndef FAMILY_BUSINESS_SCREEN_H
#define FAMILY_BUSINESS_SCREEN_H


#include <SFML/Graphics.hpp>
#include <memory>

namespace MEng {
    namespace View {
        class View;

        using ViewPtr = std::shared_ptr<View>;

        class Screen {
        private:
            unsigned int width = 800;
            unsigned int height = 600;

            sf::RenderWindow window;

            Screen();

        public:
            static Screen &getInstance() {
                static Screen instance;
                return instance;
            }

            void draw();

            sf::RenderWindow& getWindow() { return window; }

            int getWidth() { return width; }

            int getHeight() { return height; }

            sf::Vector2f getSize() { return {static_cast<float>(width), static_cast<float>(height)}; }

            void close();
        };
    }
}

#endif //FAMILY_BUSINESS_SCREEN_H
