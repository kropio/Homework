#include "transport.h"

Transport::Transport(){};
Transport::Transport(std::string number, Stop stop){
    this->number = number;
    this->stops.push_back(stop);
}
void Transport::addStop(Stop stop){
    this->stops.push_back(stop);
};

std::string Transport::name(){
    return this->number;
}
int Transport::countOfStops(){
    return this->stops.size();
};
float Transport::Distance(){
    float len = 0;
    for(int i = 0; i < (countOfStops() - 2); ++i){
        len += stops[i].Distance(stops[1 + i]);
    }
};

void Transport::allStops(){
    std::cout << this->number << ": ";
    for(Stop s: this->stops){
        s.nameOfStop();
    }
}

