//
// Created by timo on 27.10.18.
//

#ifndef L3_2RPNCOMPLEX_PERSISTANCE_TRAITS_H
#define L3_2RPNCOMPLEX_PERSISTANCE_TRAITS_H

#include <fstream>

template<typename T, typename C>
struct persistence_traits {

    static void read(std::ifstream &i, C &container) {
        for(;;) {
            auto end = container.end();
            T x;
            i >> x;
            if(!i.good()) break;
            container.insert(end, x);
        }
    }

    static void write(std::ofstream &o, C &container) {
        for(const T &elem : container) {
            o << elem << std::endl;
        }
    }

};

template<typename C>
struct persistence_traits<std::string, C> {

    static void read(std::ifstream &i, C &container) {
        for(;;) {
            auto end = container.end();
            std::string x;
            getline(i, x);
            if(!i.good()) break;
            container.insert(end, x);
        }
    }

    static void write(std::ofstream &o, C &container) {
        for(const std::string &elem : container) {
            o << elem << std::endl;
        }
    }
};

#endif //L3_2RPNCOMPLEX_PERSISTANCE_TRAITS_H
