#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct
{
    char tag[3];
    char major;
    char ver;
    char flag;
    int tag_size;
} id3v2;
#pragma pack(pop)

int id3v2_get_size(const uint8_t *p){
    return ((uint32_t)p[0] << 21) +
           ((uint32_t)p[1] << 14) +
           ((uint32_t)p[2] << 7 ) +
                      p[3];
}


int main() {
    int amountOfFolders;
    id3v2 test;
    char nameOfFolder[255], inf[255];
    gets(nameOfFolder);

    FILE *S = fopen(nameOfFolder, "rb");

    if(!S) {perror(nameOfFolder); exit(1);}
    
    /*printf("%d\n", sizeof(test.tag));
    printf("%d\n", sizeof(test.major));
    printf("%d\n", sizeof(test.ver));
    printf("%d\n", sizeof(test.flag));
    printf("%d\n", sizeof(id3v2));*/

    fread(&test,10,1,S);
 
    for (int i = 0; i < 3; i++){
        printf("%c",test.tag[i]);
    }
    printf("\n%d\n", (int)test.major);
    printf("%d\n", (int)test.ver);
    printf("%d\n", (int)test.flag);
    printf("%d",test.tag_size);

    
    fclose(S);
    
    getch();
    
    return 0;
}
