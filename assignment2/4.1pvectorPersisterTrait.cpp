//
// Created by timo on 14.10.18.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

template<typename T, typename C>
struct persistence_traits {

    static void read(ifstream &i, C &container) {
        for(;;) {
            auto end = container.end();
            T x;
            i >> x;
            if(!i.good()) break;
            container.insert(end, x);
        }
    }

    static void write(ofstream &o, T &elem) {
        o << elem << endl;
    }
};

template<typename C>
struct persistence_traits<string, C> {

    static void read(ifstream &i, C &container) {
        for(;;) {
            auto end = container.end();
            string x;
            getline(i, x);
            if(!i.good()) break;
            container.insert(end, x);
        }
    }

    static void write(ofstream &o, string &elem) {
        o << elem << endl;
    }
};

template<typename T, typename P=persistence_traits<T, vector<T>>>
class pvector {
    string filename;
    vector<T> v;

    void readvector() {
        ifstream ifs(filename);
        P::read(ifs, v);

    }

    void writevector() {
        ofstream ofs(filename);

        typename vector<T>::iterator fst=v.begin(), lst=v.end();

        while(fst != lst) P::write(ofs, *fst++);
    }

public:
    pvector(string fname) : filename(fname) {
        cout << "constructor called!" << endl;        
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

//TODO: Define class pset analog to pvector.

void foo(pvector<string> *pv) {

    if(pv->getSize() > 0) pv->printValue(0);
    pv->push_back("Hi! This is a string readline test.");

}

int main(int argc, char *argv[]) {

    pvector<string> pv("/tmp/test.txt");
    foo(&pv);

}

