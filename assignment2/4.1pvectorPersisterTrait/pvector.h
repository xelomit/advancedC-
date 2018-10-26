//
// Created by timo on 26.10.18.
//

#ifndef INC_4_1PVECTORPERSISTERTRAIT_PVECTOR_H
#define INC_4_1PVECTORPERSISTERTRAIT_PVECTOR_H

#include <fstream>
#include <vector>
#include <iostream>
#include "persistence_traits.h"

template<typename T, typename P=persistence_traits<T, std::vector<T>>>
class pvector {

    std::string filename;
    std::vector<T> v;

    void readvector() {
        std::ifstream ifs(filename);
        P::read(ifs, v);

    }

    void writevector() {
        std::ofstream ofs(filename);
        P::write(ofs, v);
    }

public:
    pvector(std::string fname) : filename(fname) {
        std::cout << "pvector's constructor called!" << std::endl;
        readvector();
    }

    ~pvector() {
        std::cout << "pvector's destructor called!" << std::endl;
        writevector();
    }

    void push_back(const T &el) {
        v.push_back(el);
    }

    void pop_back() {
        v.pop_back();
    }

    int getSize() {
        return v.size();
    }

    void printValue (int index) {
        std::cout << v[index] << std::endl;
    }

};

#endif //INC_4_1PVECTORPERSISTERTRAIT_PVECTOR_H
