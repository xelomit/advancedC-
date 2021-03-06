//
// Created by timo on 26.11.18.
//

#ifndef L5_1FILELOCKERRPN_RPNCALCULATOR_H
#define L5_1FILELOCKERRPN_RPNCALCULATOR_H

#include <sstream>
#include "pvector.h"

template<typename T>
class RPNCalculator {
    pvector<T> vectorStack;
    bool quit;

public:
    RPNCalculator() : vectorStack("/tmp/RPNVector.txt"), quit(false) {
        if (this->vectorStack.isLocked()) quit = true;
    }

    inline T mymin(T a, T b) {
        return a<b ? a : b;
    }

    void calculate(){
        while (!quit){

            std::cout << "stack:  " << std::endl;

            for (int i = 0; i < vectorStack.size(); i++) {
                std::cout << vectorStack.get(i) << std::endl;
            }

            std::string input;
            std::cin >> input;

            if(input == "q") {
                quit = true;
            } else if (input.substr(0,1) == "n") {
                std::istringstream is(input.substr(1, input.size()));
                T number;
                is >> number;
                vectorStack.push_back(number);

            } else if (input == "d" && vectorStack.size() > 0) {

                vectorStack.pop_back();

            } else if (input == "+" && vectorStack.size() >= 2) {

                T a = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();
                T b = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();

                vectorStack.push_back(a+b);

            } else if (input == "-" && vectorStack.size() >= 2) {

                T a = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();
                T b = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();

                vectorStack.push_back(b-a);

            } else if (input == "*" && vectorStack.size() >= 2) {

                T a = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();
                T b = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();

                vectorStack.push_back(a*b);

            } else if (input == "/" && vectorStack.size() >= 2) {

                T a = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();
                T b = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();

                vectorStack.push_back(b/a);

            } else if(input == "min" && vectorStack.size() >= 2) {
                if(true){
                    T a = vectorStack.get(vectorStack.size()-1);
                    vectorStack.pop_back();
                    T b = vectorStack.get(vectorStack.size()-1);
                    vectorStack.pop_back();

                    vectorStack.push_back(mymin(a, b));
                }
            }
        }
    }
};

#endif //L5_1FILELOCKERRPN_RPNCALCULATOR_H
