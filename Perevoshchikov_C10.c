#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef struct dot
{
    float x, y; 
}Dot;

int main(){
    int amountOfDots;
    float x, y;
    printf("How many dots: ");
    scanf("%d", &amountOfDots);
    float distance[amountOfDots][amountOfDots - 1];
    float *distancePo = distance;
    Dot dots[amountOfDots];
    for(int i = 0; i < amountOfDots; i++){
        printf("x and y of %d dot: ", (i + 1));
        scanf("%f %f", &x, &y);
        dots[i].x = x;
        dots[i].y = y;
    }
    dotFunction(dots, amountOfDots, distancePo);

    printf("String: ");
    char str[255], withoutSpaces[255];
    char *strPo = str, *withoutSpacesPo = withoutSpaces;
    int *lastDot, length = 0, i = 0;
    while((str[length] = getchar())!='\n'){
        if (str[length] == '.'){
            lastDot = &(str[length]);
        }
        length++;
    }
    deleteSpaces(strPo, withoutSpacesPo, 0, lastDot);
    while(withoutSpaces[i]!='\n'){
        printf("%c", withoutSpaces[i]);
        i++;
    }

    getch();

    return 0;
}

void dotFunction(Dot arr[], int amount, float *distance){
    for (int i = 0; i < amount; i++){
        for (int j = 0; j < amount - 1; j++){
            if (j >= i){
                *(distance + i*(amount - 1) + j) = sqrt(pow((arr[i].x - arr[j+1].x), 2) + pow((arr[i].y - arr[j+1].y), 2));
            }else{
                *(distance + i*(amount - 1) + j) = sqrt(pow((arr[i].x - arr[j].x), 2) + pow((arr[i].y - arr[j].y), 2));
            }
        }
    }
}

void deleteSpaces(char *strPo, char *withoutSpaces, int numOfSpaces, int *lastDot){
    if (strPo == lastDot){
        *withoutSpaces = '.';
        *(withoutSpaces + 1) = '\n';
        return;
    }
    if (*strPo == ' '){numOfSpaces++;}
    if (numOfSpaces != 3){
        *withoutSpaces = *strPo;
        withoutSpaces++;
    }else{numOfSpaces = 0;}
    deleteSpaces(strPo + 1, withoutSpaces, numOfSpaces, lastDot);
}