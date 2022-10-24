#include "triangle.h"

Triangle::Triangle(Point m[], int k): Polygon(m, k){
    if (k != 3){
        throw std::runtime_error("Triangle input error — number of points != 3");
    }
};

Triangle::Triangle(){};

Triangle::Triangle(std::vector<Point> &m): Polygon(m){
    if (m.size() != 3){
        throw std::runtime_error("Triangle input error — number of points != 3");
    }
};

Triangle::Triangle(Triangle &p): Polygon(p){
    if (v.size() != 3){
        throw std::runtime_error("Triangle input error — number of points != 3");
    }
};

void Triangle::operator=(Triangle &p){
    v = p.v;
};

float Triangle::getLength(){
    return Polygon :: getLength();
}
float Triangle::getS(){
    return Polygon :: getS();
};