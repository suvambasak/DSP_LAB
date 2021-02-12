#include <stdio.h>
#include <stdlib.h>
#define EDGE_EXIST 1
#define VISITED 1
#define NOT_VISITED 0

// DFS Algorithm.
void dfs(int **graph, int vertices, int vertex, int *visited)
{
	// Starting node.
	visited[vertex] = VISITED;
	printf("\n\t VISITING NODE : %d ", vertex + 1);

	// If there is a adjacent node. recursively call DFS with that node.
	for (int adj_vertex = 0; adj_vertex < vertices; adj_vertex++)
		if (EDGE_EXIST == graph[vertex][adj_vertex] && NOT_VISITED == visited[adj_vertex])
			dfs(graph, vertices, adj_vertex, visited);
}

int main()
{
	int vertices;
	printf("\n TOTAL NUMBER OF NODES : ");
	scanf("%d", &vertices);

	// Allocating memeory.
	int *visited = (int *)calloc(vertices, sizeof(int));
	int **graph = (int **)malloc(vertices * sizeof(int *));
	for (int i = 0; i < vertices; i++)
		graph[i] = (int *)malloc(vertices * sizeof(int));

	// Adjacency Matrix of given graph.
	printf("\n Adjacency Matrix \n");
	for (int i = 0; i < vertices; i++)
	{
		printf(" Node %d : ", i + 1);
		for (int j = 0; j < vertices; j++)
			scanf("%d", &graph[i][j]);
	}

	// BFS calling for components of graph.
	printf("\n Depth first search :\n");
	for (int vertex = 0; vertex < vertices; vertex++)
		if (NOT_VISITED == visited[vertex])
			dfs(graph, vertices, vertex, visited);

	printf("\n");
	return 0;
}

/*

0 1 1 1 0
1 0 1 0 0
1 1 0 0 1
1 0 0 0 0
0 0 1 0 0

0 1 0 1 0 0
1 0 1 0 1 0
0 1 0 0 0 0
1 0 0 0 0 0
0 1 0 0 0 1
0 0 0 0 1 0

*/