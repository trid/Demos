//
// Created by TriD on 27.05.2015.
//

#ifndef FAMILY_BUSINESS_POINT_H
#define FAMILY_BUSINESS_POINT_H

#include <cmath>

#include <SFML/Graphics.hpp>

namespace MEng {

    class Point {
    public:
        int x, y;

        Point() = default;

        Point(int x, int y) : x(x), y(y) { }

        Point(const sf::Vector2f& vec) : x(vec.x), y(vec.y) {}

        int squareEuclideanDist() { return x * x + y * y; }
        int euclideanDist() { return std::sqrt(squareEuclideanDist()); }
        int manhattanDist() { return std::abs(x + y); }

        sf::Vector2f asVector2f() const { return {static_cast<float>(x), static_cast<float>(y)}; }
    };

    inline Point operator+(const Point &p1, const Point &p2) {
        return Point{p1.x + p2.x, p1.y + p2.y};
    }

    inline Point operator-(const Point &p1, const Point &p2) {
        return Point{p1.x - p2.x, p1.y - p2.y};
    }

    inline bool operator==(const Point &p1, const Point &p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }

    inline int squareEuclideanDist(const Point& p1, const Point& p2) {
        return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    }

    inline int euclideanDist(const Point& p1, const Point& p2) {
        return std::sqrt(squareEuclideanDist(p1, p2));
    }

    inline int manhattanDist(const Point& p1, const Point& p2) {
        return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
    }
}

#endif //FAMILY_BUSINESS_POINT_H
