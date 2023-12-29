#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <limits>
#include "studentai.h"
#include "failas.h"
#include "calculateStatistics.h"
#include "printResults.h"

using namespace std;

int main() {
    srand(time(0));


    int a;
    cout << "Ką pasirinksite?: 1 - Vidurkis, 2 - Mediana: ";
    cin >> a;

    vector<Studentas> studentai;

    try {

            isFailo(studentai, a);

    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }

    return 0;
}
