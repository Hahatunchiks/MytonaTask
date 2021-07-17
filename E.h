#ifndef MYTONATASKS_E_H
#define MYTONATASKS_E_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

double calculateDiscriminant(const int &A, const int &B, const int &C) {
    return std::pow(B, 2) - 4 * A * C;
}

bool calculateT(const int &x, const int &x1, const int &x2, const int &x3, double &t) {
    int A = x1 - 2 * x2 + x3;
    int B = 2 * x2 - 2 * x1;
    int C = x1 - x;
    double D = calculateDiscriminant(A, B, C);
    if (D >= 0) {
        double t1 = (-B + std::sqrt(D)) / (2 * A);
        double t2 = (-B - std::sqrt(D)) / (2 * A);
        if (t1 >= 0 && t1 <= 1) {
            t = t1;
        } else {
            t = t2;
        }
        return true;
    }
    return false;
}

double calculateY(const double &t, const int &y1, const int &y2, const int &y3) {
    double A = 1 - 2 * t - t * t;
    double B = 2 * t - 2 * t * t;
    double C = t * t;
    double res =  A * y1 + B * y2 + C * y3;
    return res;
}

void solveFifthTask() {
    // x = (1-t)^2 * x1 + 2*(1-t)*t*x2 + t^2 * x3;
    int N = 3;
    std::vector<std::pair<int, int>> Coordinates(N);
    std::vector<std::pair<int,double>> integerXCoordinates;
    for (int i = 0; i < N; i++) {
        std::cin >> Coordinates[i].first >> Coordinates[i].second;
    }

    std::sort(Coordinates.begin(), Coordinates.end());
    double t = 0;
    for (int i = Coordinates.front().first; i <= Coordinates.back().first; i++) {
        if (calculateT(i, Coordinates[0].first, Coordinates[1].first, Coordinates[2].first, t)) {
            integerXCoordinates.emplace_back(i, calculateY(t,Coordinates[0].second, Coordinates[1].second, Coordinates[2].second));
        }
    }
    for(const auto &i : integerXCoordinates) {
        std::cout << "x: " << i.first << " y: " << i.second << '\n';
    }
    std::cout << '\n';
}

#endif //MYTONATASKS_E_H