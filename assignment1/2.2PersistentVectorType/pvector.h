//
// Created by timo on 25.10.18.
//

#ifndef INC_2_2PERSISTENTVECTORTYPE_PVECTOR_H
#define INC_2_2PERSISTENTVECTORTYPE_PVECTOR_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

template<typename T>
class pvector {
    std::string filename;
    std::vector<T> v;

    void readvector() {
        std::ifstream ifs(filename);
        for(;;) {
            T x;
            ifs >> x;
            if(!ifs.good()) break;
            v.push_back(x);
        }
    }

    void writevector() {
        std::ofstream ofs(filename);
        for (const T &elem : v) ofs << elem << std::endl;
    }

public:
    pvector(std::string fname) : filename(fname) {
        std::cout << "constructor called!" << std::endl;
        readvector();
    }

    ~pvector() {
        std::cout << "destructor called!" << std::endl;
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

#endif //INC_2_2PERSISTENTVECTORTYPE_PVECTOR_H
