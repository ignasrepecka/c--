#include "sortStudents.h"
#include <algorithm>

bool compareByName(const Studentas& a, const Studentas& b) {
    return a.vardas < b.vardas;
}

bool compareBySurname(const Studentas& a, const Studentas& b) {
    return a.pavarde < b.pavarde;
}

void sortStudents(std::vector<Studentas>& studentai, bool sortByName) {
    if (sortByName) {
        std::sort(studentai.begin(), studentai.end(), compareByName);  // To sort by name
    } else {
        std::sort(studentai.begin(), studentai.end(), compareBySurname);  // To sort by surname
    }
}
