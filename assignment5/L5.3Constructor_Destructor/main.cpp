#include <iostream>
#include "base.h"
#include "child.h"

using namespace std;

void execFoo(base &o) {
    o.foo1();
}

int main() {
/*    cout << "Instantiating a \"base\"-object..." << endl;

    base o1;
    o1.foo1();*/

    cout << "Instantiating a \"child\"-object..." << endl;

    child o2;
    o2.foo1();

    // Testing the functionality of the 'virtual'-keyword...
    /*cout << "Calling \"foo\"-method via execFoo(base &o), whilst passing the child object..." << endl;
    execFoo(o2);
    */
    return 0;
}