#ifndef MYTONATASKS_D_H
#define MYTONATASKS_D_H
#include <iostream>
#include <fstream>
#include <algorithm>

void solveFourthTask() {
    std::fstream file("input.txt", std::ios_base::in | std::ios_base::out);
    std::ofstream newFile("helpFile.txt");
    if (newFile.is_open()) {
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                line.erase(
                        std::remove_if(line.begin(), line.end(),
                                       [](char x) { return std::isspace(x) || std::isdigit(x); }), line.end());
                newFile << line << '\n';
            }
            newFile.close();
            file.close();
            std::remove("input.txt");
            std::rename("helpFile.txt", "input.txt");
        } else {
            std::cerr << "No input file\n";
        }
    } else {
        std::cerr << "Program is crushed\n";
    }
}

#endif //MYTONATASKS_D_H
