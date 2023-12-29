#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "printResults.h"

using namespace std;

void printResults(vector<Studentas>& studentai, int a) {
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
