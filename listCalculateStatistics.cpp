#include <iostream>
#include <list>
#include <string>
#include <limits>
#include <iomanip>
#include <stdexcept>
#include "listCalculateStatistics.h"

using namespace std;

void listCalculateStatistics(Studentasl& studentasl) {
    double suma = 0;
    for(int j : studentasl.balai) {
        suma += j;
    }

    studentasl.balai.sort();
    auto it = studentasl.balai.begin();
    advance(it, studentasl.balai.size() / 2);
    if ((studentasl.balai.size()) % 2 == 0) {
        int val1 = *it;
        --it;
        int val2 = *it;
        studentasl.mediana = (val1 + val2) / 2.0;
    } else {
        studentasl.mediana = *it;
    }

    studentasl.vidurkis = suma/studentasl.balai.size();
}
