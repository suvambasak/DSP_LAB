#include <stdio.h>
#include <stdlib.h>
#define EDGE_EXIST 1
#define EXPLORING 2
#define VISITED 1
#define NOT_VISITED 0

// Structure for each node.
typedef struct node
{
	int data;
	struct node *link;
} queue;

// Function to check QUEUE is empty.
int is_empty(queue **front)
{
	if (NULL == (*front))
		return 1;
	return 0;
}

// Function for enqueue operation.
void enqueue(int item, queue **front, queue **rear)
{
	queue *new_node = (queue *)malloc(sizeof(queue));
	if (NULL == new_node)
	{
		printf("\n\tOVERFLOW!\n");
		exit(-1);
	}

	new_node->data = item;
	new_node->link = NULL;

	if (is_empty(front))
		*front = *rear = new_node;
	else
	{
		(*rear)->link = new_node;
		(*rear) = new_node;
	}
}

// Function for dequeue operation.
int dequeue(queue **front, queue **rear)
{
	if (is_empty(front))
	{
		printf("\n\tUNDERFLOW!");
		return -1;
	}

	int item = (*front)->data;
	queue *del = *front;

	if (*front == *rear)
		*front = *rear = NULL;
	else
		*front = (*front)->link;
	del->link = NULL;

	free(del);
	return item;
}

// BFS Algorithm.
void bfs(int **graph, int vertices, int vertex, int *visited)
{
	queue *front = NULL, *rear = NULL;
	// Starting node.
	enqueue(vertex, &front, &rear);
	visited[vertex] = EXPLORING;

	while (!is_empty(&front))
	{
		// Dequeue node from the queue & change to visited.
		vertex = dequeue(&front, &rear);
		visited[vertex] = VISITED;
		printf("\n\t VISITING NODE : %d ", vertex + 1);

		for (int adj_vertex = 0; adj_vertex < vertices; adj_vertex++)
			// Exploring all the adjacent nodes.
			if (EDGE_EXIST == graph[vertex][adj_vertex] && NOT_VISITED == visited[adj_vertex])
			{
				// Enqueue the unvisited nodes & change to exploring.
				enqueue(adj_vertex, &front, &rear);
				visited[adj_vertex] = EXPLORING;
			}
	}
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
	printf("\n Breadth first search :\n");
	for (int vertex = 0; vertex < vertices; vertex++)
		if (NOT_VISITED == visited[vertex])
			bfs(graph, vertices, vertex, visited);

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