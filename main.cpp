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
            int fileNum;
            cout << "Kiek failų norite generuoti?: ";
            cin >> fileNum;

            for (int i = 1; i <= fileNum; ++i) {
                int n;
                cout << "Kiek studentų bus " << i << "-ajame faile?: ";
                cin >> n;
                generateFile(n, i);
            }
        } else {
            int fileNum;
            cout << "Kiek failų norite skaityti?: ";
            cin >> fileNum;

            for (int i = 1; i <= fileNum; ++i) {
                int n;
                cout << "Kiek studentų yra " << i << "-ajame faile?: ";
                cin >> n;
                string filename = "C:\\Users\\Administrator\\Desktop\\cc++++\\v0.2\\studentai" + to_string(n) + ".txt";
                isFailo(studentai, a, filename);
            }
        }
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }

    return 0;
}
