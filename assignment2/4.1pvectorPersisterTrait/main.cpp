//
// Created by timo on 14.10.18.
//

#include "persistence_traits.h"
#include "pvector.h"
#include "pset.h"


using namespace std;


void vectorTest(pvector<string> *pv) {

    if(pv->getSize() > 0) pv->printValue(0);
    pv->push_back("Hi! This is a string readline test using pvector.");

}

void setTest(pset<string> *ps) {

    if(ps->getSize() > 0) ps->printValue(0);
    ps->push_back("Hi! This is a string readline test using pset.");

}

int main(int argc, char *argv[]) {

    pvector<string> pv("/tmp/testVector.txt");
    vectorTest(&pv);

    pset<string> ps("/tmp/testSet.txt");
    setTest(&ps);

    return 0;

}
