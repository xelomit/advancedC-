//
// Created by timo on 17.10.18.
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

template<typename T>
struct SmartPointer {

    int* pointerCounter;
    T *object;
    string address;

public:
    // regular constructor
    SmartPointer(T &obj) {
        object = &obj;

        stringstream ss;
        ss << &obj;
        address = ss.str();

        pointerCounter = new int(1);
    }

    // copy constructor
    SmartPointer(const SmartPointer<T> &sp) {
        object = sp.object;
        pointerCounter = sp.pointerCounter;

        address = sp.address;

        (*pointerCounter)++;
    }

    // destructor
    ~SmartPointer() {
        if ((*pointerCounter)-- < 0) {
            delete object;
            delete pointerCounter;
        }
    }

    string getAddress() {
        return address;
    }

    int counter() {
        return *pointerCounter;
    }

    T operator*() {
        return *object;
    }

    T* operator->() {
        return object;
    }

    SmartPointer<T>& operator= (const SmartPointer<T>& sp) {
        if (this == &sp) return *this;

        // decrease pointerCounter of lvalue
        --(*pointerCounter);

        // lvalue's pointerCounter now points to the same value as rvalue's pointerCounter
        pointerCounter = sp.pointerCounter;  // pointerCounter now points to the same value as rvalue's pointerCounter
        object = sp.object;
        address = sp.address;

        // increase pointerCounter (which both lvalue & rvalue now point to)
        ++(*pointerCounter);

        return *this;
    }
};

class Object {
int i;
public:
    Object(int n){
     i = n;
    }

    int getNumber() {
        return i;
    }
};

void print(SmartPointer<Object> sp) { cout << "number: " << sp->getNumber() << ", counter: " << sp.counter() << endl; }

void dumbPointerTest() {
    cout << "====== dumbPointerTest start ======" << endl;

    int a = 4;
    DumbPointer<int> dumbPointer(a);
    cout << *dumbPointer << endl;
    cout << dumbPointer.getAddress() << endl;
    int b = 5;
    a = b;
    cout << *dumbPointer << endl;
    cout << dumbPointer.getAddress() << endl;

    int c = 7;
    Object testObject(c);
    DumbPointer<Object> dumbPointer1(testObject);

    cout << dumbPointer1->getNumber() << endl;
    cout << dumbPointer1.getAddress() << endl;

    cout << "====== dumbPointerTest end ======" << endl << endl;
}

void smartPointerTest() {
    cout << "====== smartPointerTest start ======" << endl;

    Object o1(1);       // let's create our 1st object
    Object o2(2);       // let's create our 2nd object

    SmartPointer<Object> p(o1);    // ref counter is 1 for 1st object
    cout << "Pointer counter p: " << p.counter() << endl;    // displays 1

    SmartPointer<Object> q(p);     // another smart pointer that points to o1 (overload copy constructor)
    cout << "Pointer counter p: " << p.counter() << endl;    // displays 2 (two smart pointers refer to o1)
    cout << "Pointer counter q: " << q.counter() << endl;    // displays 2 (two smart pointers refer to o1)

    SmartPointer<Object> r(o2);    // ref counter is 1 for 2nd object
    cout << "Pointer counter r: " << r.counter() << endl;    // displays 1
    q=r;                            // decrease counter for 1st object and
                                    // increase counter for 2nd object (overload assignment operator)

    cout << "Pointer counter p: " << p.counter() << endl;    // displays 1
    cout << "Pointer counter q: " << q.counter() << endl;    // displays 2
    cout << "Pointer counter r: " << r.counter() << endl;    // displays 2

    print(p); // displays 2, and the 1st object, don't delete the object pointed to by p
    print(q); // displays 3, and the 2nd object, don't delete the object pointed to by q
    print(r); // displays 3, and the 2nd object, don't delete the object pointed to by r
    cout << (*p).getNumber() << (*r).getNumber() << endl; // display 1st and 2nd object (overload operator*)
    cout << p->getNumber() << q->getNumber() << r->getNumber() << endl; // (overload operator->)

    cout << "====== smartPointerTest end ======" << endl;
} // now the destructors of p, q, and r are called, make sure that 1st
// and 2nd object is each deleted once (i.e., when the counter reaches 0)

int main(){
    dumbPointerTest();
    smartPointerTest();
    return 0;
}
