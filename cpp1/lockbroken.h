#ifndef LOCKBROKEN_H
#define LOCKBROKEN_H
#include <vector>
#include "broken.h"
#include "point.h"

class LockBroken: public Broken{
    public:
        LockBroken(Point m[], int k);
        explicit LockBroken();
        explicit LockBroken(std::vector<Point> &m);
        explicit LockBroken(LockBroken &p);
        void operator=(const LockBroken &t);
        virtual float getLength();
};

#endif