//
// Created by timo on 28.09.18.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

template<typename T>
struct persistence_traits {

    static void read(ifstream &i, vector<T> &v) {
        for(;;) {
            T x;
            i >> x;
            if(!i.good()) break;
            v.push_back(x);
        }
    }

    static void write(ofstream &o, T &elem) {
        o << elem << endl;
    }
};

template<>
struct persistence_traits<string> {

    //TODO: Read full lines, not just words.
    static void read(ifstream &i, vector<string> &v) {
        for(;;) {
            string x;
            i >> x;
            if(!i.good()) break;
            v.push_back(x);
        }
    }

    static void write(ofstream &o, string &elem) {
        o << elem << endl;
    }
};

template<typename T>
class pvector {
    string filename;
    vector<T> v;

    void readvector() {
        ifstream ifs(filename);
        persistence_traits<T>::read(ifs, v);

    }

    void writevector() {
        ofstream ofs(filename);

        typename vector<T>::iterator fst=v.begin(), lst=v.end();

        while(fst != lst) persistence_traits<T>::write(ofs, *fst++);
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

void foo(pvector<int> *pv) {

    if(pv->getSize() > 0) pv->printValue(0);
    pv->push_back(95);

}

int main(int argc, char *argv[]) {

    pvector<int> pv("/tmp/test.txt");
    foo(&pv);

}

