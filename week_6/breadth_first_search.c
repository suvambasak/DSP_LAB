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
void bfs(int **graph, int total_nodes, int current_node, int *visited)
{
	queue *front = NULL, *rear = NULL;
	// Starting node.
	enqueue(current_node, &front, &rear);
	visited[current_node] = EXPLORING;

	while (!is_empty(&front))
	{
		// Dequeue node from the queue & change to visited.
		current_node = dequeue(&front, &rear);
		visited[current_node] = VISITED;
		printf("\n\t VISITING NODE : %d ", current_node + 1);

		for (int i = 0; i < total_nodes; i++)
			// Exploring all the adjacent nodes.
			if (EDGE_EXIST == graph[current_node][i] && NOT_VISITED == visited[i])
			{
				// Enqueue the unvisited nodes & change to exploring.
				enqueue(i, &front, &rear);
				visited[i] = EXPLORING;
			}
	}
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
	printf("\n Breadth first search :\n");
	for (int node = 0; node < total_nodes; node++)
		if (NOT_VISITED == visited[node])
			bfs(graph, total_nodes, node, visited);

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