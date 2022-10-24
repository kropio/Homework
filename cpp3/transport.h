#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <string>
#include <vector>
#include <iostream>
#include "stop.h"

class Transport{

    private:
        std::string number;
        std::vector<Stop> stops;

    public:

        Transport();
        Transport(std::string number, Stop stop);
        std::string name();
        void addStop(Stop stop);
        int countOfStops();
        float Distance();
        void allStops();
};

#endif