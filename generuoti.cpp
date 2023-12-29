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

void generuoti(int n, int a) {
    vector<Studentas> studentai(n);

    
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

        double suma = 0;
        for(int j : studentai[i].balai) {
            suma += j;
        }

        sort(studentai[i].balai.begin(), studentai[i].balai.end());
        if ((studentai[i].balai.size()) % 2 == 0)
            studentai[i].mediana = (studentai[i].balai[studentai[i].balai.size()/2 - 1] + studentai[i].balai[studentai[i].balai.size()/2]) / 2.0;
        else
            studentai[i].mediana = studentai[i].balai[studentai[i].balai.size()/2];

        studentai[i].vidurkis = suma/studentai[i].balai.size();
    }

   
    for(int i = 0; i < n; ++i) {
        if (a == 1) {
            cout << setw(15) << left << studentai[i].vardas << setw(15) << left << studentai[i].pavarde << setw(15) << left << fixed << setprecision(2) << studentai[i].vidurkis;
        } else if (a == 2) {
            cout << setw(15) << left << studentai[i].vardas << setw(15)<< left << studentai[i].pavarde << setw(15) << left << studentai[i].mediana;
            cout << endl;
        } else {
            throw runtime_error("Neteisingas pasirinkimas a");
        }
    }
}

