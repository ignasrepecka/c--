#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <limits>
#include "studentai.h"
#include "sortStudents.h"
#include "failas.h"
#include "calculateStatistics.h"
#include "printResults.h"

using namespace std;

int main() {
    srand(time(0));
    int n;
    cout << "Kiek studentų?: ";
    cin >> n;

    int b;
    cout << "Ką pasirinksite?: 1 - Įvesti ranka, 2 - Generuoti atsitiktinai, 3 - Skaityti is failo: ";
    cin >> b;

    int a;
    cout << "Ką pasirinksite?: 1 - Vidurkis, 2 - Mediana: ";
    cin >> a;

    vector<Studentas> studentai;

    try {
        if (b == 1) {
            ivestiStudentus(n, a);
        } else if (b == 2) {
            generuoti(n, a);
        } else if (b == 3) {
            isFailo(studentai, a);
        } else {
            throw runtime_error("Neteisingas pasirinkimas");
        }
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }

    return 0;
}
