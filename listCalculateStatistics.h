#ifndef LISTCALCULATESTATISTICS_H_INCLUDED
#define LISTCALCULATESTATISTICS_H_INCLUDED

#include <list>
#include <string>

struct Studentasl {
    std::string vardas;
    std::string pavarde;
    std::list<int> balai;
    double vidurkis;
    double mediana;
    int egz;
};

void listCalculateStatistics(Studentasl& studentasl);

#endif // LISTCALCULATESTATISTICS_H_INCLUDED
