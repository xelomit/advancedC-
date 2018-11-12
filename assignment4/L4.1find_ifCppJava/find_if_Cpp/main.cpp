#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>

std::string value = "foo";

bool match (std::string &elem){

    return elem == value;

}

int main() {

    std::vector<std::string> vector;

    auto startTime = std::chrono::high_resolution_clock::now();

    for(int i = 0; i<10000000; i++) {

        if (i == 9999999) {

            vector.push_back(value);

        } else {

            vector.push_back("bar");

        }

    }

    auto ite = std::find_if(vector.begin(), vector.end(), match);

    auto endTime = std::chrono::high_resolution_clock::now();

    double totalTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime-startTime).count();
    double totalTimeSec = totalTime/1000000000;

    std::cout << "Total run time in seconds: " << totalTimeSec << std::endl;


    if (ite == vector.end()) {

        std::cout << "Element \"" << value << "\" not found!" << std::endl;

    } else {

        std::cout << "Found element: \"" << *ite << "\"" << std::endl;

    }

    return 0;
}