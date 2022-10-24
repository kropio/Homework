#include "Point.h"

Point::Point(double x_, double y_){
    x = x_;
    y = y_;
}

Point::Point(){
    x = 0;
    y = 0;
}

double Point::getX() const{
    return x;
}

double Point::getY() const{
    return y;
}

