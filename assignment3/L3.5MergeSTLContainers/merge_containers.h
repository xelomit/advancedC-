//
// Created by timo on 01.11.18.
//

#ifndef L3_5MERGESTLCONTAINERS_MERGE_CONTAINERS_H
#define L3_5MERGESTLCONTAINERS_MERGE_CONTAINERS_H

#include <iostream>

template <typename C1, typename C2>
struct container_merger {

public:

    container_merger() = default;

    void printContC1(C1 &c1) {
        std::cout << "Container 1:" << std::endl;
        for(auto ite = c1.begin(); ite != c1.end(); ite++){
            std::cout << *ite << " ";
        }
        std::cout << std::endl;
    }

    void printContC2(C2 &c2) {
        std::cout << "Container 2:" << std::endl;
        for(auto ite = c2.begin(); ite != c2.end(); ite++){
            std::cout << *ite << " ";
        }
        std::cout << std::endl << std::endl;
    }

    void printMapC1(C1 &c1) {
        std::cout << "Container 1:" << std::endl;
        for(auto ite = c1.begin(); ite != c1.end(); ite++){
            std::cout << ite->first << ": " << ite ->second << std::endl;
        }
        std::cout << std::endl;
    }

    void printMapC2(C2 &c2) {
        std::cout << "Container 2:" << std::endl;
        for(auto ite = c2.begin(); ite != c2.end(); ite++){
            std::cout << ite->first << ": " << ite ->second << std::endl;
        }
        std::cout << std::endl;
    }

    // This also accepts set-based associative containers as c2!
    void mergeCpp98StyleSequenceContainers(C1 &c1, C2 &c2) {

        printContC1(c1);
        printContC2(c2);

        long sizeC1 = c1.size();
        c1.resize(sizeC1 + c2.size());

        auto iteC1 = c1.begin();

        // 'skip' c1's part
        for (long count = 0; count < sizeC1; count++) {
            iteC1++;
        }

        // merge c2 into c1
        for (auto iteC2 = c2.begin(); iteC2 != c2.end(); iteC2++) {
            *iteC1 = *iteC2;
            iteC1++;
        }

    }

    // This also accepts Cpp98-style sequence containers as c2!
    void mergeSetBasedAssociativeContainers(C1 &c1, C2 &c2) {

        printContC1(c1);
        printContC2(c2);

        for(auto iteC2 = c2.begin(); iteC2 != c2.end(); iteC2++) {
            c1.insert(*iteC2);
        }

    }

    // Note, that this method only works with int-index-based maps, starting @ index 0
    void mergeMapBasedAssociativeContainers(C1 &c1, C2 &c2) {

        printMapC1(c1);
        printMapC2(c2);

        long count = c1.size();

        for(auto iteC2 = c2.begin(); iteC2 != c2.end(); iteC2++) {
            c1.insert(std::make_pair(count, iteC2->second));
            count ++;
        }
    }

    void mergeCpp98SeqContIntoMapBasedAssocCont (C1 &c1, C2 &c2) {
        printMapC1(c1);
        printContC2(c2);

        long count = c1.size();

        for(auto iteC2 = c2.begin(); iteC2 != c2.end(); iteC2++) {
            c1.insert(std::make_pair(count, *iteC2));
            count ++;
        }
    }

    void mergeMapBasedAssocContIntoCpp98SeqCont (C1 &c1, C2 &c2) {
        printContC1(c1);
        printMapC2(c2);

        long sizeC1 = c1.size();
        c1.resize(sizeC1 + c2.size());

        auto iteC1 = c1.begin();

        // 'skip' c1's part
        for (long count = 0; count < sizeC1; count++) {
            iteC1++;
        }

        // merge c2 into c1
        for (auto iteC2 = c2.begin(); iteC2 != c2.end(); iteC2++) {
            *iteC1 = iteC2->second;
            iteC1++;
        }
    }
};

#endif //L3_5MERGESTLCONTAINERS_MERGE_CONTAINERS_H
