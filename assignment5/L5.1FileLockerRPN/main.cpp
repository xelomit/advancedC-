#include <iostream>
#include "fraction.h"
#include "RPNCalculator.h"

int main() {

    RPNCalculator<fraction> calc;
    calc.calculate();

    return 0;
}