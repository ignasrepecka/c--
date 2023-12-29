#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "calculateStatistics.h" // Include this
#include "printResults.h"
#include "generuoti.h"

using namespace std;

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
