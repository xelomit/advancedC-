//
// Created by timo on 28.09.18.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

template<typename T>
class pvector {
    string filename;
    vector<T> v;

    void readvector() {
        ifstream ifs(filename);
        for(;;) {
            T x;
            ifs >> x;
            if(!ifs.good()) break;
            v.push_back(x);
        }
    }

    void writevector() {
        ofstream ofs(filename);
        for (const T &elem : v) ofs << elem << endl;
    }

public:
    pvector(string fname) : filename(fname) {
        readvector();
    }

    ~pvector() {
        cout << "destructor called!" << endl;
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
        cout << v[index] << endl;
    }
};

void foo(pvector<int>* pv) {

    if(pv->getSize() > 0) pv->printValue(0);
    pv->push_back(18);

}

int main(int argc, char *argv[]) {

    pvector<int> pv("/tmp/test.txt");
    foo(&pv);

}

