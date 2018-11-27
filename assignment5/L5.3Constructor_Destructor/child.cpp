//
// Created by timo on 27.11.18.
//

#include "child.h"

child::child() {
    cout << "Constructor of \"child\" called!" << endl;
}


child::~child() {
    cout << "Destructor of \"child\" called!" << endl;
}

void child::foo1() {
    cout << "child::foo1() called!" << endl;
}
