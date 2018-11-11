#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

std::string value = "foo";

bool match (std::string &elem){

    return elem == value;

}

int main() {

    std::vector<std::string> vector;


    for(int i = 0; i<10000000; i++) {

        if (i == 9999999) {

            vector.push_back(value);

        } else {

            vector.push_back("bar");

        }

    }

    auto ite = std::find_if(vector.begin(), vector.end(), match);

    if (ite == vector.end()) {

        std::cout << "Element \"" << value << "\" not found!" << std::endl;

    } else {

        std::cout << "Found element: \"" << *ite << "\"" << std::endl;

    }

    return 0;
}