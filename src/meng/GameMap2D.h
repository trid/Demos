//
// Created by TriD on 13.12.2015.
//

#ifndef OBAKE_REAL_ESTATE_GAMEMAP2D_H
#define OBAKE_REAL_ESTATE_GAMEMAP2D_H


template <typename Tile> class GameMap2D {
public:
    using Row = std::vector<Tile>;
    using MapData = std::vector<Row>;

    GameMap2D(int width, int height) {
        mapData.resize(width);
        for (auto& item: mapData) {
            item.resize(height);
        }
    }

    Tile& getTile(Point point) { return mapData[point.x][point.y]; }
    const Tile& getTile(Point point) const { return mapData[point.x][point.y]; }

    unsigned int getWidth() { return width; }
    unsigned int getHeight() { return height; }
private:
    MapData mapData;

    unsigned int width;
    unsigned int height;
};


#endif //OBAKE_REAL_ESTATE_GAMEMAP2D_H
