//
// Created by timo on 22.09.18.
//

#include <iostream>
#include "fraction.h"

using namespace std;


void staticExample(){
    cout << "Welcome! The following example is based on the following two fractions:" << endl;

    fraction fr1 = fraction(12, 9);
    fraction fr2 = fraction(7, 3);

    cout << "fraction 1: " << fr1 << endl;
    cout << "fraction 2: " << fr2 << endl;

    cout << endl;

    cout << "Addition: " << endl;
    cout << fr1 << " + " << fr2 << " = " << fr1 + fr2 << endl;

    cout << endl;


    cout << "Subtraction: " << endl;
    cout << fr1 << " - " << fr2 << " = " << fr1 - fr2 << endl;

    cout << endl;

    cout << "Addition: " << endl;
    cout << fr1 << " + " << fr2 << " = " << fr1 + fr2 << endl;

    cout << endl;

    cout << "Multiplication: " << endl;
    cout << fr1 << " * " << fr2 << " = " << fr1 * fr2 << endl;

    cout << endl;

    cout << "Division: " << endl;
    cout << fr1 << " / " << fr2 << " = " << fr1 / fr2 << endl;
}


void interactiveExample(char operation){
    fraction fr1;
    fraction fr2;

    cout << "Please, enter a 1st fraction in format (int/int): ";
    cin >> fr1;
    cout << "Please, enter a 2nd fraction: in format (int/int): ";
    cin >> fr2;
    cout << endl;
    cout << "1st fraction: " << fr1 << endl;
    cout << "2nd fraction: " << fr2 << endl;
    cout << endl;
    cout << "Operation result: " << endl;
    cout << endl;

    switch(operation) {
        case 'a':
            cout << fr1 << " + " << fr2 << " = " << fr1 + fr2 << endl;
            break;

        case 's':
            cout << fr1 << " - " << fr2 << " = " << fr1 - fr2 << endl;
            break;

        case 'm':
            cout << fr1 << " * " << fr2 << " = " << fr1 * fr2 << endl;
            break;

        case 'd':
            cout << fr1 << " / " << fr2 << " = " << fr1 / fr2 << endl;
            break;

        default: cout << "Unknown operation, please specify next time." << endl;
    }
}

void printDisclaimer() {
    cout << "Welcome to the fraction calculator!" << endl;
    cout << endl;
    cout << "Usage: " << endl;
    cout << "-   For running a static demonstration, enter param 's'." << endl;
    cout << "-   For running an demonstration example, enter param 'i' as well as a 2nd param for the operation, i.e. "
            "'a' for addition, 's' for subtraction, 'm' for multiplication and 'd' for division." << endl;
    cout << endl;
    cout <<"Examples: "<< endl;
    cout <<" - $ ./1.1fractionType s"<< endl;
    cout <<" - $ ./1.1fractionType i m"<< endl;
    cout << endl;
}

int main(int argc, char** argv) {

    if(argc > 1) {
        switch (*argv[1]) {
            case 's':
                staticExample();
                break;
            case 'i':
                interactiveExample(*argv[2]);
                break;
            default: printDisclaimer();
        }
    }

    if(argc == 1) printDisclaimer();
    return 0;
};
