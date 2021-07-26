#ifndef MYTONATASKS_B_H
#define MYTONATASKS_B_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void printArray(const std::vector<int> &v) {
    for(const auto &i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void solveSecondTask() {
    std::vector<int> A(10);
    std::vector<int> B(10);
    long lTime = time(nullptr);
    std::srand(lTime);
    for (auto &i : A) {
        i = std::rand() % 1000;
    }
    for (auto &i : B) {
        i = std::rand() % 1000;
    }

    std::cout << "First array\n";
    printArray(A);
    std::cout << "Second array\n";
    printArray(B);
    std::vector<int> C(A.begin(), A.end());
    C.insert(C.end(), B.begin(), B.end());
    std::sort(C.begin(), C.end());

    std::cout << "Sorted array\n";
    printArray(C);
    std::cout << "Minimal number in array " << C.front() << '\n';
    std::cout << "Maximal number in array " << C.back() << '\n';

    double midValue = 1;
    double degree = 1 / (double) C.size();
    for (const auto &i : C) {
        midValue *= std::pow(i, degree);
    }
    std::cout << "Geometric mean " << midValue << '\n';
}

#endif