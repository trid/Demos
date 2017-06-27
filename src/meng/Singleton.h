//
// Created by TriD on 21.11.2015.
//

#ifndef OBAKE_REAL_ESTATE_SINGLETON_H
#define OBAKE_REAL_ESTATE_SINGLETON_H

namespace MEng {
    template <typename T>
    class Singleton {
    public:
        static T& getInstance() {
            static T instance;
            return instance;
        }
    };
}

#endif //OBAKE_REAL_ESTATE_SINGLETON_H
