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
#include "strat.h"

using namespace std;
using namespace std::chrono;  // Use the chrono namespace

void isFailo(std::vector<Studentas>& studentai, int a, const string& filename) {
    std::vector<Studentas> vargsiukai;
    std::vector<Studentas> kietiakai;
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

    cout << "Duomenu nuskaitymas is failu";
    cout << endl;
    cout << "Trukme: "
         << duration.count() << " microseconds" << endl;

    failas.close();

    int Strat;
    std::cout << "Kokia Strategija naudoti?: 1 - Strategija1, 2 - Strategija2, 3 - Strategija3: ";
    std::cin >> Strat;

    int sortOption;
    std::cout << "Kaip norite rusiuoti studentus?: 1 - Pagal varda, 2 - Pagal pavarde, 3 - Pagal vidurki, 4 - Pagal mediana: ";
    std::cin >> sortOption;

    strat(studentai, a, Strat, sortOption, kietiakai, vargsiukai);

    // Start timing
    start = high_resolution_clock::now();

    int size = (Strat == 1) or (Strat==3) ? studentai.size() : (studentai.size() + vargsiukai.size());

    // Write the students to files
    ofstream failas1("kietiakai" + to_string(size) + ".txt");
    ofstream failas2("vargsiukai" + to_string(size) + ".txt");

    vector<Studentas>& target = (Strat == 1) or (Strat == 3) ? kietiakai : studentai;

    for (const Studentas& studentas : target) {
        failas1 << studentas.vardas << "\t" << studentas.pavarde << "\t";
        if (a == 1) {
            failas1 << studentas.vidurkis << endl;
        } else if (a == 2) {
            failas1 << studentas.mediana << endl;
        }
    }
    for (const Studentas& studentas : vargsiukai) {
        failas2 << studentas.vardas << "\t" << studentas.pavarde << "\t";
            if (a == 1) {
        failas2 << studentas.vidurkis << endl;
            } else if (a == 2) {
        failas2 << studentas.mediana << endl;
        }
    }
    failas1.close();
    failas2.close();

    // Stop timing and calculate the duration
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout << "Surusiuotu studentu isvedimas i 'kietiakai' ir 'vargsiukai'";
    cout << endl;
    cout << "Trukme: "
         << duration.count() << " microseconds" << endl;
    cout << "--------------------------------------------------------------------------";
    cout << endl;
}
