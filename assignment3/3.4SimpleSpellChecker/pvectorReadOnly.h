//
// Created by timo on 28.10.18.
//

#ifndef INC_3_4SIMPLESPELLCHECKER_PVECTORREADONLY_H
#define INC_3_4SIMPLESPELLCHECKER_PVECTORREADONLY_H

#include <fstream>
#include <vector>
#include <iostream>
#include "persistence_traits.h"

template<typename T, typename P=persistence_traits<T, std::vector<T>>>
class pvectorReadOnly {

    std::string filename;
    std::vector<T> v;

    void readvector() {
        std::ifstream ifs(filename);
        P::read(ifs, v);

    }

public:
    pvectorReadOnly(std::string fname) : filename(fname) {
        //std::cout << "pvectorReadOnly's constructor called!" << std::endl;
        readvector();
    }

    ~pvectorReadOnly() {
        //std::cout << "pvectorReadOnly's destructor called!" << std::endl;
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

#endif //INC_3_4SIMPLESPELLCHECKER_PVECTORREADONLY_H
