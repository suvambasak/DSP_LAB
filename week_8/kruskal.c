/*
    Vertex should be starting from One(1).
    edge: 0 1 (invalid)
    edge: 1 2 (valid)

    exe: $ ./a.out < input1.txt
*/

#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_PARENT -1
#define VALID_EDGE 1
#define INVALID_VERTEX_NAME 0

// To store list of edges and weight.
typedef struct edge_list
{
    int vertex1;
    int vertex2;
    int weight;
} edge_list;

// Function to handle error.
void error_exit(char *err)
{
    printf("%s\n", err);
    exit(-1);
}

// Compare function for qsort().
int compare_edge_list(const void *e1, const void *e2)
{
    return (((edge_list *)e1)->weight - ((edge_list *)e2)->weight);
}

// Function to show the Graph and Spanning Tree.
void show(edge_list *graph, int edges, int *edge_flags, char *msg)
{
    printf("\n%s:\n", msg);

    // Print all edges when edge_flags is NULL.
    // Print edges when flag is set when flag is not NULL.
    for (int i = 0; i < edges; i++)
        if (NULL == edge_flags || edge_flags[i])
            printf("\nEdge: %d-%d | Weight: %d", graph[i].vertex1, graph[i].vertex2, graph[i].weight);

    printf("\n");
}

// Function to find the parent of given vertex.
int get_parent(int vertex, int *parent_list, int len)
{
    // Trace the parent.
    while (parent_list[vertex] > 0)
        vertex = parent_list[vertex];

    return vertex;
}

// Function to find spanning tree.
void minimum_spanning_tree(edge_list *graph, int edges, int vertices)
{
    // If the flag value is SET then the edge is included in the spanning tree.
    int *edge_flags = (int *)calloc(edges, sizeof(int));

    // Disjoint set for cycle detection.
    int *parent_list = (int *)malloc((vertices + 1) * sizeof(int));
    for (int i = 0; i <= vertices; i++)
        parent_list[i] = DEFAULT_PARENT;

    for (int i = 0; i < edges; i++)
    {
        // If parent1 == parent then that edge is creating a cycle.
        int parent1 = get_parent(graph[i].vertex1, parent_list, vertices);
        int parent2 = get_parent(graph[i].vertex2, parent_list, vertices);

        if (parent1 != parent2)
        {
            // Cycle is not created so set the edge flag (Edge is included in the spanning tree.)
            edge_flags[i] = VALID_EDGE;

            if (parent1 < parent2)
            {
                parent_list[parent1] -= abs(parent_list[parent2]);
                parent_list[parent2] = parent1;
            }
            else
            {
                parent_list[parent2] -= abs(parent_list[parent1]);
                parent_list[parent1] = parent2;
            }
        }
    }

    // Show the spanning tree.
    show(graph, edges, edge_flags, "Minimum Spanning Tree");
    free(edge_flags);
    free(parent_list);
}

int main()
{
    // Total number of vertices and edges.
    int vertices;
    int edges;
    scanf("%d %d", &vertices, &edges);

    // Input edges and weight. format of input -> vertex1 vertex2 weight
    edge_list *graph = (edge_list *)malloc(sizeof(edge_list) * edges);
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &graph[i].vertex1, &graph[i].vertex2, &graph[i].weight);
        if (INVALID_VERTEX_NAME == graph[i].vertex1 || INVALID_VERTEX_NAME == graph[i].vertex2)
        {
            free(graph);
            error_exit("Invalid input (INVALID_VERTEX_NAME)");
        }
    }

    // Show the graph.
    show(graph, edges, NULL, "Graph");

    // Sort edges based on weight.
    qsort(graph, edges, sizeof(edge_list), compare_edge_list);
    // Find minimum spanning tree.
    minimum_spanning_tree(graph, edges, vertices);
    free(graph);

    printf("\n");
    return 0;
}