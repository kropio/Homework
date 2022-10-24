#include "stop.h"

void Stop::setX(float x){
    this->x = x;
};

void Stop::setY(float y){
    this->y = y;
};

float Stop::getX() const{
    return x;
};

float Stop::getY() const{
    return y;
};

Stop::Stop(){
    x = 0;
    y = 0;
};
Stop::Stop(float x, float y, std::string name){
    this->x = x;
    this->y = y;
    this->name = name;
};

Stop::Stop(const Stop &t){
    x = t.getX(); 
    y = t.getY();
};  

void Stop::operator=(const Stop &t){
    x = t.getX(); 
    y = t.getY();
};

float Stop::Distance(const Stop &t){
    return (sqrt(pow(x - t.getX(), 2) + pow(y - t.getY(), 2)) * 111000);
};

void Stop::nameOfStop(){
    std::cout << this->name << std::endl;
}