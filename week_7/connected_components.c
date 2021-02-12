#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define VISITED 1
#define NOT_VISITED 0

// Data structures for Adjacency List

// Structure to hold list of adjacent vertices from one vertex.(Linkedlist)
typedef struct graph_node
{
    int vertex;
    struct graph_node *next;
} graph_node;

// Structures to hold the input graph.
// Total number of vertices, edeges, array to store visited flag, Adjacency List (Array of linkedlist head pointers)
typedef struct graph_struct
{
    int vertices;
    int edges;
    int *visited;
    graph_node **adj_list;
} graph_struct;

// To store the input graph from file.
graph_struct *graph = NULL;

// Function to handle error.
void error_exit(char *err)
{
    printf("%s\n", err);
    exit(-1);
}

// Function create a new graph.
void create_graph(int v, int e)
{
    // Allocate memeory for graph. (v+1) -> skipping 0 index.
    graph = (graph_struct *)malloc(sizeof(graph_struct));
    graph->visited = (int *)calloc((v + 1), sizeof(int));
    graph->adj_list = (graph_node **)calloc((v + 1), sizeof(graph_node *));

    // If memory not allocated.
    if (NULL == graph || NULL == graph->visited || NULL == graph->adj_list)
        error_exit("Memory full. (create_graph)");

    // Total number of vertices and edges.
    graph->vertices = v;
    graph->edges = e;
}

// Function to add new edges in the graph. edge v1->v2
void add_new_edge(int v1, int v2)
{
    // Create new node.
    graph_node *new_node = (graph_node *)malloc(sizeof(graph_node));
    // If memory not allocated.
    if (NULL == new_node)
        error_exit("Memory full. (add_new_edge)");

    new_node->vertex = v2;
    new_node->next = NULL;

    // If first adjacent vertex of v1.
    if (NULL == graph->adj_list[v1])
        graph->adj_list[v1] = new_node;

    else
    {
        // If not first adjacent vertices then add the node at the end.
        graph_node *list_head = graph->adj_list[v1];

        while (list_head->next != NULL)
            list_head = list_head->next;

        list_head->next = new_node;
    }
}

// Function to show the graph.
void show_graph()
{
    printf("TOTAL VERTICES : %d\n", graph->vertices);
    printf("TOTAL EDGES : %d\n", graph->edges);

    // Showing the adjacent vertices of each vertex.
    for (int v = 1; v <= graph->vertices; v++)
    {
        printf(" %d :: ", v);

        // Print Adjacency List.
        graph_node *list_head = graph->adj_list[v];
        while (NULL != list_head)
        {
            printf("%d -> ", list_head->vertex);
            list_head = list_head->next;
        }
        printf("%p\n", NULL);
    }
}

// Function to read the input graph from the file.
void read_input_file(char *file_name)
{
    char c;
    int number_1 = 0;
    int number_2 = 0;
    int line = 0;
    FILE *input_file;

    // Opening the file.
    if (NULL == (input_file = fopen(file_name, "r")))
        error_exit("Failed to read (read_input_file)");

    // Reading the file.
    while (EOF != (c = fgetc(input_file)))
    {
        // For each line.

        // reading the first number.
        while (isdigit(c))
        {
            if (number_1)
                number_1 = (number_1 * 10) + atoi(&c);
            else
                number_1 = atoi(&c);
            c = fgetc(input_file);
        }

        // Reading the second number.
        c = fgetc(input_file);
        while (isdigit(c))
        {
            if (number_2)
                number_2 = (number_2 * 10) + atoi(&c);
            else
                number_2 = atoi(&c);
            c = fgetc(input_file);
        }

        // First line gives total number of vertices and edges.
        if (line < 1)
            // Create the graph with number_1 vertices and number_2 edges.
            create_graph(number_1, number_2);
        else
        {
            // Checking the validity of edges.
            if (line > graph->edges)
                error_exit("Invalid input (read_input_file)");
            if ((number_1 > graph->vertices) || (number_2 > graph->vertices))
                error_exit("Invalid egde (read_input_file)");

            // Adding edges to the graph.
            // For undirected graph v1-v2 is same as v2-v1.
            add_new_edge(number_1, number_2);
            add_new_edge(number_2, number_1);
        }

        // Counting the lines & reset the numbers.
        line++;
        number_1 = number_2 = 0;
    }

    // Closing file.
    fclose(input_file);
}

// Function for DFS search.
void dfs(int v)
{
    // Set the vertex v visited.
    graph->visited[v] = VISITED;

    // Check for all adjacent vertices of vertex v.
    graph_node *list_head = graph->adj_list[v];
    while (NULL != list_head)
    {
        // If unvisited adjacent vertex found call dfs recursively
        if (NOT_VISITED == graph->visited[list_head->vertex])
            dfs(list_head->vertex);
        list_head = list_head->next;
    }
}

int main(int argc, char *argv[])
{
    // If input filename is not given.
    if (argc < 2)
        error_exit("Filename missing. (main)");

    // Read the input file then generate and show the graph.
    read_input_file(argv[1]);
    show_graph();

    // Count total number of connected components (total number of DFS call) and show.
    int component_count = 0;
    for (int v = 1; v <= graph->vertices; v++)
    {
        if (NOT_VISITED == graph->visited[v])
        {
            dfs(v);
            component_count++;
        }
    }
    printf("\nCONNECTED COMPONENT(s): %d\n", component_count);
    return 0;
}

/*

Write a C program to compute number of connected components of an undirected graph.
You should implement Adjacency List data structure to represent an undirected graph.
The implemented adjacency list should be used to compute the number of connected components.
The input graph file name will be provided as a command line argument.
Graph is stored in text file in the following format:
- First line contains number of vertices and number of edges.
- The subsequent lines, each line will have information about an undirected edge.
Sample file for K4 (A complete graph on 4 vertices):
4 6
1 2
1 3
1 4
2 3
2 4
3 4

*/