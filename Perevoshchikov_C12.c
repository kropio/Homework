#include <stdio.h>
#include <direct.h>
#include <io.h>
#include <sys\stat.h>

int main(int argc, char **argv) { 
    
    FILE *S;

    S = fopen(argv[1], "w");

    for (int i = 2; i < argc; i++){
        _mkdir(argv[i]);
        fprintf(S, "%s\n", argv[i]);
    }
    fclose(S);

    return 0;
}