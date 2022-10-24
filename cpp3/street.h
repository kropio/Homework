#ifndef STREET_H
#define STREET_H
#include <string>
#include <set>
#include "stop.h"

class Street{
    private:
        std::string name;
        std::set<Stop> stops;


    public:
        Street (const std::string &name, const Stop &stop);
        Street();
        explicit Street(const std::string &name);
        
        void addstop(const Stop &stop);
        int countOfStops();
};

#endif