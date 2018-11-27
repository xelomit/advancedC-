//
// Created by timo on 27.11.18.
//

#include "base.h"


base::base() {
    cout << "Constructor of \"base\" called!" << endl;
}

base::~base() {
    cout << "Destructor of \"base\" called!" << endl;
}

void base::foo1() {
    cout << "base::foo1() called!" << endl;
}