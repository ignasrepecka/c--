#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include "strat.h"
#include "calculateStatistics.h"
#include "sortStudents.h"

using namespace std;
using namespace std::chrono;

void strat(std::vector<Studentas>& studentai, int a, int Strat, int sortOption, std::vector<Studentas>& kietiakai, std::vector<Studentas>& vargsiukai) {
        if (Strat==1){
        auto start = high_resolution_clock::now();
        for (const Studentas& studentas : studentai) {
            if (a == 1) {
                if (studentas.vidurkis >= 5) {
                    kietiakai.push_back(studentas);
                } else {
                    vargsiukai.push_back(studentas);
                }
            } else if (a == 2) {
                if (studentas.mediana >= 5) {
                    kietiakai.push_back(studentas);
                } else {
                    vargsiukai.push_back(studentas);
                }
            }
        }

        sortStudents(kietiakai, sortOption);
        sortStudents(vargsiukai, sortOption);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        std::cout << "Rusiavimas";
        std::cout << std::endl;
        std::cout << "Trukme: "
            << duration.count() << " microseconds" << std::endl;
        } else if (Strat==2) {
        auto start = high_resolution_clock::now();
        studentai.erase(std::remove_if(studentai.begin(), studentai.end(), [&](const Studentas& studentas) {
            bool isVargsiukas = (a == 1 && studentas.vidurkis < 5) || (a == 2 && studentas.mediana < 5);
            if (isVargsiukas) {
                vargsiukai.push_back(studentas);
            }
            return isVargsiukas;
            }), studentai.end());

            sortStudents(studentai, sortOption);
            sortStudents(vargsiukai, sortOption);

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);

            std::cout << "Rusiavimas";
            std::cout << std::endl;
            std::cout << "Trukme: "
                << duration.count() << " microseconds" << std::endl;

        } else {
        auto start = high_resolution_clock::now();
            auto it = std::partition(studentai.begin(), studentai.end(), [a](const Studentas& studentas) {
                if (a == 1) {
                    return studentas.vidurkis >= 5;
                } else if (a == 2) {
                    return studentas.mediana >= 5;
                }
                return false;
            });

        kietiakai.assign(studentai.begin(), it);
        vargsiukai.assign(it, studentai.end());

        sortStudents(kietiakai, sortOption);
        sortStudents(vargsiukai, sortOption);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        std::cout << "Rusiavimas";
        std::cout << std::endl;
        std::cout << "Trukme: "
            << duration.count() << " microseconds" << std::endl;
        }
}
