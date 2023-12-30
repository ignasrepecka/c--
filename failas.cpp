#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include "failas.h"
#include "calculateStatistics.h"
#include "printResults.h"

using namespace std;

void isFailo(std::vector<Studentas>& studentai, int a, const string& filename) {
    studentai.clear();  // Clear the vector
    ifstream failas(filename);
    if (!failas.is_open()) {
        throw runtime_error("Nepavyko atidaryti failo");
    }

    // Skip the header line
    string header;
    getline(failas, header);

    string line;
    while (getline(failas, line)) {
        istringstream iss(line);
        string vardas, pavarde;
        iss >> vardas >> pavarde;

        vector<int> balai;
        int j;
        // Read 15 homework scores
        for(int i = 0; i < 3; i++) {
            iss >> j;
            balai.push_back(j);
        }
        // Read the exam score
        int egz;
        iss >> egz;

        Studentas studentas;
        studentas.vardas = vardas;
        studentas.pavarde = pavarde;
        studentas.balai = balai;
        studentas.egz = egz;

        calculateStatistics(studentas);
        studentai.push_back(studentas);
    }
    failas.close();

    // Split the students into two files
    ofstream failas1("kietiakai" + to_string(studentai.size()) + ".txt");
    ofstream failas2("vargsiukai" + to_string(studentai.size()) + ".txt");
    for (const Studentas& studentas : studentai) {
        if (studentas.vidurkis >= 5) {
            failas1 << studentas.vardas << "\t" << studentas.pavarde << "\t" << studentas.vidurkis << endl;
        } else {
            failas2 << studentas.vardas << "\t" << studentas.pavarde << "\t" << studentas.vidurkis << endl;
        }
    }
    failas1.close();
    failas2.close();

    printResults(studentai, a);
}
