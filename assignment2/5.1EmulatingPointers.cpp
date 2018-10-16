//
// Created by timo on 16.10.18.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template<typename T>
struct DumbPointer {
    T object;
    string address;

public:
    DumbPointer(T &obj) {
        object = obj;
        stringstream ss;
        ss << &obj;
        address = ss.str();
    }

    string getAddress() {
        return address;
    }

};

int main(){

    int a = 4;
    DumbPointer<int> dumbPointer(a);
    //auto addr = &a;
    cout << "adress: " << dumbPointer.getAddress() << endl;

    return 0;
}