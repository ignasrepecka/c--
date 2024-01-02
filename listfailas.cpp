#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <chrono>  // Include the chrono library
#include "listfailas.h"
#include "listCalculateStatistics.h"
#include "listSortStudents.h"
#include "listStrat.h"

using namespace std;
using namespace std::chrono;  // Use the chrono namespace

void listIsFailo(std::list<Studentasl>& studentail, int a, const string& filename) {
    std::list<Studentasl> vargsiukai;
    std::list<Studentasl> kietiakai;
    studentail.clear();  // Clear the list
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

        list<int> balai;
        int j;

        for(int i = 0; i < 3; i++) {
            iss >> j;
            balai.push_back(j);
        }
        // Read the exam score
        int egz;
        iss >> egz;

        Studentasl studentasl;
        studentasl.vardas = vardas;
        studentasl.pavarde = pavarde;
        studentasl.balai = balai;
        studentasl.egz = egz;

        listCalculateStatistics(studentasl);
        studentail.push_back(studentasl);
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
    std::cout << "Kokia Strategija naudoti?: 1 - Strategija1, 2 - Strategija2: ";
    std::cin >> Strat;

    int sortOption;
    std::cout << "Kaip norite rusiuoti studentus?: 1 - Pagal varda, 2 - Pagal pavarde, 3 - Pagal vidurki, 4 - Pagal mediana: ";
    std::cin >> sortOption;

    listStrat(studentail, a, Strat, sortOption, kietiakai, vargsiukai);

    // Start timing
    start = high_resolution_clock::now();

    int size = (Strat == 1) ? studentail.size() : (studentail.size() + vargsiukai.size());

    // Split the students into two files
    ofstream failas1("kietiakai" + to_string(size) + ".txt");
    ofstream failas2("vargsiukai" + to_string(size) + ".txt");

    list<Studentasl>& target = (Strat == 1) ? kietiakai : studentail;

    for (const Studentasl& studentasl : target) {
        failas1 << studentasl.vardas << "\t" << studentasl.pavarde << "\t";
        if (a == 1) {
            failas1 << studentasl.vidurkis << endl;
        } else if (a == 2) {
            failas1 << studentasl.mediana << endl;
        }
    }
    for (const Studentasl& studentasl : vargsiukai) {
        failas2 << studentasl.vardas << "\t" << studentasl.pavarde << "\t";
            if (a == 1) {
        failas2 << studentasl.vidurkis << endl;
            } else if (a == 2) {
        failas2 << studentasl.mediana << endl;
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
