#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "generuoti.h"

using namespace std;

void generuoti(int n, int a) {
    for(int i = 0; i < n; ++i) {
        string vardas, pavarde;
        vector<int> balai;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Vardas:" ;
        getline(cin, vardas);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Pavardė:" ;
        getline(cin, pavarde);

        int num_results = rand() % 10 + 1;
        for(int j = 0; j < num_results; ++j) {
            balai.push_back(rand() % 10 + 1);
        }

        int egz = rand() % 10 + 1;
        balai.push_back(egz);

        double suma = 0;
        for(int j : balai) {
            suma += j;
        }

        sort(balai.begin(), balai.end());
        double mediana;
        if ((balai.size()) % 2 == 0)
            mediana = (balai[balai.size()/2 - 1] + balai[balai.size()/2]) / 2.0;
        else
            mediana = balai[balai.size()/2];

        if (a == 1) {
            cout << setw(15) << left << vardas << setw(15) << left << pavarde << setw(15) << left << fixed << setprecision(2) << suma/balai.size();
        } else if (a == 2) {
            cout << setw(15) << left << vardas << setw(15)<< left << pavarde << setw(15) << left << mediana;
            cout << endl;
        } else {
            throw runtime_error("Neteisingas pasirinkimas a");
        }
    }
}
