#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <limits>
#include <fstream>
#include "studentai.h"
#include "failas.h"
#include "calculateStatistics.h"
#include "printResults.h"
#include "generateFile.h"

using namespace std;

int main() {
    srand(time(0));

    int a;
    cout << "Ką pasirinksite?: 1 - Vidurkis, 2 - Mediana, 3 - Generuoti failus: ";
    cin >> a;

    vector<Studentas> studentai;

    try {
        if (a == 3) {
            int n;
            cout << "Kiek studentu?: ";
            cin >> n;
            generateFile(n);
        } else {
            isFailo(studentai, a);
        }
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }

    return 0;
}
