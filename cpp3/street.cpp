#include "street.h"

Street::Street (const std::string &name, const Stop &stop){
    this->stops.insert(stop);
    this->name = name;
}
Street::Street(){}
Street::Street(const std::string &name){
    this->name = name;
}
        
void Street::addstop(const Stop &stop){
    this->stops.insert(stop);
}
int Street::countOfStops(){
    return stops.size();
}