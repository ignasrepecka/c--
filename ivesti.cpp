#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "ivesti.h"

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> balai;
    double vidurkis;
    double mediana;
};

void ivestiStudentus(int n, int a) {
    vector<Studentas> studentai(n);

    for(int i = 0; i < n; ++i) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Vardas:" ;
        getline(cin, studentai[i].vardas);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Pavardė:" ;
        getline(cin, studentai[i].pavarde);

        cout << "Rezultatai (įveskite ne sveikąjį skaičių, kad sustabdytumėte): ";
        while(true) {
            int j;
            if(!(cin >> j)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            studentai[i].balai.push_back(j);
        }

        int egz;
        cout << "Egzamino rezultatas: ";
        cin >> egz;
        studentai[i].balai.push_back(egz);
        cout << endl;

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

    for(const auto& s : studentai) {
        if (a == 1) {
            cout << setw(15) << left << s.vardas << setw(15) << left << s.pavarde << setw(15) << left << fixed << setprecision(2) << s.vidurkis;
        } else if (a == 2) {
            cout << setw(15) << left << s.vardas << setw(15)<< left << s.pavarde << setw(15) << left << s.mediana;
            cout << endl;
        } else {
            throw runtime_error("Neteisingas pasirinkimas a");
        }
    }
}
