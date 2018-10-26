#ifndef P_VECTOR
#define P_VECTOR

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
        //cout << "pvector's constructor called!" << endl;
	      readvector();
    }

    ~pvector() {
        //cout << "pvector's destructor called!" << endl;
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

};

#endif