#include "generateFile.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void generateFile(int n) {
    std::ofstream failas("studentai.txt");
    if (!failas.is_open()) {
        std::cerr << "Nepavyko atidaryti failo" << std::endl;
        exit(1);
    }

    // Write the header
    failas << "Vardas\tPavarde\tND1\tND2\tEgz." << std::endl;

    for (int i = 1; i <= n; ++i) {
        failas << "Vardas" << i << "\tPavarde" << i;
        for (int j = 0; j < 2; ++j) {
            failas << "\t" << rand() % 10 + 1;
        }
        failas << "\t" << rand() % 10 + 1 << std::endl;  // Exam score
    }

    failas.close();
}
