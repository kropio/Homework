#include "polygon.h"


Polygon::Polygon(Point m[], int k): LockBroken(m, k){
    if(k < 3){
        throw std::runtime_error("Polygon input error — not enough points");
    }
    for(int i = 0; i < k - 2; i++){
        if ((m[i + 2].getX() - m[i].getX()) / (m[i + 1].getX() - m[i].getX()) == 
            (m[i + 2].getY() - m[i].getY()) / (m[i + 1].getY() - m[i].getY())){
                throw std::runtime_error("Polygon input error — 3 points on same line");
        }
        if ((m[i].getX() == m[i + 1].getX() and m[i + 1].getX() == m[i + 2].getX()) or
            (m[i].getY() == m[i + 1].getY() and m[i + 1].getY() == m[i + 2].getY())){
            throw std::runtime_error("Polygon input error — 3 points on same line");
        }
    }
};

Polygon::Polygon(){
};

Polygon::Polygon(std::vector<Point> &m): LockBroken(m){
    if(m.size() < 3){
        throw std::runtime_error("Polygon input error — not enough points");
    }
    for(int i = 0; i < m.size() - 2; i++){
        if ((m[i + 2].getX() - m[i].getX()) / (m[i + 1].getX() - m[i].getX()) == 
            (m[i + 2].getY() - m[i].getY()) / (m[i + 1].getY() - m[i].getY())){
                throw std::runtime_error("Polygon input error — 3 points on same line");
            }
        if ((m[i].getX() == m[i + 1].getX() and m[i + 1].getX() == m[i + 2].getX()) or
            (m[i].getY() == m[i + 1].getY() and m[i + 1].getY() == m[i + 2].getY())){
                throw std::runtime_error("Polygon input error — 3 points on same line");
            }
    }
};
Polygon::Polygon(Polygon &p): LockBroken(p){
    if(v.size() < 3){
        throw std::runtime_error("Polygon input error — not enough points");
    }
    for(int i = 0; i < v.size() - 2; i++){
        if ((v[i + 2].getX() - v[i].getX()) / (v[i + 1].getX() - v[i].getX()) == 
            (v[i + 2].getY() - v[i].getY()) / (v[i + 1].getY() - v[i].getY())){
                throw std::runtime_error("Polygon input error — 3 points on same line");
            }
        if ((v[i].getX() == v[i + 1].getX() and v[i + 1].getX() == v[i + 2].getX()) or
            (v[i].getY() == v[i + 1].getY() and v[i + 1].getY() == v[i + 2].getY())){
                throw std::runtime_error("Polygon input error — 3 points on same line");
            }
    }
};

void Polygon::operator=(const Polygon &k){
    v = k.v;
};

float Polygon::getLength(){
    return LockBroken::getLength();
};

float Polygon::getS(){
    float S = 0;
    for(int i = 0; i < v.size() - 1; i++)
    {
        S += 0.5 * (v[i].getX() + v[i + 1].getX()) * (v[i].getY() - v[i + 1].getY());
    }
    S += 0.5 * (v[v.size() - 1].getX() + v[0].getX()) * (v[v.size() - 1].getY() - v[0].getY());
    return S;
};
