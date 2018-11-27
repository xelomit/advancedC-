#include <iostream>
#include "gcd_meta.h"
#include "fibonacci_meta.h"

using namespace std;

int main() {
    cout << endl << "gcd_meta<12, 18>::gcd == " << gcd_meta<12, 18>::gcd << endl << endl;
    cout << "fibonacci_meta<10>::fib == " << fibonacci_meta<10>::fib << endl;

    return 0;
}