#include <complex>
#include "fraction.h"
#include "RPNCalculator.h"

int main(){
    RPNCalculator<std::complex<double>> calc;
    calc.calculate();
    return 0;
}