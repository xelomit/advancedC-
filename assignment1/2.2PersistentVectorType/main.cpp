//
// Created by timo on 28.09.18.
//

#include "pvector.h"

using namespace std;



void foo(pvector<int>* pv) {

    if(pv->getSize() > 0) pv->printValue(0);
    pv->push_back(18);

}

int main(int argc, char *argv[]) {

    pvector<int> pv("/tmp/test.txt");
    foo(&pv);

    return 0;

}
