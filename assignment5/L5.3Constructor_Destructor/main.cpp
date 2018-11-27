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

/* The calling of con- and destructors in case of inheritance follows the 'onion'-principle:
 * After instantiating a "child"-object, first the child-class's base-class's constructor is executed,
 * followed by the constructor of the child-class itself.
 * The executions of destructors follow the opposite way: First, the child-class destructor is executed,
 * followed by the destructor of the base-class.
 * */