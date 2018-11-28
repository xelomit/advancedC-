//
// Created by timo on 26.11.18.
//

#ifndef L5_1FILELOCKERRPN_PVECTOR_H
#define L5_1FILELOCKERRPN_PVECTOR_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "persistence_traits.h"
#include "FileLocker.h"

template<typename T, typename P=persistence_traits<T, std::vector<T>>>
class pvector {

    std::string filename;
    std::vector<T> v;
    FileLocker fileLocker;
    bool locked = false;

    void readvector() {
        std::ifstream ifs(filename);
        P::read(ifs, v);
    }

    void writevector() {
        std::ofstream ofs(filename);
        P::write(ofs, v);
    }

public:
    pvector(std::string fname) : filename(fname), fileLocker(fname) {

        if(fileLocker.lock() == 0) {
            readvector();

        } else {
            this->locked = true;
            std::cout << "File " << fname << " is already x-locked!" << std::endl;
        }
    }

    ~pvector() {
        writevector();
    }

    void push_back(const T &el) {
        v.push_back(el);
    }

    void pop_back() {
        v.pop_back();
    }

    int size() {
        return v.size();
    }

    void printValue (int index) {
        std::cout << v[index] << std::endl;
    }

    T get (int index) {
        return v[index];
    }

    bool isLocked() const {
        return locked;
    }

};

#endif //L5_1FILELOCKERRPN_PVECTOR_H
