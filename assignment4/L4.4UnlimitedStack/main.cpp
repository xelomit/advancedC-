#include <iostream>

#include "stack.h"
#include "unlimited_stack.h"

using namespace std;

void stack_pop_call_by_reference(stack& s, bool is_basic_stack) {

    if(is_basic_stack) {

        cout << "- stack ";

    } else {

        cout << "- unlimited_stack ";

    }

    cout << "passed by reference: stack.pop() == ";
    cout << s.pop() << endl;

}

void stack_pop_using_shallow_copy(stack s, bool is_basic_stack) {

    if(is_basic_stack) {

        cout << "- stack ";

    } else {

        cout << "- unlimited_stack ";

    }

    cout << "passed by shallow copy: stack.pop() == ";
    cout << s.pop() << endl;

}

int main()
{

    stack s1;
    stack s2;
    unlimited_stack us1;
    unlimited_stack us2;

    for (int i = 0; i < 100; ++i) {

        s1.push(i);
        s2.push(i);
        us1.push(i);
        us2.push(i);

    }

    stack_pop_using_shallow_copy(s1, true);
    stack_pop_using_shallow_copy(us1, false);

    cout << endl;

    stack_pop_call_by_reference(s2, true);
    stack_pop_call_by_reference(us2, false);


    return 0;
}