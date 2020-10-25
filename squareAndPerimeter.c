#include <math.h>
#define M_PI //doesn't work
#include "ring.h"

float square(float rad1, float rad2){
    return abs(pow(rad2, 2) - pow(rad1, 2)) * 3.1415;
}

float perimeter(float rad1, float rad2){
    return 2*3.1415*(rad1 + rad2);
}