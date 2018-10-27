//
// Created by timo on 27.10.18.
//

#ifndef L3_2RPNCOMPLEX_RPNCALCULATOR_H
#define L3_2RPNCOMPLEX_RPNCALCULATOR_H

#include <complex>
#include <sstream>
#include "pvector.h"

template<typename T, typename C=pvector<T>>
class RPNCalculator {
    C vectorStack;
    bool quit;

public:
    RPNCalculator() : vectorStack("/tmp/RPNcomplex.txt"), quit(false) {
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

template<typename T>
class RPNCalculator<std::complex<T>> {
    pvector<std::complex<T>> vectorStack;
    bool quit;

public:
    RPNCalculator() : vectorStack("/tmp/RPNcomplex.txt"), quit(false) { }

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
                std::complex<T> number;
                is >> number;
                vectorStack.push_back(number);

            } else if (input == "d" && vectorStack.size() > 0) {

                vectorStack.pop_back();

            } else if (input == "+" && vectorStack.size() >= 2) {

                std::complex<T> a = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();
                std::complex<T> b = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();

                vectorStack.push_back(a+b);

            } else if (input == "-" && vectorStack.size() >= 2) {

                std::complex<T> a = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();
                std::complex<T> b = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();

                vectorStack.push_back(b-a);

            } else if (input == "*" && vectorStack.size() >= 2) {

                std::complex<T> a = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();
                std::complex<T> b = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();

                vectorStack.push_back(a*b);

            } else if (input == "/" && vectorStack.size() >= 2) {

                std::complex<T> a = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();
                std::complex<T> b = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();

                vectorStack.push_back(b/a);

            } else if (input == "conj" && vectorStack.size() > 0){

                std::complex<T> temp = conj(vectorStack.get(vectorStack.size()-1));
                vectorStack.pop_back();
                vectorStack.push_back(temp);

            }
        }
    }
};


#endif //L3_2RPNCOMPLEX_RPNCALCULATOR_H
