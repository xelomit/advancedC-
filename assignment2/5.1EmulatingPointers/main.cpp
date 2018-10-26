//
// Created by timo on 17.10.18.
//

#include <iostream>
#include "dumbPointer.h"
#include "smartPointer.h"
#include "object.h"

using namespace std;


void print(smartPointer<object> sp) { cout << "number: " << sp->getNumber() << ", counter: " << sp.counter() << endl; }

void dumbPointerTest() {
    cout << "====== dumbPointerTest start ======" << endl;

    int a = 4;
    dumbPointer<int> dumbPointer1(a);
    cout << *dumbPointer1 << endl;
    cout << dumbPointer1.getAddress() << endl;
    int b = 5;
    a = b;
    cout << *dumbPointer1 << endl;
    cout << dumbPointer1.getAddress() << endl;

    int c = 7;
    object testObject(c);
    dumbPointer<object> dumbPointer2(testObject);

    cout << dumbPointer2->getNumber() << endl;
    cout << dumbPointer2.getAddress() << endl;

    cout << "====== dumbPointerTest end ======" << endl << endl;
}

void smartPointerTest() {
    cout << "====== smartPointerTest start ======" << endl;

    object o1(1);       // let's create our 1st object
    object o2(2);       // let's create our 2nd object

    smartPointer<object> p(o1);    // ref counter is 1 for 1st object
    cout << "Pointer counter p: " << p.counter() << endl;    // displays 1

    smartPointer<object> q(p);     // another smart pointer that points to o1 (overload copy constructor)
    cout << "Pointer counter p: " << p.counter() << endl;    // displays 2 (two smart pointers refer to o1)
    cout << "Pointer counter q: " << q.counter() << endl;    // displays 2 (two smart pointers refer to o1)

    smartPointer<object> r(o2);    // ref counter is 1 for 2nd object
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