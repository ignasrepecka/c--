#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "generuoti.h"

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> balai;
    double vidurkis;
    double mediana;
};

void calculateStatistics(Studentas& studentas) {
    double suma = 0;
    for(int j : studentas.balai) {
        suma += j;
    }

    sort(studentas.balai.begin(), studentas.balai.end());
    if ((studentas.balai.size()) % 2 == 0)
        studentas.mediana = (studentas.balai[studentas.balai.size()/2 - 1] + studentas.balai[studentas.balai.size()/2]) / 2.0;
    else
        studentas.mediana = studentas.balai[studentas.balai.size()/2];

    studentas.vidurkis = suma/studentas.balai.size();
}

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

void generuoti(int n, int a) {
    vector<Studentas> studentai(n);

    // First, generate all the student data
    for(int i = 0; i < n; ++i) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Vardas:" ;
        getline(cin, studentai[i].vardas);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Pavardė:" ;
        getline(cin, studentai[i].pavarde);

        int num_results = rand() % 10 + 1;
        for(int j = 0; j < num_results; ++j) {
            studentai[i].balai.push_back(rand() % 10 + 1);
        }

        int egz = rand() % 10 + 1;
        studentai[i].balai.push_back(egz);

        // Calculate statistics for each student
        calculateStatistics(studentai[i]);
    }

    // Then, call the function to sort and print the results
    printResults(studentai, a);
}
