#include<stdio.h>


int main(){
    int number, answer;
    scanf("%i", &number);
    printf("%i\n", ((number >= 33) & (number <=88)));
    scanf("%i", &number);
    printf("%i\n", (number >> 20) & 1);
    system("pause");
    return 0;
}