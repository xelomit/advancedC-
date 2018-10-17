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

    T* operator->() {
        return object;
    }

};

class exampleClass {
int i;
public:
    exampleClass(int n){
     i = n;
    }

    int getNumber() {
        return i;
    }

};

int main(){

    int a = 4;
    DumbPointer<int> dumbPointer(a);
    cout << *dumbPointer << endl;
    cout << dumbPointer.getAddress() << endl;
    int b = 5;
    a = b;
    cout << *dumbPointer << endl;
    cout << dumbPointer.getAddress() << endl;

    int c = 7;
    exampleClass testObject(c);
    DumbPointer<exampleClass> dumbPointer1(testObject);

    cout << dumbPointer1->getNumber() << endl;
    cout << dumbPointer1.getAddress() << endl;


    return 0;
}