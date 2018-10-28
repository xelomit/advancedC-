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
        //std::cout << "pvector's constructor called!" << std::endl;
        readvector();
    }

    ~pvector() {
        //std::cout << "pvector's destructor called!" << std::endl;
        writevector();
    }

    void push_back(const T &el) {
        v.push_back(el);
    }

    void pop_back() {
        v.pop_back();
    }

    void replace(int index, T replacement){
        auto ite = v.begin();
        for (int count = 0; count<index; count++){
            ++ite;
        }

        v.erase(ite);
        v.insert(ite, replacement);

    }

    int getSize() {
        return v.size();
    }

    std::vector<T> getVector() {
        return v;
    }

    void printValue (int index) {
        std::cout << v[index] << std::endl;
    }

    T getValue(int index) {
        auto ite = v.begin();
        int count;
        for(count = 0; count < index; count++){
            ite++;
        }

        return *ite;
    }

};

#endif //INC_3_4SIMPLESPELLCHECKER_PVECTORREADONLY_H
