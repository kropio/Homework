#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "polygon.h"

class Triangle: public Polygon{
    public:
        Triangle(Point m[], int k);

        Triangle();

        explicit Triangle(std::vector<Point> &m);

        explicit Triangle(Triangle &p);

        void operator=(Triangle &p);

        virtual float getLength();
        virtual float getS();

};

#endif