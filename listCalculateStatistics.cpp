#include <iostream>
#include <list>
#include <string>
#include <limits>
#include <iomanip>
#include <stdexcept>
#include "listCalculateStatistics.h"

using namespace std;

void listCalculateStatistics(Studentasl& studentas) {
    double suma = 0;
    for(int j : studentas.balai) {
        suma += j;
    }

    studentas.balai.sort();
    auto it = studentas.balai.begin();
    advance(it, studentas.balai.size() / 2);
    if ((studentas.balai.size()) % 2 == 0) {
        int val1 = *it;
        --it;
        int val2 = *it;
        studentas.mediana = (val1 + val2) / 2.0;
    } else {
        studentas.mediana = *it;
    }

    studentas.vidurkis = suma/studentas.balai.size();
}
