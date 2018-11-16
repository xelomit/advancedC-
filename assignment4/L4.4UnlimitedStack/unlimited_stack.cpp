#include "unlimited_stack.h"

unlimited_stack::unlimited_stack() {

    // empty

}

unlimited_stack::~unlimited_stack() {

    // empty

}

void unlimited_stack::push(int i) {

    buf.push_back(i);

}

int unlimited_stack::pop() {

    int temp = buf.back();
    buf.pop_back();
    return temp;

}

bool unlimited_stack::empty() {

    return buf.size() <= 0;

}

// This boolean is always false, as an unlimited_stack
// cannot be full in any situation.
bool unlimited_stack::full() {

    return false;

}


