//
// Created by timo on 26.10.18.
//

#ifndef INC_5_1EMULATINGPOINTERS_DUMBPOINTER_H
#define INC_5_1EMULATINGPOINTERS_DUMBPOINTER_H

#include <sstream>

template<typename T>
struct dumbPointer {

    T *object;
    std::string address;

public:
    dumbPointer(T &obj) {
        object = &obj;

        std::stringstream ss;
        ss << &obj;
        address = ss.str();
    }

    std::string getAddress() {
        return address;
    }

    T operator*() {
        return *object;
    }

    T* operator->() {
        return object;
    }
};

#endif //INC_5_1EMULATINGPOINTERS_DUMBPOINTER_H