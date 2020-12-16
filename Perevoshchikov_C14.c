#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bit{
    unsigned short x : 1;
};

struct aliveness{
    unsigned short x : 4;
};

int strToInt(char *p){
    int num = 0, tmp = 1, len = strlen(p);
    for(int i = 0; i < len; i++){
        num += (((int) p[len-i-1] - 48) * tmp);
        tmp *= 10; 
    }
    return num;
}

char *intTOStr(int p, int log){
    char *k;
    k = (char*) malloc(log + 5);
    for(int i = 0; i < log; i++){
        k[log - i - 1] = (char) (p % 10 + 48);
        p /= 10;
    }
    *(k + log) = '.';
    *(k + log + 1) = 'b';
    *(k + log + 2) = 'm';
    *(k + log + 3) = 'p';
    *(k + log + 4) = '\0';
    return k;
}

short int numOfChars(int p){
    int log = 0;
    if (p == 0){
        return 1;
    }
    while (p !=0){
        log++;
        p /= 10;
    }
    return log;
}

int main(int argc, char **argv) {
    char *nameOfImage, *directory, *buffer8, *temp, buf;
    int iteration = 2147483647, frequency = 1, width, height, offSetBits, psSize, counter = 0, skip = 0, tempint;
    short int depth, buffer = 0, log = 0, next = 1;
    FILE *S;

    if(argc < 5) {
        printf("error", argv[0]);
        return 0;
    } 
    nameOfImage = (char*) malloc((strlen(argv[2]) + 1)*sizeof(char));
    directory = (char*) malloc((strlen(argv[4]) + 20)*sizeof(char));
    for(int i = 0; i < (strlen(argv[2])); i++){
        nameOfImage[i] = argv[2][i];
    }
    for(int i = 0; i < (strlen(argv[4])); i++){
        directory[i] = argv[4][i];
    }
    *(nameOfImage + strlen(argv[2])) = '\0';
    *(directory + strlen(argv[4])) = '\0';

    if (argc == 7){

        if (argv[5][2] == 'm'){
            iteration = strToInt(argv[6]);
        }
        else{
            frequency = strToInt(argv[6]);
        }

    }
    if (argc == 9){
        if (argv[5][2] == 'm'){
            iteration = strToInt(argv[6]);
            frequency = strToInt(argv[8]);
        }
        else{
            iteration = strToInt(argv[8]);
            frequency = strToInt(argv[6]);
        }
    }
    
    S = fopen(nameOfImage, "rb");
    //printf("%s", nameOfImage);
    fseek(S, 10, SEEK_SET);
    fread(&offSetBits, sizeof(int), 1, S);
    fseek(S, 4, SEEK_CUR);
    fread(&width, sizeof(int), 1, S);
    fread(&height, sizeof(int), 1, S);
    fseek(S, 2, SEEK_CUR);
    fread(&depth, sizeof(short int), 1, S);
    struct bit bitMap[height + 2][width + 2];
    struct aliveness alive[height][width];
    //short int bitMap[height][width];
    //printf("%d %d", psSize, skip);
    psSize = width % 8 == 0 ? width / 8 : width / 8 + 1;
    skip = width % 32 == 0 ? 0 : ((width / 32 + 1) * 32 - width)/8;
    buffer8 = (char*) malloc(psSize);
    fseek(S, offSetBits, SEEK_SET);
    for(int i = 0; i < height; i++){
        fread (buffer8, psSize, 1, S);
        for(int j = 0; j < width; j++){
            tempint = (int) buffer8[counter / 8] & (128 >> (counter % 8));
            tempint = tempint == 0 ? 0 : 1;
            bitMap[i + 1][j + 1].x = tempint;
            counter++; 
        }
        counter = 0;
        fseek(S, skip, SEEK_CUR);
        //printf(" %d\n", counter);
        //printf("%d\n", buffer8);
    }

    fseek(S, 0, SEEK_SET);
    buffer8 = (char*) malloc(offSetBits + 1);
    fread (buffer8, offSetBits, 1, S);
    /*for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j ++){
            printf("%d", bitMap[i][j]);
        }
        printf("\n");
    }*/
    
    for(int k = 0; k < iteration; k++){

        if(next == 0){break;}

        if(k % frequency == 0){
            tempint = k;
            log = numOfChars(k);
            temp = intTOStr(k, log);
            for(int i = 0; i < log + 4; i++){
                *(directory + strlen(argv[4]) - 4 + i) = temp[i];
            }
            S = fopen(directory, "wb");
            fwrite(buffer8, offSetBits, 1, S);
            for(int i = 0; i < height; i++){
                for(int j = 0; j < width; j++){
                    
                    buffer = buffer | ((int)bitMap[i + 1][j + 1].x << (7 - (j % 8)));
                    if ((j + 1) % 8 == 0){
                        buf = (char) buffer;
                        fwrite(&buf, 1, 1, S);
                        buffer = 0;
                    }
                }
                if (width % 8 != 0){   
                    buf = (char) buffer;
                    fwrite(&buf, 1, 1, S);
                }
                buf = (char) 0;
                for (int j = 0; j < skip; j++){
                    fwrite(&buf, 1, 1, S);
                }
            
            }
            fclose(S);
        }
        next = 0;

        bitMap[0][0] = bitMap[height][width];
        bitMap[height + 1][width + 1] = bitMap[1][1];
        bitMap[0][width + 1] = bitMap[height][1];
        bitMap[height + 1][0] = bitMap[1][width];
        for(int i = 0; i < width; i++){
            bitMap[0][i + 1] = bitMap[height][i + 1];
            bitMap[height + 1][i + 1] = bitMap[1][i + 1];
        }
        for(int i = 0; i < height; i++){
            bitMap[i + 1][0] = bitMap[i + 1][width];
            bitMap[i + 1][width + 1] = bitMap[i + 1][1];
        }
        
        for (int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                //printf("%d", bitMap[i + 1][j + 1].x);
                alive[i][j].x = 0;
            }
            //printf("\n");
        }
        //printf("\n");
        for (int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                alive[i][j].x += bitMap[i][j].x;
                alive[i][j].x += bitMap[i][j + 1].x;
                alive[i][j].x += bitMap[i][j + 2].x;
                alive[i][j].x += bitMap[i + 1][j + 2].x;
                alive[i][j].x += bitMap[i + 2][j + 2].x;
                alive[i][j].x += bitMap[i + 2][j + 1].x;
                alive[i][j].x += bitMap[i + 2][j].x;
                alive[i][j].x += bitMap[i + 1][j].x;
                //printf("%d", alive[i][j].x);
            }
            //printf("\n");
        }
        //printf("\n");
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(alive[i][j].x == 3 & bitMap[i + 1][j + 1].x == 0){
                    bitMap[i + 1][j + 1].x = 1;
                    next = 1;
                }
                else if ((alive[i][j].x > 3 | alive[i][j].x < 2) & bitMap[i + 1][j + 1].x == 1){
                    bitMap[i + 1][j + 1].x = 0;
                    next = 1;
                }
                //printf("%d", bitMap[i][j].x);
            }
            //printf("\n");
        }

    }

    fclose(S);

    return 0;
}