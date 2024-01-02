#include "listSortStudents.h"
#include <algorithm>
#include <list>
#include <iostream>
#include <chrono>

bool compareByName(const Studentasl& a, const Studentasl& b) {
    return a.vardas < b.vardas;
}

bool compareBySurname(const Studentasl& a, const Studentasl& b) {
    return a.pavarde < b.pavarde;
}

bool compareByAverage(const Studentasl& a, const Studentasl& b) {
    return a.vidurkis < b.vidurkis;
}

bool compareByMedian(const Studentasl& a, const Studentasl& b) {
    return a.mediana < b.mediana;
}

void listSortStudents(std::list<Studentasl>& studentail, int sortOption) {
    switch (sortOption) {
        case 1:
            studentail.sort(compareByName);  // To sort by name
            break;
        case 2:
            studentail.sort(compareBySurname);  // To sort by surname
            break;
        case 3:
            studentail.sort(compareByAverage);  // To sort by average
            break;
        case 4:
            studentail.sort(compareByMedian);  // To sort by median
            break;
        default:
            std::cout << "Netinkamas rūšiavimo pasirinkimas. Prašome pasirinkti nuo 1 iki 4." << std::endl;
            break;
    }
}
