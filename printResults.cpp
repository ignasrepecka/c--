#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "printResults.h"

using namespace std;

bool compareByMedian(const Studentas& a, const Studentas& b) {
    return a.mediana < b.mediana;
}

bool compareByAverage(const Studentas& a, const Studentas& b) {
    return a.vidurkis < b.vidurkis;
}

void printResults(vector<Studentas>& studentai, int a) {
    // Sort the students by average or median
    if (a == 1) {
        sort(studentai.begin(), studentai.end(), compareByAverage);
    } else if (a == 2) {
        sort(studentai.begin(), studentai.end(), compareByMedian);
    }

    // Print the header
    cout << setw(15) << left << "Vardas"
         << setw(15) << left << "Pavade"
         << setw(15) << left << "Vid/Med:"
         << endl;
    cout << "------------------------------------------------------------------" << endl;

    for(Studentas& studentas : studentai) {
        if (a == 1) {
            cout << setw(15) << left << studentas.vardas
                 << setw(15) << left << studentas.pavarde
                 << setw(15) << left << fixed << setprecision(2) << studentas.vidurkis << endl;
        } else if (a == 2) {
            cout << setw(15) << left << studentas.vardas
                 << setw(15)<< left << studentas.pavarde
                 << setw(15) << left << studentas.mediana << endl;
        } else {
            throw runtime_error("Neteisingas pasirinkimas a");
        }
    }
}
