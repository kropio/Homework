#include <stdio.h>
#include <conio.h>
#include <math.h> 
#include <windows.h>

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double m, n, answer1, answer2;
    printf("m = ");
    scanf("%d", &m);
    printf("\nn = ");
    scanf("%d", &n);
    answer1 = ((m - 1) * sqrt(m) - (n - 1) * sqrt (n)) / (sqrt(pow(m,3) * n) + n * m + m * m - m);
    answer2 = (sqrt(m) - sqrt(n)) / m;
    printf("z1 = %d\nz2 = %d", answer1, answer2);
    system("Pause");
	return 0;
}