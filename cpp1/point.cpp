#include "point.h"
    
void Point::setX(const float newX){
    x = newX;
};
void Point::setY(const float newY){
    y = newY;
};
float Point::getX() const{
    return x;
};
float Point::getY() const{
    return y;
};
Point::Point(){
    x = 0;
    y = 0;
};
Point::Point(const float _x, const float _y): x(_x), y(_y){
};
Point::Point(const int _x, const int _y): x(_x), y(_y){
};
Point::Point(const Point &p){
    x = p.getX(); y = p.getY();
};
void Point::operator=(const Point &t){
    x = t.getX(); y = t.getY();
};
float Point::ToZero() const{
    return sqrt(pow(x, 2) + pow(y, 2));
};