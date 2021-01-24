#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct graph_node{
    int vertex;
    struct graph_node* next;
}graph_node;

typedef struct graph_struct{
    int vertices;
    int edges;
    graph_node** adj_list;
}graph_struct;

graph_struct* graph=NULL;


void error_exit(char* err){
    printf("%s\n",err);
    exit(-1);
}

void create_graph(int v, int e){
    graph=(graph_struct*)malloc(sizeof(graph_struct));
    graph->adj_list = (graph_node**)calloc((v+1),sizeof(graph_node*));
    if(NULL==graph || NULL==graph->adj_list)
        error_exit("Memory full.");

    graph->vertices=v;
    graph->edges=e;
}

void add_new_edge(int v1, int v2){
    graph_node* new_node = (graph_node*)malloc(sizeof(graph_node));
    if(NULL==new_node)
        error_exit("Memory full.");
    
    new_node->vertex=v2;
    new_node->next=NULL;

    
    if (NULL==graph->adj_list[v1]){
        graph->adj_list[v1]=new_node;
    }else{
        graph_node* list_head = graph->adj_list[v1];
        while (list_head->next != NULL)
            list_head = list_head->next;
        list_head->next = new_node;
    }
}

void show_graph(){
    printf("TOTAL VERTICES : %d\n",graph->vertices);
    printf("TOTAL EDGES : %d\n",graph->edges);
    
    for(int i=1;i<=graph->vertices;i++){
        printf("%d :: ",i);
        graph_node* list_head = graph->adj_list[i];
        while(NULL!=list_head){
            printf("%d -> ",list_head->vertex);
            list_head=list_head->next;
        }
        printf("%p\n",NULL);
    }
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

        // printf("%d -> %d\n",number_1,number_2);
        if(line < 1)
            create_graph(number_1,number_2);
        else{
            if(line>graph->edges)
                error_exit("Invalid input");
            if((number_1>graph->vertices)||(number_2>graph->vertices))
                error_exit("Invalid egde");
            
            add_new_edge(number_1,number_2);
            add_new_edge(number_2,number_1);
        }
        line++;
        number_1=number_2=0;
    }

    fclose(input_file);
}

int main(int argc, char* argv[]){
    if(argc<2)
        error_exit("Filename missing.");

    read_input_file(argv[1]);
    show_graph();

    return 0;
}