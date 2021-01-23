#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Adjacency matrix of given graph and size
unsigned int size = 6;
unsigned int graph[7][7] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 5, 6, INT_MAX, INT_MAX, INT_MAX},
    {0, 5, 0, 8, 3, 4, INT_MAX},
    {0, 6, 8, 0, INT_MAX, 6, INT_MAX},
    {0, INT_MAX, 3, INT_MAX, 0, 3, 7},
    {0, INT_MAX, 4, 6, 3, 0, 7},
    {0, INT_MAX, INT_MAX, INT_MAX, 7, 7, 0}};

// Function to display matrix.
void show()
{
    printf("\n ADJ MATRIX : \n");
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
            printf(" %3d", graph[i][j]);
        printf("\n");
    }
}

int main()
{
    // Floyd waeshall algorithm.
    for (int k = 1; k <= size; k++)
        for (int i = 1; i <= size; i++)
            for (int j = 1; j <= size; j++)
                graph[i][j] = graph[i][j] > (graph[i][k] + graph[k][j]) ? (graph[i][k] + graph[k][j]) : graph[i][j];

    // Show the adjacency matrix with the shortest paths
    show();

    return 0;
}