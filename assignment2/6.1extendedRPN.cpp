//
// Created by timo on 18.10.18.
//
#include <iostream>
//#include <vector>
#include <string>
//#include"fraction.h"
#include"pvector.h"

using namespace std;

inline double mymin(double a, double b) {
    return a<b ? a : b;
}

class RPNCalculator {
    pvector<double> vectorStack;
    bool quit;

public:
    RPNCalculator() : vectorStack("/tmp/RPNVector.txt"), quit(false) {
      //Why is 'vectorStack = pvector<double>("/tmp/RPNVector.txt");' not possible here?
      //quit = false;
    }

    void calculate(){
      while (!quit){

          cout << "stack:  " << endl;

          for (int i = 0; i < vectorStack.size(); i++) {
              cout << vectorStack.get(i) << endl;
          }

          string input;
          cin >> input;

          if(input == "q") {
              quit = true;
          } else if (input.substr(0,1) == "n") {

              double number = stod(input.substr(1, input.size()));
              vectorStack.push_back(number);

          } else if (input == "d") {

              vectorStack.pop_back();

          } else if (input == "+" && vectorStack.size() >= 2) {

              double a = vectorStack.get(vectorStack.size()-1);
              vectorStack.pop_back();
              double b = vectorStack.get(vectorStack.size()-1);
              vectorStack.pop_back();

              vectorStack.push_back(a+b);

          } else if (input == "-" && vectorStack.size() >= 2) {

              double a = vectorStack.get(vectorStack.size()-1);
              vectorStack.pop_back();
              double b = vectorStack.get(vectorStack.size()-1);
              vectorStack.pop_back();

              vectorStack.push_back(b-a);

          } else if (input == "*" && vectorStack.size() >= 2) {

              double a = vectorStack.get(vectorStack.size()-1);
              vectorStack.pop_back();
              double b = vectorStack.get(vectorStack.size()-1);
              vectorStack.pop_back();

              vectorStack.push_back(a*b);

          } else if (input == "/" && vectorStack.size() >= 2) {

              double a = vectorStack.get(vectorStack.size()-1);
              vectorStack.pop_back();
              double b = vectorStack.get(vectorStack.size()-1);
              vectorStack.pop_back();

              vectorStack.push_back(b/a);

          } else if(input == "min" && vectorStack.size() >= 2) {
              if(true){
                double a = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();
                double b = vectorStack.get(vectorStack.size()-1);
                vectorStack.pop_back();

                vectorStack.push_back(mymin(a, b));
              }
          }
    }
  }
};

int main(){
    RPNCalculator calc;
    calc.calculate();
    return 0;
}
