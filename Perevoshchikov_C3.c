// для 2-го задания сдвиг на 12 бит и побитовое сложение с 1
#include <stdio.h>
#include <conio.h>
 
int main () {
	int first, second;
	scanf("%i", &first);
    printf("%x\n%x %x\n%x %x\n", first, first, first << 4, first, ~first);
    scanf("%x", &second);
    printf("%x", first & second);
    system("pause");
	return 0;
}