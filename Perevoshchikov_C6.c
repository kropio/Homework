#include <stdio.h>
#include <stdlib.h>

int main(){

    int *numbers, *numbers2;
    int real_numbers[99] = {0, 3, 5, 7};

    numbers = real_numbers;

    for(int i = 0; i < 4; i++){
        printf("%i ", *(numbers + i));
    }

    numbers2 = (int*) malloc(4*sizeof(int));
    numbers2[0] = 0;
    numbers2[1] = 3;
    numbers2[2] = 5;
    numbers2[3] = 7;

    free(numbers2);
    system("pause");
    return 0;
}