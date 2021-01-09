#include <stdio.h>
#include <stdlib.h>

// Structure for each node.
struct node
{
	int data;
	struct node *link;
};

// Global variables
struct node *front = NULL, *rear = NULL;

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

// Function to check QUEUE is empty.
int is_empty()
{
	if (NULL == front && NULL == rear)
		return 1;
	else
		return 0;
}

// Function for enqueue operation.
void enqueue(int item)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if (NULL == new_node)
	{
		printf("\n\tOVERFLOW!\n");
	}
	else
	{
		new_node->data = item;
		new_node->link = NULL;
		if (is_empty())
			front = rear = new_node;
		else
		{
			rear->link = new_node;
			rear = new_node;
		}
	}
}

// Function for dequeue operation.
int dequeue()
{
	if (is_empty())
	{
		printf("\n\tUNDERFLOW!");
		return -1;
	}
	else
	{
		int item = front->data;
		struct node *del = front;

		if (front == rear)
			front = rear = NULL;
		else
			front = front->link;
		del->link = NULL;

		free(del);
		return item;
	}
}

// Function to print visiting nodes.
void show_visiting_node(int node_index)
{
	printf("\n\t VISITING NODE : %d ", node_name[node_index]);
}

// BFS Algorithm.
void bfs(int node)
{
	// Starting node.
	visited[node] = 1;
	show_visiting_node(node);

	while (1)
	{
		for (int i = 0; i < total_node; i++)
		{
			// Exploring all the adjacent nodes.
			if (graph[node][i] == 1 && visited[i] == 0)
			{
				// Enqueue the unvisied nodes.
				enqueue(i);
				visited[i] = 1;
				show_visiting_node(i);
			}
		}
		// When queue is empty.
		if (is_empty())
			return;
		else
			node = dequeue(); // Dequeue next node from the queue.
	}
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
	printf("\n Breadth-first search :\n");
	for (int node = 0; node < total_node; node++)
		if (visited[node] == 0)
			bfs(node);

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