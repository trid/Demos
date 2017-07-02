//
// Created by TriD on 28.06.2017.
//

#ifndef MENG_MAP2D_H
#define MENG_MAP2D_H

#include <vector>

namespace MEng::Utils {

    template<typename T>
    class Map2D {
    private:
        std::vector<T> data;

        const int width;
        const int height;
    public:
        Map2D(int w, int h) : width(w), height(h) { data.resize(w * h); }

        T &getTile(int x, int y) { return data[x + y * height]; }

        void setTile(int x, int y, const T &tile) { data[x + y * height] = tile; }

        int getWidth() const { return width; }

        int getHeight() const { return height; }
    };

}
#endif //MENG_MAP2D_H
