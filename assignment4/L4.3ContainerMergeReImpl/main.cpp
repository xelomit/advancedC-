#include <vector>
#include <list>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <deque>
#include <bits/unordered_map.h>
#include "container_merger.h"

void printHelp() {
    std::cout << "Welcome to the advanced STL container merging demo!" << std::endl << std::endl;
    std::cout << "1: Merge two Cpp98-style sequence containers (list into vector)" << std::endl;
    std::cout << "2: Merge two set-based associative containers (unordered set into set)" << std::endl;
    std::cout << "3: Merge two map-based associative containers (unordered map into map)" << std::endl;
    std::cout << "4: Merge a set-based assoc. cont. into a Cpp98-style seq. cont. (set into vector)" << std::endl;
    std::cout << "5: Merge a Cpp98-style seq. cont. into a set-based assoc. cont. (list into unordered set)" << std::endl;
    std::cout << "6: Merge a Cpp98-style seq. cont. into a map-based assoc. cont. (vector into map)" << std::endl;
    std::cout << "7: Merge a a map-based assoc. cont. into a Cpp98-style seq. cont. (unordered map into list)" << std::endl;

    std::cout << "Please select: " << std::endl;
}

int main() {

    std::vector<int> v;
    v.push_back(1);
    v.push_back(6);

    std::list<int> l;
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    std::set<int> s;
    s.insert(6);
    s.insert(10);
    s.insert(8);

    std::unordered_set<int> us;
    us.insert(9);
    us.insert(8);

    std::map<int, int> m1;
    m1.insert(std::make_pair(0, 10));
    m1.insert(std::make_pair(1, 11));

    std::unordered_map<int, int> m2;
    m2.insert(std::make_pair(2, 12));
    m2.insert(std::make_pair(3, 13));

    printHelp();

    int answer;
    std::cin>>answer;

    switch(answer) {
        case 1: {

            container_merger<std::vector<int>, std::list<int>> cm;
            cm.mergeCpp98StyleSequenceContainers(v, l);

            std::cout << "Result container:" << std::endl;
            for (auto ite=v.begin(); ite != v.end(); ite++) {
                std::cout << *ite << " ";
            }
            std::cout << std::endl;

            break;
        }
        case 2: {

            container_merger<std::set<int>, std::unordered_set<int>> cm;
            cm.mergeSetBasedAssociativeContainers(s, us);

            std::cout << "Result container:" << std::endl;
            for (auto ite=s.begin(); ite != s.end(); ite++) {
                std::cout << *ite << " ";
            }
            std::cout << std::endl;

            break;
        }
        case 3: {

            container_merger<std::map<int, int>, std::unordered_map<int, int>> cm;
            cm.mergeMapBasedAssociativeContainers(m1, m2);

            std::cout << "Result container:" << std::endl;
            for (auto ite=m1.begin(); ite != m1.end(); ite++) {
                std::cout << ite->first << ": " << ite->second << std::endl;
            }
            std::cout << std::endl;

            break;
        }
        case 4: {

            container_merger<std::vector<int>, std::set<int>> cm;
            cm.mergeCpp98StyleSequenceContainers(v, s);

            std::cout << "Result container:" << std::endl;
            for (auto ite=v.begin(); ite != v.end(); ite++) {
                std::cout << *ite << " ";
            }
            std::cout << std::endl;

            break;
        }
        case 5: {

            container_merger<std::unordered_set<int>, std::list<int>> cm;
            cm.mergeSetBasedAssociativeContainers(us, l);

            std::cout << "Result container:" << std::endl;
            for (auto ite=us.begin(); ite != us.end(); ite++) {
                std::cout << *ite << " ";
            }
            std::cout << std::endl;

            break;
        }

        case 6: {

            container_merger<std::map<int, int>, std::vector<int>> cm;
            cm.mergeCpp98SeqContIntoMapBasedAssocCont(m1, v);

            std::cout << "Result container:" << std::endl;
            for (auto ite=m1.begin(); ite != m1.end(); ite++) {
                std::cout << ite->first << ": " << ite ->second << std::endl;
            }
            std::cout << std::endl;

            break;
        }

        case 7: {

            container_merger<std::list<int>, std::unordered_map<int, int>> cm;
            cm.mergeMapBasedAssocContIntoCpp98SeqCont(l, m2);

            std::cout << "Result container:" << std::endl;
            for (auto ite=l.begin(); ite != l.end(); ite++) {
                std::cout << *ite << " ";
            }
            std::cout << std::endl;

            break;
        }
        default: std::cout << "Invalid answer!" << std::endl;
    }

    return 0;
}