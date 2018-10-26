//
// Created by timo on 26.10.18.
//

#ifndef INC_6_1EXTENDEDRPN_RPNCALCULATOR_H
#define INC_6_1EXTENDEDRPN_RPNCALCULATOR_H

#include <sstream>
#include "pvector.h"

template<typename T>
class RPNCalculator {
    pvector<T> vectorStack;
    bool quit;

public:
    RPNCalculator() : vectorStack("/tmp/RPNVector.txt"), quit(false) {
        //Why is 'vectorStack = pvector<double>("/tmp/RPNVector.txt");' not possible here?
        //quit = false;
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

#endif //INC_6_1EXTENDEDRPN_RPNCALCULATOR_H