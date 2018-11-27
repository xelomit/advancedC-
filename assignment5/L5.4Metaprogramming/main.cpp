#include <iostream>
#include "gcd_meta.h"
#include "fibonacci_meta.h"

using namespace std;

int main() {
    cout << "gcd_meta<12, 18>::gcd == " << gcd_meta<12, 18>::gcd << endl;
    return 0;
}