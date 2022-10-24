#include "regular_polygon.h"

float Regular_Polygon::cos(Point &a, Point &b, Point &c){
    return ((b.getX() - a.getX())*(b.getX() - c.getX()) + (b.getY() - a.getY())*(b.getY() - c.getY())) /
            (pointToPoint(a, b) * pointToPoint(b, c));
}
Regular_Polygon::Regular_Polygon(Point m[], int k): Polygon(m, k){
    for(int i = 0; i < k - 2; i++){
        if (pointToPoint(m[i], m[i + 1]) != pointToPoint(m[i + 1], m[i + 2])){
            throw std::runtime_error("Regular polygon error — it's not a Regular polygon");
        }
    }
    for(int i = 0; i < k-3; i++){
        if (cos(m[i], m[i + 1], m[i + 2]) != cos(m[i + 1], m[i + 2], m[i + 3])){
            throw std::runtime_error("Regular polygon error — it's not a Regular polygon");
        }
    }
    if (cos(m[k - 2], m[k - 1], m[0]) != cos(m[k - 1], m[0], m[1])){
            throw std::runtime_error("Regular polygon error — it's not a Regular polygon");
        }
};

Regular_Polygon::Regular_Polygon(std::vector<Point> &m): Polygon(m){
    for(int i = 0; i < m.size() - 2; i++){
        if (pointToPoint(m[i], m[i + 1]) != pointToPoint(m[i + 1], m[i + 2])){
            throw std::runtime_error("Regular polygon error — it's not a Regular polygon");
        }
    }
    for(int i = 0; i < m.size() - 3; i++){
        if (cos(m[i], m[i + 1], m[i + 2]) != cos(m[i + 1], m[i + 2], m[i + 3])){
            throw std::runtime_error("Regular polygon error — it's not a Regular polygon");
        }
    }
    if (cos(m[m.size() - 2], m[m.size() - 1], m[0]) != cos(m[m.size() - 1], m[0], m[1])){
            throw std::runtime_error("Regular polygon error — it's not a Regular polygon");
        }
};

Regular_Polygon::Regular_Polygon(Regular_Polygon &p): Polygon(p){
    for(int i = 0; i < v.size() - 2; i++){
        if (pointToPoint(v[i], v[i + 1]) != pointToPoint(v[i + 1], v[i + 2])){
            throw std::runtime_error("Regular polygon error — it's not a Regular polygon");
        }
    }
    for(int i = 0; i < v.size()-3; i++){
        if (cos(v[i], v[i+1], v[i+2]) != cos(v[i+1], v[i+2], v[i+3])){
            throw std::runtime_error("Regular polygon error — it's not a Regular polygon");
        }
    }
    if (cos(v[v.size()-2], v[v.size()-1], v[0]) != cos(v[v.size()-1], v[0], v[1])){
            throw std::runtime_error("Regular polygon error — it's not a Regular polygon");
        }
};

Regular_Polygon::Regular_Polygon(){};

void Regular_Polygon::operator=(Polygon &p){
    v = p.v;
};
float Regular_Polygon::getLength(){
    return Polygon::getLength();
};
float Regular_Polygon::getS(){
    return Polygon::getS();
};