#include <iostream>
#include <vector>
#include "binop.h"

using namespace std;

struct is_less_than_5 : std::unary_function<int, bool>
{
    bool operator ()(int i) const {
        return i < 5;
    }
};

struct is_even : std::unary_function<int, bool>
{
    bool operator ()(int i) const {
        return i % 2 == 0;
    }
};

struct is_both : std::binary_function<int, int, bool>
{
    bool operator ()(bool i, bool j) const {
        return i && j;
    }
};

int main()
{
    auto op = some_function(is_both(), is_less_than_5(), is_even());

    for (int x = 0; x < 10; ++x) {

        cout << "Is both even and less than 5: " << x << ": ";
        if(op(x) == 1) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

    }

    return 0;
}