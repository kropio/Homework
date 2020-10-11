#include <stdio.h>
#include <conio.h>

int main(){
    char first[200], second[200];
    char *firstPo = first, *secondPo = second;
    int nsymbols;

    printf("1st string: ");
    int i = 0;
    while((first[i] = getchar())!='\n'){i++;}
    int lengthFirst = i;
    printf("2nd string: ");
    i = 0;
    while((second[i] = getchar())!='\n'){i++;}
    int lengthSecond = i;

    printf("equalOrNo: %d\n", equal(firstPo, secondPo, lengthFirst, lengthSecond));
    
    printf("How much symbols do you want to copy: ");
    scanf("%d", &nsymbols);
    if(lengthFirst > lengthSecond){i = lengthFirst;}
    else {i = lengthSecond;}
    char withCopiedArr[i];
    char *withCopiedArrPo = withCopiedArr;
    withCopied(firstPo, secondPo, withCopiedArrPo, nsymbols, lengthSecond);

    printf("length of 1st String: %d\nlength of 2nd String: %d\n", lengthFirst, lengthSecond);

    char set[60];
    char *setPo = set;
    int counter = 0;
    int *counterPo;
    counterPo = &counter;
    findSet(first, second, lengthFirst, lengthSecond, setPo, counterPo);

    lexems(first, set, lengthFirst, counter);

    getch();
    return 0;
}

int equal(char *first, char *second, int lengthFirst, int lengthSecond){
    int checker = 1;
    if (lengthSecond != lengthFirst){
        return 0;
    }
    for (int i = 0; i < lengthFirst; i++){
        if(*(first + i) != *(second + i)){
            checker = 0;
            break;
        }
    }
    return checker;
}

void withCopied(char *first, char *second, char *copied, int nsymbols, int lengthSecond){
    printf("Copied String: ");
    for (int i = 0; i < nsymbols; i++){
        *(copied+i) = *(first + i);
        printf("%c", *(copied + i));
    }
    for (int i = nsymbols; i < lengthSecond; i++){
        *(copied + i) = *(second + i);
        printf("%c", *(copied + i));
    }
    printf("\n");
}

void findSet(char first[], char second[], int lengthFirst, int lengthSecond, char *set, int *counterPo){
    printf("set from 1st String, that 2nd String have: ");
    int numeric[60] = {0};
    for (int i = 0; i < lengthFirst; i++){
        numeric[(int) (first[i] - 65)] = 1;
    }
    for (int i = 0; i < lengthSecond; i++){
        if(numeric[(int)(second[i] - 65)] == 1){
            numeric[(int)(second[i] - 65)] = 2;
        }
    }
    for (int i = 0; i < 60; i++){
        if(numeric[i] == 2){
            *(set + *counterPo) = i + 65;
            printf("%c", *(set + *counterPo));
            (*counterPo)++;
        }
    }
    printf("\n");
    return;
}

void lexems(char first[], char set[], int lengthFirst, int counter){
    char lexem[lengthFirst];
    printf("lexems from 1st String: ");
    for (int i = 0; i < lengthFirst; i++){
        for(int j = 0; j < counter; j++){
            if(first[i] == set[j]){
                lexem[i] = ' ';
                break;
            }
        }
        if (lexem[i] != ' '){
            lexem[i] = first[i];
        }
        printf("%c", lexem[i]);
    }
    return;
}