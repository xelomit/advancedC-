#ifndef L4_4UNLIMITEDSTACK_UNLIMITED_STACK_H
#define L4_4UNLIMITEDSTACK_UNLIMITED_STACK_H

#include <vector>

#include "stack.h"

class unlimited_stack : public stack {

    std::vector<int> buf;


public:

    unlimited_stack();
    virtual ~unlimited_stack();

    virtual void push(int i);
    virtual int pop();
    virtual bool empty();
    virtual bool full();

};


#endif //L4_4UNLIMITEDSTACK_UNLIMITED_STACK_H
