#ifndef CALCULATESTATISTICS_H_INCLUDED
#define CALCULATESTATISTICS_H_INCLUDED

#include <vector>
#include <string>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> balai;
    double vidurkis;
    double mediana;
};

void calculateStatistics(Studentas& studentas);

#endif // CALCULATESTATISTICS_H_INCLUDED
