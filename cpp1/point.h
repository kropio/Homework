#ifndef POINT_H
#define POINT_H
#include <cmath>

class Point{
    private:
        float x,y;
    
    public:
        void setX(const float newX);
        void setY(const float newY);
        float getX() const;
        float getY() const;
        Point();
        Point(const float _x, const float _y);
        Point(const int _x, const int _y);
        explicit Point(const Point &p);
        void operator=(const Point &t);
        float ToZero() const;
};

#endif