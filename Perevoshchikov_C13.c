#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int id3v2_size(char *p){
    return ((uint32_t)p[0] << 21) + ((uint32_t)p[1] << 14) + ((uint32_t)p[2] << 7 ) + p[3];
}

int invid3v_size(int *p){
    return ((*p)&127) + (((*p)&16256)<<1) + (((*p)&2080768)<<2) + (((*p)&266338304)<<3);
}

union ver{
    short x;
    char y[2];
} ver;
union flag{
    short x;
    char y;
} flag;
union tag_size{
    int x;
    char y[4];
} tag_size;
union flag1{
    short x;
    char y[2];
}flag1;
union new_tag_size{
    int x;
    char y[4];
} new_tag_size;

int tag_read(FILE *S){
    char *frameID, *information;
    frameID = (char*) malloc(5);
    fread(frameID, sizeof(char), 4, S); 
    *(frameID + 4) = '\0';
    
    fread(&tag_size.y, sizeof(char), 4, S);
    tag_size.x = id3v2_size(tag_size.y);
    if (tag_size.x == 0){
        return 10;
    }
    if (((int) frameID[0] < 48) | ((int) frameID[0] > 90) |  ((int) frameID[1] < 48) | ((int) frameID[1] > 90) | ((int) frameID[2] < 48) | ((int) frameID[2] > 90) | ((int) frameID[3] < 48) | ((int) frameID[3] > 90)){
        return 10;
    }
    fread(&flag1.y, sizeof(char), 2, S);
        
    information = (char*) malloc(tag_size.x + 1);
    fread(information, sizeof(char), tag_size.x, S);
    *(information + tag_size.x) = '\0';

    printf("name: %s\n", frameID);
    printf("tag size: %i\n", tag_size.x);
    printf("flags: %i\n", flag1.x);
    printf("information: %s\n\n", information);
    free(frameID);
    free(information);
    return tag_size.x + 10;
}

int tag_change(char *tagName, char *value, FILE *S, int tmp){
    char *frameID, *information;
    int perm = tmp;
    while (tmp > 0){
        frameID = (char*) malloc(5);
        fread(frameID, sizeof(char), 4, S); 
        *(frameID + 4) = '\0';
        fread(&tag_size.y, sizeof(char), 4, S);
        tag_size.x = id3v2_size(tag_size.y);

        if (!strcmp(tagName, frameID)){
            new_tag_size.x = strlen(value);
            new_tag_size.x = invid3v_size(&new_tag_size.x);
            fseek(S, -4, SEEK_CUR);
            //fwrite(new_tag_size.y, sizeof(char), 4, S);
            fputc(new_tag_size.y[3], S);
            fputc(new_tag_size.y[2], S);
            fputc(new_tag_size.y[1], S);
            fputc(new_tag_size.y[0], S);
            fseek(S, tag_size.x + 2, SEEK_CUR);
            information = (char*)malloc(tmp - 9 - tag_size.x);
            fread(information, tmp - 10 - tag_size.x, 1, S);
            *(information + (tmp - 10 - tag_size.x)) = '\0';
            fseek(S, 20 + perm - tmp, SEEK_SET);
            fwrite(value, strlen(value), 1, S);
            fwrite(information, tmp - 10 - tag_size.x - strlen(value), 1, S);
            return 0;
        }
    

        fseek(S, tag_size.x + 2, SEEK_CUR);
        tmp = tmp - tag_size.x - 10;
        free(frameID);
    }
    
    
    printf("there's no tag");
    return 1;
}

void one_tag_read(char *tagName, FILE *S, int tmp){
    char *frameID, *information;
    int perm = tmp;
    while (tmp > 0){
        frameID = (char*) malloc(5);
        fread(frameID, sizeof(char), 4, S); 
        *(frameID + 4) = '\0';
        fread(&tag_size.y, sizeof(char), 4, S);
        tag_size.x = id3v2_size(tag_size.y);
        if (!strcmp(tagName, frameID)){
            fread(&flag1.y, sizeof(char), 2, S);
            information = (char*) malloc(tag_size.x + 1);
            fread(information, sizeof(char), tag_size.x, S);
            *(information + tag_size.x) = '\0';
            printf("name: %s\n", frameID);
            printf("tag size: %i\n", tag_size.x);
            printf("flags: %i\n", flag1.x);
            printf("information: %s\n\n", information);
            free(frameID);
            free(information);
            return;
        }

        fseek(S, tag_size.x + 2, SEEK_CUR);
        tmp = tmp - tag_size.x - 10;
        free(frameID);
    }

    printf("there's no tag");
    return;
}

int main(int argc, char **argv) {
    char *nameOfFile, *tagHead;
    int i = 11, j, tmp;
    FILE *S;
    tagHead = (char*) malloc(3 * sizeof(char));

    if(argc <= 2) {
        printf("error", argv[0]);
        return 0;
    }


    nameOfFile = (char*) malloc((strlen(argv[1]) - 10)*sizeof(char));
    if((int)argv[1][i]==0){
        printf("error");
        return 0;
    }
    while ((int)argv[1][i]!=0){
        nameOfFile[i - 11] = argv[1][i];
        i++;
    }
    *(nameOfFile + (i - 11)) = '\0';

    S = fopen(nameOfFile, "r+b");

    fread(tagHead, sizeof(char), 3, S);
    fread(&ver.y, sizeof(char), 2, S);
    fread(&flag.y, sizeof(char), 1, S);
    fread(&tag_size.y, sizeof(char), 4, S);
    printf("%s\n", tagHead);
    printf("version: %i\n", ver.x);
    printf("flags: %i\n", flag.x);
    printf("tag_size: %i\n\n", id3v2_size(tag_size.y));
    tmp = id3v2_size(tag_size.y);
    
    if (argc == 4){
        char *tagName, *value;
        tagName = (char*) malloc((strlen(argv[2]) - 5)*sizeof(char));
        value = (char*) malloc((strlen(argv[3]) - 7)*sizeof(char));
        i = 6;
        j = 8;
        if((int)argv[2][i]==0){printf("error");
            fclose(S);
            return 0;}

        while ((int)argv[2][i]!=0){
            tagName[i - 6] = argv[2][i];
            i++;}

        *(tagName + (i - 6)) = '\0';

        if((int)argv[3][j]==0){
            printf("error");
            fclose(S);
            return 0;
        }
        while ((int)argv[3][j]!=0){
            value[j - 8] = argv[3][j];
            j++;
        }
        *(value + j - 8) = '\0';
        tag_change(tagName, value, S, tmp);
    }

    else if (!strcmp(argv[2], "--show")){
        while (tmp > 0){
            tmp = tmp - tag_read(S);
        }
        fclose(S);
        return 0;
    }
    
    else{
        char *tagName;
        tagName = (char*) malloc((strlen(argv[2]) - 5)*sizeof(char));
        i = 6;
        if((int)argv[2][i]==0){printf("error");
            fclose(S);
            return 0;}
        while ((int)argv[2][i]!=0){
            tagName[i - 6] = argv[2][i];
            i++;}
        *(tagName + (i - 6)) = '\0';

        one_tag_read(tagName, S, tmp);
    }

    fclose(S);

    return 0;
 }