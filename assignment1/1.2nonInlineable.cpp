//
// Created by timo on 23.09.18.
//

#include <iostream>

using namespace std;

inline int recursiveFactorial(int i) {
    if (i <= 0) {
        return 0;
    } else {
        return i + recursiveFactorial(i-1);
    }

}

int main() {
    int number = 70;
    cout << recursiveFactorial(number) << endl;
    return 0;
}