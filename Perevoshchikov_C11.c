#include <stdio.h>
#include <conio.h>
#include "ring.h"

int main(){
    printf("coordinates of the ring's center: ");
    float x, y, rad1, rad2;
    scanf("%f %f", &x, &y);
    printf("1st and 2nd radius: ");
    scanf("%f %f", &rad1, &rad2);
    struct Ring ring = {{x, y}, rad1, rad2};
    printf("perimeter: %f\nsquare: %f", perimeter(rad1, rad2), square(rad1, rad2));
    getch();
}