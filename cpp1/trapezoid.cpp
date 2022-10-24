#include "trapezoid.h"

Trapezoid::Trapezoid(Point m[], int k): Polygon(m, k){
    if (k != 4){
        throw std::runtime_error("Trapezoid input error — number of points != 4");
    }
    if ((abs((m[0].getY() - m[1].getY())/(m[0].getX() - m[1].getX())) == 
        abs((m[2].getY() - m[3].getY())/(m[2].getX() - m[3].getX())) and
        abs((m[2].getY() - m[1].getY())/(m[2].getX() - m[1].getX())) != 
        abs((m[0].getY() - m[3].getY())/(m[0].getX() - m[3].getX()))) or
        (abs((m[0].getY() - m[1].getY())/(m[0].getX() - m[1].getX())) != 
        abs((m[2].getY() - m[3].getY())/(m[2].getX() - m[3].getX())) and
        abs((m[2].getY() - m[1].getY())/(m[2].getX() - m[1].getX())) == 
        abs((m[0].getY() - m[3].getY())/(m[0].getX() - m[3].getX()))))
    {
            throw std::runtime_error("Trapezoid input error — it's not trapezoid");
    }
};

Trapezoid::Trapezoid(){};

Trapezoid::Trapezoid(std::vector<Point> &m): Polygon(m){
    if (m.size() != 4){
        throw std::runtime_error("Trapezoid input error — number of points != 4");
    }
    if ((abs((m[0].getY() - m[1].getY()) / (m[0].getX() - m[1].getX())) == 
        abs((m[2].getY() - m[3].getY()) / (m[2].getX() - m[3].getX())) and
        abs((m[2].getY() - m[1].getY()) / (m[2].getX() - m[1].getX())) != 
        abs((m[0].getY() - m[3].getY()) / (m[0].getX() - m[3].getX()))) or
        (abs((m[0].getY() - m[1].getY()) / (m[0].getX() - m[1].getX())) != 
        abs((m[2].getY() - m[3].getY()) / (m[2].getX() - m[3].getX())) and
        abs((m[2].getY() - m[1].getY()) / (m[2].getX() - m[1].getX())) == 
        abs((m[0].getY() - m[3].getY()) / (m[0].getX() - m[3].getX()))))
        {
            throw std::runtime_error("Trapezoid input error — it's not trapezoid");
        } 
};

Trapezoid::Trapezoid(Trapezoid &p): Polygon(p){
    if (v.size() != 4){
        throw std::runtime_error("Trapezoid input error — number of points != 4");
    }
    if ((abs((v[0].getY() - v[1].getY()) / (v[0].getX() - v[1].getX())) == 
        abs((v[2].getY() - v[3].getY()) / (v[2].getX() - v[3].getX())) and
        abs((v[2].getY() - v[1].getY()) / (v[2].getX() - v[1].getX())) != 
        abs((v[0].getY() - v[3].getY()) / (v[0].getX() - v[3].getX()))) or
        (abs((v[0].getY() - v[1].getY()) / (v[0].getX() - v[1].getX())) != 
        abs((v[2].getY() - v[3].getY()) / (v[2].getX() - v[3].getX())) and
        abs((v[2].getY() - v[1].getY()) / (v[2].getX() - v[1].getX())) == 
        abs((v[0].getY() - v[3].getY()) / (v[0].getX() - v[3].getX()))))
        {
            throw std::runtime_error("Trapezoid input error — it's not trapezoid");
        }
};

void Trapezoid::operator=(Trapezoid &p){
    v = p.v;
};

float Trapezoid::getLength(){
    return Polygon::getLength();
}
float Trapezoid::getS(){
    return Polygon::getS();
};
