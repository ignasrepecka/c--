#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "calculateStatistics.h"

using namespace std;

void calculateStatistics(Studentas& studentas) {
    double suma = 0;
    for(int j : studentas.balai) {
        suma += j;
    }

    sort(studentas.balai.begin(), studentas.balai.end());
    if ((studentas.balai.size()) % 2 == 0)
        studentas.mediana = (studentas.balai[studentas.balai.size()/2 - 1] + studentas.balai[studentas.balai.size()/2]) / 2.0;
    else
        studentas.mediana = studentas.balai[studentas.balai.size()/2];

    studentas.vidurkis = suma/studentas.balai.size();
}
