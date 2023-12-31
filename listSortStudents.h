#ifndef LISTSORTSTUDENTS_H
#define LISTSORTSTUDENTS_H

#include "Studentai.h"
#include <list>

bool compareByName(const Studentasl& a, const Studentasl& b);
bool compareBySurname(const Studentasl& a, const Studentasl& b);
bool compareByAverage(const Studentasl& a, const Studentasl& b);
bool compareByMedian(const Studentasl& a, const Studentasl& b);
void listSortStudents(std::list<Studentasl>& studentail);

#endif
