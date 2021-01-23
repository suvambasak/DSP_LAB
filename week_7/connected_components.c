#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int vertices;
int edges;

void error_exit(char* err){
    printf("%s\n",err);
    exit(-1);
}

int main(int argc, char* argv[]){
    if(argc<2)
        error_exit("Filename missing.");

    char c;
    FILE* input_file;
    if (NULL==(input_file=fopen(argv[1],"r")))
        error_exit("Failed to read");

    while(EOF!=(c=fgetc(input_file))){
        putchar(c);
    }

    fclose(input_file);
    return 0;
}