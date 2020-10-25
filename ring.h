#ifndef RING_H
#define RING_H
#include "squareAndPerimeter.c"

float square(float, float);
float perimeter(float, float);

struct Dot{
    float x, y; 
};

struct Ring{
    struct Dot dot;
    float rad1, rad2; 
};

#endif 