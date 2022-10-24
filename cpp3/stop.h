#ifndef STOP_H
#define STOP_H
#include<cmath>
#include<string>
#include<iostream>

class Stop{
    private:
        float x, y;
        std::string name;
    public:

    void setX(float x);
    void setY(float y);
    float getX() const;
    float getY() const;
    Stop();
    Stop(float _x, float _y, std::string name);
    Stop(const Stop &t);  
    void operator=(const Stop &t);
    float Distance(const Stop &t);
    void nameOfStop();
};

#endif