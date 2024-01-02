#ifndef SORTSTUDENTS_H
#define SORTSTUDENTS_H

#include "Studentai.h"
#include <vector>

bool compareByName(const Studentas& a, const Studentas& b);
bool compareBySurname(const Studentas& a, const Studentas& b);
bool compareByAverage(const Studentas& a, const Studentas& b);
bool compareByMedian(const Studentas& a, const Studentas& b);
void sortStudents(std::vector<Studentas>& studentai, int sortOption);

#endif
