#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "polygon.h"

class Trapezoid: public Polygon{
    public:
        Trapezoid(const Point m[], const int k);

        Trapezoid();

        explicit Trapezoid(const std::vector<Point> &m);

        explicit Trapezoid(const Trapezoid &p);

        void operator=(const Trapezoid &p);

        virtual float getLength();
        virtual float getS();

};

#endif