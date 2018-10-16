//
// Created by timo on 14.10.18.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>

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

    static void write(ofstream &o, C &container) {
        for(const T &elem : container) {
            o << elem << endl;
        }
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

    static void write(ofstream &o, C &container) {
        for(const string &elem : container) {
            o << elem << endl;
        }
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
        P::write(ofs, v);
    }

public:
    pvector(string fname) : filename(fname) {
        cout << "pvector's constructor called!" << endl;        
	readvector();
    }

    ~pvector() {
        cout << "pvector's destructor called!" << endl;
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


template<typename T, typename P=persistence_traits<T, set<T>>>
class pset {
    
    string filename;
    set<T> s;

    void readset() {
        ifstream ifs(filename);
        P::read(ifs, s);
    }

    void writeset() {
        ofstream ofs(filename);
        P::write(ofs, s);
    }

public:
    pset(string fname) : filename(fname) {
        cout << "pset's constructor called!" << endl;
        readset();
    }

    ~pset() {
        cout << "pset's destructor called!" << endl;
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
        cout << *s.begin() << endl;
    }

};


void vectorTest(pvector<string> *pv) {

    if(pv->getSize() > 0) pv->printValue(0);
    pv->push_back("Hi! This is a string readline test using pvector.");

}

void setTest(pset<string> *ps) {

    if(ps->getSize() > 0) ps->printValue(0);
    ps->push_back("Hi! This is a string readline test using pset.");

}

int main(int argc, char *argv[]) {

    pvector<string> pv("/tmp/testVector.txt");
    vectorTest(&pv);

    pset<string> ps("/tmp/testSet.txt");
    setTest(&ps);

    return 0;

}

