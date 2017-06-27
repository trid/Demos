//
// Created by dmitry-khovyakov on 5/25/15.
//

#ifndef FAMILY_BUSINESS_VIEW_H
#define FAMILY_BUSINESS_VIEW_H

#include <algorithm>
#include <vector>

#include "GUI/UILayout.h"
#include "Screen.h"
#include "../Point.h"
#include "Drawable.h"
#include "Animation.h"

namespace MEng {
    namespace View {

        class View {
        private:
            std::unique_ptr<tgui::Gui> gui;
            std::vector<MEng::View::DrawablePtr> drawables;
            std::vector<MEng::View::AnimationPtr> animations;
        public:
            View();
            virtual ~View();

            virtual void draw(sf::RenderWindow &renderer);

            virtual void onClick(const MEng::Point &point, int button);

            virtual void onMouseMove(const MEng::Point point);

            virtual bool onKeyUp(int key);;

            virtual bool onKeyDown(int key);;

            virtual void update(int timeDelta);

            tgui::Gui &getLayout() { return *gui; }

            void addDrawable(MEng::View::DrawablePtr drawable) { drawables.push_back(drawable); }

            void removeDrawable(MEng::View::DrawablePtr drawablePtr) {
                drawables.erase(std::remove(drawables.begin(), drawables.end(), drawablePtr), drawables.end());
            }

            void addAnimation(MEng::View::AnimationPtr animation) { animations.push_back(animation); }

            tgui::Gui& getGui() { return *gui; }
        };

        using ViewPtr = std::shared_ptr<View>;

    }
}

#endif //FAMILY_BUSINESS_VIEW_H
