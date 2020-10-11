#include <stdio.h>

int main(){
    int numbers[80];
    int c[2][2];
    int a[2][2]={{1,1}, {1,4}};
    int b[2][2]={{1,2}, {4,1}};
    for (int i = 0; i<6; i++) 
    {
    scanf("%i, ", &numbers[i]); 
    }
    printf("%i\n", numbers[3]);
    

    for(int i = 0; i<2; i++){
        for (int j = 0; j<2; j++){
            for (int k = 0; k<2; k++){
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    printf("%i %i\n%i %i\n", c[0][0], c[0][1], c[1][0], c[1][1]);



    system("pause");
    return 0;
}