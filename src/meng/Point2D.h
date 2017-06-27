//
// Created by TriD on 14.12.2015.
//

#ifndef OBAKE_REAL_ESTATE_POINT2D_H
#define OBAKE_REAL_ESTATE_POINT2D_H

namespace MEng {

    template <typename T> class Point2D {
        T x;
        T y;

        Point2D<T> operator+(Point2D<T> point) {
            return Point2D<T>{this->x + point.x, this->y + point.y};
        }
    };

}

#endif //OBAKE_REAL_ESTATE_POINT2D_H
