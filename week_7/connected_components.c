#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int vertices;
int edges;

void error_exit(char* err){
    printf("%s\n",err);
    exit(-1);
}

void read_input_file(char* file_name){
    char c;
    int number_1=0;
    int number_2=0;
    int line=0;

    FILE* input_file;
    if (NULL==(input_file=fopen(file_name,"r")))
        error_exit("Failed to read");

    while(EOF!=(c=fgetc(input_file))){
        while(isdigit(c)){
            if(number_1)
                number_1=(number_1*10)+atoi(&c);
            else
                number_1=atoi(&c);
            c=fgetc(input_file);
        }

        c=fgetc(input_file);
        while(isdigit(c)){
            if(number_2)
                number_2=(number_2*10)+atoi(&c);
            else
                number_2=atoi(&c);
            c=fgetc(input_file);
        }

        printf("%d -> %d\n",number_1,number_2);
        if(line < 1){
            vertices=number_1;
            edges=number_2;
        }else{
            if(line>edges)
                error_exit("Invalid input");
            if((number_1>vertices)||(number_2>vertices))
                error_exit("Invalid egde");   
        }
        line++;
        number_1=number_2=0;
    }

    // printf("%d --- %d\n",vertices,edges);

    fclose(input_file);
}


int main(int argc, char* argv[]){
    if(argc<2)
        error_exit("Filename missing.");

    read_input_file(argv[1]);

    return 0;
}