#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *intTOStr(int p){
    char *k;
    int log = 0, temp = p;
    while (temp !=0){
        log++;
        temp /= 10;
    }
    k = (char*) malloc(log + 1);
    for(int i = 0; i < log; i++){
        k[log - i - 1] = (char) (p % 10 + 48);
        p /= 10;
    }
    return k;
}

int main (){
  printf("%s", intTOStr(234));
  return 0;
}