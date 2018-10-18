//
// Created by timo on 17.10.18.
//

#include <iostream>

using namespace std;

void c_swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

int main() {

    int x = 1;
    int y = 2;

    cout << "x: " << x << " @" << &x << endl;
    cout << "y: " << y << " @" << &y << endl;

    cout << "c_swap(&x, &y):" << endl;
    c_swap(&x, &y);
    cout << "x: " << x << " @" << &x << endl;
    cout << "y: " << y << " @" << &y << endl;

    cout << "swap(x, y):" << endl;
    swap(x, y);
    cout << "x: " << x << " @" << &x << endl;
    cout << "y: " << y << " @" << &y << endl;

    return 0;
}
