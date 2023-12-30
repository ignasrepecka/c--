#include "generateFile.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void generateFile(int n, int fileNum) {
    string filename = "studentai" + to_string(n) + ".txt";
    ofstream failas(filename);
    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo" << endl;
        exit(1);
    }

    // Write the header
    failas << "Vardas\tPavarde\tND1\tND2\tEgz." << endl;

    for (int i = 1; i <= n; ++i) {
        failas << "Vardas" << i << "\tPavarde" << i;
        for (int j = 0; j < 2; ++j) {
            failas << "\t" << rand() % 10 + 1;
        }
        failas << "\t" << rand() % 10 + 1 << endl;  // Exam score
    }

    failas.close();
}
