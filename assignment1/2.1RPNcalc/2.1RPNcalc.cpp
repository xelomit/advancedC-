//
// Created by timo on 25.09.18.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline double mymin(double a, double b) {
    return a<b ? a : b;
}

int main(){
    vector<double> vectorStack = {};
    bool quit = false;

    while (!quit){

        string input;
        cin >> input;

        if(input == "q") {
            quit = true;
        } else if (input.substr(0,1) == "n") {

            double number = stod(input.substr(1, input.size()));
            vectorStack.push_back(number);

        } else if (input == "d") {

            vectorStack.pop_back();

        } else if (input == "+") {

            double a = vectorStack[vectorStack.size()-1];
            vectorStack.pop_back();
            double b = vectorStack[vectorStack.size()-1];
            vectorStack.pop_back();

            vectorStack.push_back(a+b);

        } else if (input == "-") {

            double a = vectorStack[vectorStack.size()-1];
            vectorStack.pop_back();
            double b = vectorStack[vectorStack.size()-1];
            vectorStack.pop_back();

            vectorStack.push_back(b-a);

        } else if (input == "*") {

            double a = vectorStack[vectorStack.size()-1];
            vectorStack.pop_back();
            double b = vectorStack[vectorStack.size()-1];
            vectorStack.pop_back();

            vectorStack.push_back(a*b);

        } else if (input == "/") {

            double a = vectorStack[vectorStack.size()-1];
            vectorStack.pop_back();
            double b = vectorStack[vectorStack.size()-1];
            vectorStack.pop_back();

            vectorStack.push_back(b/a);

        } else if(input == "min") {
            double a = vectorStack[vectorStack.size()-1];
            vectorStack.pop_back();
            double b = vectorStack[vectorStack.size()-1];
            vectorStack.pop_back();

            vectorStack.push_back(mymin(a, b));

        }

        cout << "stack:  " << endl;

        for (int i = 0; i < vectorStack.size(); i++) {
            cout << vectorStack[i] << endl;
        }

    }
    return 0;
}
