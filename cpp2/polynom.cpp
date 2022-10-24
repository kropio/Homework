#include "polynom.h"

Polynom::Polynom(){};
        
Polynom::Polynom(int k, float m[]){
    //std::cout << "hello";
    //std::cout << m[0];
    /*for (int i = 0; i < k; i++){
        coef.push_back(m[i]);
    };*/
};

Polynom::Polynom(std::vector<float> &m){
    coef = m;
};
Polynom::Polynom(Polynom &m){
    coef = m.coef;
};

void Polynom::operator=(const Polynom &m){
    coef = m.coef;
};

bool Polynom::operator==(const Polynom &m){
    return coef == m.coef;
};

bool Polynom::operator!=(const Polynom &m){
    return !(coef == m.coef);
}

Polynom Polynom::operator+(const Polynom &m){
    Polynom tmp;
    if(m.coef.size() > coef.size()){
        for(int i = 0; i < coef.size(); i++){
        tmp.coef.push_back(m.coef[i] + coef[i]);
        }
        for(int i = coef.size(); i < m.coef.size(); i++){
        tmp.coef.push_back(m.coef[i]);
        }
    }
    else{
        for(int i = 0; i < m.coef.size(); i++){
        tmp.coef.push_back(m.coef[i] + coef[i]);
        }
        for(int i = m.coef.size(); i < coef.size(); i++){
        tmp.coef.push_back(coef[i]);
        }
    }
    return tmp;
};

Polynom Polynom::operator-(const Polynom &m){
    Polynom tmp;
    if(m.coef.size() > coef.size()){
        for(int i = 0; i < coef.size(); i++)
            tmp.coef.push_back(coef[i] - m.coef[i]);
        
        for(int i = coef.size(); i < m.coef.size(); i++)
            tmp.coef.push_back(-m.coef[i]);
        
    }
    else{
        for(int i = 0; i < m.coef.size(); i++)
            tmp.coef.push_back(coef[i] - m.coef[i]);
        
        for(int i = m.coef.size(); i < coef.size(); i++)
            tmp.coef.push_back(coef[i]);
        
    }
    return tmp;
};

Polynom Polynom::operator-() const{
    Polynom m;
    for(int i = 0; i < coef.size(); i++){
        m.coef.push_back(-coef[i]);
    }
    return m;
};

Polynom& Polynom::operator++(){
    coef[0]++;
    return *this;        
};

Polynom Polynom::operator++(int){
    Polynom tmp(coef);

    ++(*this);
    return tmp;        
};

Polynom& Polynom::operator--(){
    coef[0]--;
    return *this;        
};

Polynom Polynom::operator--(int){
    Polynom tmp(coef);

    --(*this);
    return tmp;        
};

void Polynom::operator+=(const Polynom &m){
    *this = *this + m;
};

void Polynom::operator-=(const Polynom &m){
    *this = *this - m;
};

Polynom Polynom::operator*(const Polynom &m) const{
    Polynom tmp;
    for(int i = 0; i < m.coef.size() + coef.size() - 1; i++){
        tmp.coef.push_back(0);
    }
    for(int i = 0; i < coef.size(); i++){
        if (coef[i] != 0){
            for(int j = 0; j < m.coef.size(); j++){
                tmp.coef[i + j] += coef[i] * m.coef[j];
            }
        }
    }
    return tmp;
};

Polynom Polynom::operator/(float m) const{
    Polynom tmp;
    for(int i = 0; i < coef.size(); i++){
        tmp.coef.push_back(coef[i] / m);
    }
    return tmp;
};

void Polynom::operator*=(const Polynom &m){
    *this = *this * m;
};

void Polynom::operator/=(float m){
    *this = *this / m;
};

float Polynom::operator[](int k){
    return coef[k];
};

void Polynom::show() const{
    for(int i = coef.size() - 1; i > 0; i--){
        if (coef[i] != 0){
        std::cout << coef[i] << "*x^" << i << " + "; 
        }
    }
    std::cout << coef[0] << std::endl;
}
Polynom::~Polynom(){
    delete(&coef);
};

std::ostream& operator<< (std::ostream &out, const Polynom &Polynom){


    return out;
}
 
std::istream& operator>> (std::istream &in, Polynom &Polynom){

 
    return in;
}