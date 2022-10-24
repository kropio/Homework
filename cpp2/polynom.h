#ifndef POLYNOM_H
#define POLYNOM_H
#include <vector>
#include <iostream>

class Polynom{
    private:
        std::vector<float> coef;

    public:
        Polynom();
        
        Polynom(int k, float m[]);
        Polynom(std::vector<float> &m);
        Polynom(Polynom &m);

        void operator=(const Polynom &m);

        bool operator==(const Polynom &m);

        bool operator!=(const Polynom &m);

        Polynom operator+(const Polynom &m);

        Polynom operator-(const Polynom &m);

        Polynom operator-() const;
        
        Polynom& operator++();
        
        Polynom operator++(int);

        Polynom& operator--();
        
        Polynom operator--(int);

        void operator+=(const Polynom &m);

        void operator-=(const Polynom &m);

        Polynom operator*(const Polynom &m) const;

        Polynom operator/(float m) const;

        void operator*=(const Polynom &m);

        void operator/=(float m);

        friend std::ostream& operator<< (std::ostream &out, const Polynom &Polynom);
        friend std::istream& operator>> (std::istream &in, Polynom &point);

        float operator[](int k);

        void show() const;
        
        ~Polynom();
};



#endif