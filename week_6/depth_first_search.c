#include <stdio.h>
#include <stdlib.h>
#define EDGE_EXIST 1
#define VISITED 1
#define NOT_VISITED 0

// DFS Algorithm.
void dfs(int **graph, int total_nodes, int current_node, int *visited)
{
	// Starting node.
	visited[current_node] = VISITED;
	printf("\n\t VISITING NODE : %d ", current_node + 1);

	// If there is a adjacent node. recursively call DFS with that node.
	for (int adj_node = 0; adj_node < total_nodes; adj_node++)
		if (EDGE_EXIST == graph[current_node][adj_node] && NOT_VISITED == visited[adj_node])
			dfs(graph, total_nodes, adj_node, visited);
}

int main()
{
	int total_nodes;
	printf("\n TOTAL NUMBER OF NODES : ");
	scanf("%d", &total_nodes);

	// Allocating memeory.
	int *visited = (int *)calloc(total_nodes, sizeof(int));
	int **graph = (int **)malloc(total_nodes * sizeof(int *));
	for (int i = 0; i < total_nodes; i++)
		graph[i] = (int *)malloc(total_nodes * sizeof(int));

	// Adjacency Matrix of given graph.
	printf("\n Adjacency Matrix \n");
	for (int i = 0; i < total_nodes; i++)
	{
		printf(" Node %d : ", i + 1);
		for (int j = 0; j < total_nodes; j++)
			scanf("%d", &graph[i][j]);
	}

	// BFS calling for components of graph.
	printf("\n Depth first search :\n");
	for (int node = 0; node < total_nodes; node++)
		if (NOT_VISITED == visited[node])
			dfs(graph, total_nodes, node, visited);

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