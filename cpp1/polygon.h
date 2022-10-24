#ifndef POLYGON_H
#define POLYGON_H
#include "lockbroken.h"
#include <iostream>

class Polygon: public LockBroken{
    public:
        Polygon(Point m[], int k);
        Polygon();
        explicit Polygon(std::vector<Point> &m);
        explicit Polygon(Polygon &p);

        void operator=(const Polygon &k);
        virtual float getLength();
        virtual float getS();

};

#endif