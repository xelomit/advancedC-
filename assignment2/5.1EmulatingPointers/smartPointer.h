//
// Created by timo on 26.10.18.
//

#ifndef INC_5_1EMULATINGPOINTERS_SMARTPOINTER_H
#define INC_5_1EMULATINGPOINTERS_SMARTPOINTER_H

#include <string>

template<typename T>
struct smartPointer {

    int* pointerCounter;
    T *object;
    std::string address;

public:
    // regular constructor
    smartPointer(T &obj) {
        object = &obj;

        std::stringstream ss;
        ss << &obj;
        address = ss.str();

        pointerCounter = new int(1);
    }

    // copy constructor
    smartPointer(const smartPointer<T> &sp) {
        object = sp.object;
        pointerCounter = sp.pointerCounter;

        address = sp.address;

        (*pointerCounter)++;
    }

    // destructor
    ~smartPointer() {
        if ((*pointerCounter)-- < 0) {
            delete object;
            delete pointerCounter;
        }
    }

    std::string getAddress() {
        return address;
    }

    int counter() {
        return *pointerCounter;
    }

    T operator*() {
        return *object;
    }

    T* operator->() {
        return object;
    }

    smartPointer<T>& operator= (const smartPointer<T>& sp) {
        if (this == &sp) return *this;

        // decrease pointerCounter of lvalue
        --(*pointerCounter);

        // lvalue's pointerCounter now points to the same value as rvalue's pointerCounter
        pointerCounter = sp.pointerCounter;  // pointerCounter now points to the same value as rvalue's pointerCounter
        object = sp.object;
        address = sp.address;

        // increase pointerCounter (which both lvalue & rvalue now point to)
        ++(*pointerCounter);

        return *this;
    }
};

#endif //INC_5_1EMULATINGPOINTERS_SMARTPOINTER_H
