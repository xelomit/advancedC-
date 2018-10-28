//
// Created by timo on 28.10.18.
//

#ifndef INC_3_4SIMPLESPELLCHECKER_PSET_H
#define INC_3_4SIMPLESPELLCHECKER_PSET_H

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
        //std::cout << "pset's constructor called!" << std::endl;
        readset();
    }

    ~pset() {
        //std::cout << "pset's destructor called!" << std::endl;
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

    T getValue(int index) {
        auto ite = s.begin();
        int count;
        for(count = 0; count < index; count++){
            ite++;
        }

        return *ite;
    }

    auto find(T focus) {
        return s.find(focus);
    }

    auto begin() {
        return s.begin();
    }

    auto end() {
        return s.end();
    }

};

#endif //INC_3_4SIMPLESPELLCHECKER_PSET_H
