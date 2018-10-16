//
// Created by timo on 16.10.18.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template<typename T>
struct DumbPointer {

    T *object;
    string address;

public:
    DumbPointer(T &obj) {
        object = &obj;

        stringstream ss;
        ss << &obj;
        address = ss.str();
    }

    string getAddress() {
        return address;
    }

    T operator*() {
        return *object;
    }

};

int main(){

    int a = 4;
    DumbPointer<int> dumbPointer(a);
    //int* dumbPointer = &a;
    cout << *dumbPointer << endl;
    cout << dumbPointer.getAddress() << endl;
    //cout << dumbPointer << endl;
    int b = 5;
    a = b;
    cout << *dumbPointer << endl;
    cout << dumbPointer.getAddress() << endl;
    //cout << dumbPointer << endl;


    return 0;
}