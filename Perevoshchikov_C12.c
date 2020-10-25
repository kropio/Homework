#include <stdio.h>
#include <direct.h>
#include <io.h>
#include <sys\stat.h>


int main() {
    int amountOfFolders, fp;
    fp = creat("file.txt", 0000200);
    printf("How much folder you want to create?\n");
    scanf("%d", &amountOfFolders);
    char nameOfFolder[255];
    gets(nameOfFolder);

    FILE *S;
    S = fopen("Created_folders.txt", "w");

    for(int i = 0; i < amountOfFolders; i++){
        printf("write name of folder\n");
        gets(nameOfFolder);
        _mkdir(nameOfFolder);
        fprintf(S, "%s\n", nameOfFolder);
    }
    fclose(S);
    
    getch();
    
    return 0;
}

