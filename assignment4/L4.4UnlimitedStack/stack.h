#ifndef L4_4UNLIMITEDSTACK_STACK_H
#define L4_4UNLIMITEDSTACK_STACK_H


class stack {

    int buf[256];
    int sp;

public:

    stack();
    virtual ~stack();

    virtual void push(int i);
    virtual int pop();
    virtual bool empty();
    virtual bool full();

};


#endif //L4_4UNLIMITEDSTACK_STACK_H
