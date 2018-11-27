#include <iostream>
#include "gcd_meta.h"
#include "fibonacci_meta.h"

using namespace std;

int main() {

    gcd_constexpr gc;
    fibonacci_constexpr fc;

    cout << endl << "gcd_meta<12, 18>::gcd == " << gcd_meta<12, 18>::gcd << endl << endl;
    cout << "gcd_constexpr::gcd(12, 18) == " << gc.gcd(12, 18) << endl << endl;
    cout << "fibonacci_meta<10>::fib == " << fibonacci_meta<10>::fib << endl << endl;
    cout << "fibonacci_constexpr::fib(10) == " << fc.fib(10) << endl;

    return 0;
}