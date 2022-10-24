#ifndef BROKEN_H
#define BROKEN_H
#include <vector>
#include "point.h"
class Broken{  
    protected:
        float pointToPoint(Point &a, Point &b) const;
    public:
        std::vector<Point> v;
        Broken();
        Broken(Point m[], int k);
        explicit Broken(std::vector<Point> &m);
        explicit Broken(Broken &p);
        void operator=(const Broken &t);
        virtual float getLength();
 
};

#endif