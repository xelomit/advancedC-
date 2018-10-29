#include <iostream>
#include <functional>
#include "foo.h"

int main() {

    foo testObject;

    auto greet = std::mem_fn(&foo::display_greeting);
    greet(testObject);

    auto print_num = std::mem_fn(&foo::display_number);
    print_num(testObject, 7);

    auto access_data = std::mem_fn(&foo::data);
    std::cout << "data stored in foo struct: int data = " << access_data(testObject) <<
    std:: endl;

    return 0;
}