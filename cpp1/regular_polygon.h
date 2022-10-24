#ifndef REGULAR_POLYGON_H
#define REGULAR_POLYGON_H
#include "polygon.h"


class Regular_Polygon: public Polygon{
    protected:
        float cos(Point &a, Point &b, Point &c);
    public:
        Regular_Polygon(Point m[], int k);

        explicit Regular_Polygon(std::vector<Point> &m);

        explicit Regular_Polygon(Regular_Polygon &p);

        Regular_Polygon();

        void operator=(Polygon &p);

        virtual float getLength();

        virtual float getS();
};

#endif
