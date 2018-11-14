#include <iostream>
#include <vector>

#include "counting_iterator.h"

using namespace std;

void print(int i) {  cout << i << endl;  }

int main() {

    cout << "vector with elements [10, 20)" << endl;
    // How does this sense the input value type of counter([...])?
    vector<int> v(counter(10), counter(20));
    for (auto ite : v) print(ite);

    cout << "\nprint [20, 30):" << endl;
    for_each(counter(20), counter(30), print);

    return 0;

}