#include <conio.h>
#include <stdio.h>
#include <math.h>

enum paints{
    watercolor = 1,
    oil,
    waterBasedEmulsion,
};

typedef struct triangle
{
    int dot1[2], dot2[2], dot3[2]; 
} Tria;

typedef struct cardReader
{
    unsigned activeSD: 1;
    unsigned compactFlash: 1;
    unsigned memoryStick: 1; 
} CR;

union forCR{
    struct cardReader card;
    int i;    
}reader;

double area(struct triangle tria){
    return 0.5 * abs((tria.dot1[0] - tria.dot3[0]) * (tria.dot2[1] - tria.dot3[1]) - (tria.dot2[0] - tria.dot3[0]) * (tria.dot1[1] - tria.dot3[1]));
}


int main() {

    enum paints paint;
    int area, num;

    Tria tria = {{1,1}, {2,2}, {1,3}};
    printf("hex number: ");
    scanf("%x", &reader.i);
    
    paint = watercolor;


    printf("watercolor: %d\n", paint);
    printf("area of triangle: %d\n", area);
    printf("activeCR: %i\ncompact flash: %i\nmemory stick: %i\n", reader.card.activeSD, reader.card.compactFlash, reader.card.memoryStick);

    system("pause");
    return 0;
}