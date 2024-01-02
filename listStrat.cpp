#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include "listStrat.h"
#include "listCalculateStatistics.h"
#include "listSortStudents.h"

using namespace std;
using namespace std::chrono;

void listStrat(std::list<Studentasl>& studentail, int a, int Strat, int sortOption, std::list<Studentasl>& kietiakai, std::list<Studentasl>& vargsiukai) {
        if (Strat==1){
        auto start = high_resolution_clock::now();
        for (const Studentasl& studentasl : studentail) {
            if (a == 1) {
                if (studentasl.vidurkis >= 5) {
                    kietiakai.push_back(studentasl);
                } else {
                    vargsiukai.push_back(studentasl);
                }
            } else if (a == 2) {
                if (studentasl.mediana >= 5) {
                    kietiakai.push_back(studentasl);
                } else {
                    vargsiukai.push_back(studentasl);
                }
            }
        }


        listSortStudents(kietiakai, sortOption);
        listSortStudents(vargsiukai, sortOption);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        std::cout << "Rusiavimas";
        std::cout << std::endl;
        std::cout << "Trukme: "
            << duration.count() << " microseconds" << std::endl;
        } else if (Strat==2) {
        auto start = high_resolution_clock::now();
        studentail.erase(std::remove_if(studentail.begin(), studentail.end(), [&](const Studentasl& studentasl){
            bool isVargsiukas = (a == 1 && studentasl.vidurkis < 5) || (a == 2 && studentasl.mediana < 5);
            if (isVargsiukas) {
                vargsiukai.push_back(studentasl);
            }
            return isVargsiukas;
        }), studentail.end());

        listSortStudents(studentail, sortOption);
        listSortStudents(vargsiukai, sortOption);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        std::cout << "Rusiavimas";
        std::cout << std::endl;
        std::cout << "Trukme: "
            << duration.count() << " microseconds" << std::endl;

        } else {
        auto start = high_resolution_clock::now();

        auto partitionPoint = std::partition(studentail.begin(), studentail.end(), [&](const Studentasl& studentasl){
            return (a == 1 && studentasl.vidurkis >= 5) || (a == 2 && studentasl.mediana >= 5);
        });

        std::copy(partitionPoint, studentail.end(), std::back_inserter(vargsiukai));
        studentail.erase(partitionPoint, studentail.end());

        listSortStudents(studentail, sortOption);
        listSortStudents(vargsiukai, sortOption);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        std::cout << "Rusiavimas" << std::endl;
        std::cout << "Trukme: " << duration.count() << " microseconds" << std::endl;
        }
}
