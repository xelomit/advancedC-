//
// Created by timo on 27.11.18.
//

#ifndef L5_3CONSTRUCTOR_DESTRUCTOR_CHILD_H
#define L5_3CONSTRUCTOR_DESTRUCTOR_CHILD_H

#include "base.h"

struct child : base {
public:
    child();
    virtual ~child();
    void foo1() override;
};

#endif //L5_3CONSTRUCTOR_DESTRUCTOR_CHILD_H
