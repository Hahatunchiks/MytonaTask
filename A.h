#ifndef MYTONATASKS_A_H
#define MYTONATASKS_A_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

void solveFirstTask() {
    std::string inputString;
    std::string delimiter = " ";
    std::vector<std::string> separatedStrings;

    std::getline(std::cin, inputString);
    std::getline(std::cin, delimiter);

    size_t pos = inputString.find(delimiter, 0);
    size_t begin = 0;
    std::string subString;
    while (pos != std::string::npos) {
        subString = inputString.substr(begin, pos - begin);
        if (!subString.empty()) {
            separatedStrings.push_back(subString);
        }
        begin = pos + delimiter.size();
        pos = inputString.find(delimiter, begin);
    }
    separatedStrings.push_back(inputString.substr(begin, inputString.size() - begin));
    for (const auto &i : separatedStrings) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

#endif //MYTONATASKS_A_H
