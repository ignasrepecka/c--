#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <chrono>  // Include the chrono library
#include "failas.h"
#include "calculateStatistics.h"
#include "sortStudents.h"

using namespace std;
using namespace std::chrono;  // Use the chrono namespace

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

    // Start timing
    auto start = high_resolution_clock::now();

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

    // Stop timing and calculate the duration
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Duomenu nuskaitymas is failu trukme: "
         << duration.count() << " microseconds" << endl;
    cout << endl;

    failas.close();


    sortStudents(studentai);

    // Start timing
    start = high_resolution_clock::now();

    // Split the students into two files
    ofstream failas1("kietiakai" + to_string(studentai.size()) + ".txt");
    ofstream failas2("vargsiukai" + to_string(studentai.size()) + ".txt");
    for (const Studentas& studentas : studentai) {
        if (a == 1) {
            if (studentas.vidurkis >= 5) {
                failas1 << studentas.vardas << "\t" << studentas.pavarde << "\t" << studentas.vidurkis << endl;
            } else {
                failas2 << studentas.vardas << "\t" << studentas.pavarde << "\t" << studentas.vidurkis << endl;
            }
        } else if (a == 2) {
            if (studentas.mediana >= 5) {
                failas1 << studentas.vardas << "\t" << studentas.pavarde << "\t" << studentas.mediana << endl;
            } else {
                failas2 << studentas.vardas << "\t" << studentas.pavarde << "\t" << studentas.mediana << endl;
            }
        }
    }
    failas1.close();
    failas2.close();

        // Stop timing and calculate the duration
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout << "Surusiuotų studentu isvedimas i 'kietiakai' ir 'vargsiukai' trukme: "
         << duration.count() << " microseconds" << endl;
    cout << endl;
}
