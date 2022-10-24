//============================================================================
// Name        : lab3e2.cpp
// Author      : ykrop
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//#include "data_analysis.h"
//#include "data_analysis.cpp"
#include "Point.h"
#include "Station.h"
#include "Solution_of_lab.h"
int main()
{
    system("chcp 65001");

    Solution_of_lab solve = Solution_of_lab("data.xml");

    std::vector<Station> stations = solve.parseToStations();
    std::vector<std::map<std::string, std::vector<Station>>> routes = solve.parseToRoutes(stations);

    solve.task1_solution(routes);
    solve.task2_solution(routes);
    solve.task3_solution(stations);

    system("pause");  
    return 0;
}
