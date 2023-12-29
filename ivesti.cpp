#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "calculateStatistics.h" // Include this
#include "printResults.h" // Include this

using namespace std;

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

        // Call calculateStatistics function for each student
        calculateStatistics(studentai[i]);
    }

    // Call printResults function to print the results
    printResults(studentai, a);
}
