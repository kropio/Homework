#ifndef SOLUTION_OF_LAB_H_
#define SOLUTION_OF_LAB_H_
#include "Station.h"
#include "pugixml.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <math.h>

const double DEG_to_KM = 56.76476;

class Solution_of_lab
{
private:
    const char* name_of_file;
public:
    Solution_of_lab(const char*);
    std::vector<Station> parseToStations() const;
    std::vector<std::map<std::string, std::vector<Station>>> parseToRoutes(std::vector<Station>&) const;
    void task1_solution(std::vector<std::map<std::string, std::vector<Station>>>&) const;
    void task2_solution(std::vector<std::map<std::string, std::vector<Station>>>&) const;
    void task3_solution(std::vector<Station>&) const;
};

double lenOfRoute(const std::vector<Station>&);

#endif /* SOLUTIONOFLAB_H_ */
