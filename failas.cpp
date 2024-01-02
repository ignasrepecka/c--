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

    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakai;

    int Strat;
    std::cout << "Kokia Strategija naudoti?: 1 - Strategija1, 2 - Strategija2: ";
    std::cin >> Strat;

    int sortOption;
    std::cout << "Kaip norite rusiuoti studentus?: 1 - Pagal varda, 2 - Pagal pavarde, 3 - Pagal vidurki, 4 - Pagal mediana: ";
    std::cin >> sortOption;

    if (Strat==1){
        for (const Studentas& studentas : studentai) {
            if (a == 1) {
                if (studentas.vidurkis >= 5) {
                    kietiakai.push_back(studentas);
                } else {
                    vargsiukai.push_back(studentas);
                }
            } else if (a == 2) {
                if (studentas.mediana >= 5) {
                    kietiakai.push_back(studentas);
                } else {
                    vargsiukai.push_back(studentas);
                }
            }
        }
        start = high_resolution_clock::now();

        sortStudents(kietiakai, sortOption);
        sortStudents(vargsiukai, sortOption);

        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);

        std::cout << "Rusiavimas";
        std::cout << std::endl;
        std::cout << "Trukme: "
            << duration.count() << " microseconds" << std::endl;
    } else {
        studentai.erase(std::remove_if(studentai.begin(), studentai.end(), [&](const Studentas& studentas) {
            bool isVargsiukas = (a == 1 && studentas.vidurkis < 5) || (a == 2 && studentas.mediana < 5);
            if (isVargsiukas) {
                vargsiukai.push_back(studentas);
            }
            return isVargsiukas;
        }), studentai.end());
        start = high_resolution_clock::now();

        sortStudents(studentai, sortOption);
        sortStudents(vargsiukai, sortOption);

        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);

        std::cout << "Rusiavimas";
        std::cout << std::endl;
        std::cout << "Trukme: "
            << duration.count() << " microseconds" << std::endl;

    }

    // Start timing
    start = high_resolution_clock::now();

    int size = (Strat == 1) ? studentai.size() : (studentai.size() + vargsiukai.size());

    // Write the students to files
    ofstream failas1("kietiakai" + to_string(size) + ".txt");
    ofstream failas2("vargsiukai" + to_string(size) + ".txt");

    vector<Studentas>& target = (Strat == 1) ? kietiakai : studentai;

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
