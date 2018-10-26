//
// Created by timo on 26.10.18.
//

#ifndef INC_4_1PVECTORPERSISTERTRAIT_PSET_H
#define INC_4_1PVECTORPERSISTERTRAIT_PSET_H

#include <set>
#include <iostream>
#include "persistence_traits.h"

template<typename T, typename P=persistence_traits<T, std::set<T>>>
class pset {

    std::string filename;
    std::set<T> s;

    void readset() {
        std::ifstream ifs(filename);
        P::read(ifs, s);
    }

    void writeset() {
        std::ofstream ofs(filename);
        P::write(ofs, s);
    }

public:
    pset(std::string fname) : filename(fname) {
        std::cout << "pset's constructor called!" << std::endl;
        readset();
    }

    ~pset() {
        std::cout << "pset's destructor called!" << std::endl;
        writeset();
    }

    void push_back(const T &el) {
        s.insert(s.end(), el);
    }

    void pop_back() {
        s.erase(s.end());
    }

    int getSize() {
        return s.size();
    }

    void printValue (int index) {
        std::cout << *s.begin() << std::endl;
    }

};

#endif //INC_4_1PVECTORPERSISTERTRAIT_PSET_H
