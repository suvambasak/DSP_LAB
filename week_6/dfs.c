#include <stdio.h>
#include <stdlib.h>

// Global variables
int **graph;
int total_node;
int *visited;
int *node_name;

// int graph[100][100];
// int graph[100][100]={
//         {0,1,1,1,0},
//         {1,0,1,0,0},
//         {1,1,0,0,1},
//         {1,0,0,0,0},
//         {0,0,1,0,0}
//     };

// int graph[100][100]={
//      {0,1,0,1,0,0},
// 		{1,0,1,0,1,0},
// 		{0,1,0,0,0,0},
// 		{1,0,0,0,0,0},
// 		{0,1,0,0,0,1},
// 		{0,0,0,0,1,0}
//     };

// Function to print visiting nodes.
void show_visiting_node(int node_index)
{
	printf("\n\t VISITING NODE : %d ", node_name[node_index]);
}

// DFS Algorithm.
void dfs(int node)
{
	// Starting node.
	visited[node] = 1;
	show_visiting_node(node);

	// If there is a adjacent node. recursively call DFS with that node.
	for (int i = 0; i < total_node; i++)
		if (1 == graph[node][i] && 0 == visited[i])
			dfs(i);
}

int main()
{
	// total_node=6;
	printf("\n TOTAL NUMBER OF NODES : ");
	scanf("%d", &total_node);

	// Allocating memeory.
	visited = (int *)calloc(total_node, sizeof(int));
	node_name = (int *)calloc(total_node, sizeof(int));
	graph = (int **)malloc(total_node * sizeof(int *));
	for (int i = 0; i < total_node; i++)
		graph[i] = (int *)malloc(total_node * sizeof(int));

	// Name of the nodes.
	printf("\n NAME OF %d NODES : ", total_node);
	for (int i = 0; i < total_node; i++)
		scanf("%d", &node_name[i]);

	// Adjacency Matrix of given graph.
	printf("\n Adjacency Matrix \n");
	for (int i = 0; i < total_node; i++)
	{
		printf(" Node %d : ", node_name[i]);
		for (int j = 0; j < total_node; j++)
			scanf("%d", &graph[i][j]);
	}

	// BFS calling for components of graph.
	printf("\n Depth first search :\n");
	for (int node = 0; node < total_node; node++)
		if (0 == visited[node])
			dfs(node);

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