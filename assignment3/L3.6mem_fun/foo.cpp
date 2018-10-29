//
// Created by timo on 29.10.18.
//

#include <iostream>
#include "foo.h"


void foo::display_greeting() {
    std::cout << "Hello world!" << std::endl;
}

void foo::display_number(int i) {
    std::cout << "Number entered: " << i << std::endl;
}