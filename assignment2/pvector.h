#ifndef P_VECTOR
#define P_VECTOR

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
        cout << v[index] << endl;
    }

    T get (int index) {
      return v[index];
    }

};

#endif
