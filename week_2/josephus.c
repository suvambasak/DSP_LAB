#include <stdio.h>
#include <stdlib.h>

// Structure
typedef struct node
{
    int data;
    struct node *next;
} node;

// Head of locate to the first army.
node *HEAD = NULL;

// Function to creates node for each army in circular linkedlist.
void create_nodes(int total)
{
    int i;
    node *temp;
    // Creating all nodes.
    for (i = 1; i <= total; i++)
    {
        node *p = (node *)malloc(sizeof(node));
        p->data = i;
        p->next = NULL;

        // First node.
        if (HEAD == NULL)
        {
            HEAD = p;
            temp = p;
            p = NULL;
        }
        else
        {
            // All other nodes.
            temp->next = p;
            temp = temp->next;
            p = NULL;
        }
    }
    // Setting last node next is HEAD.
    temp->next = HEAD;
}

// Function to show all the nodes.
int display()
{
    if (HEAD == NULL)
    {
        printf("\n\tNODE NOT FOUND!");
        return 0;
    }
    else
    {
        node *temp = HEAD;
        // Prrinting all the nodes.
        printf("\n DISPLAY :");
        while (temp->next != HEAD)
        {
            printf(" %d -> ", temp->data);
            temp = temp->next;
        }
        printf(" %d -> HEAD\n\n", temp->data);
        temp = NULL;
        return 1;
    }
}

// Function to solve josephus problem.
int solve_josephus(int skip)
{
    int temp_skip;
    node *victim = HEAD;
    node *prev = NULL;
    node *del = NULL;

    // Deleting node until remain one node.
    while (victim->next != victim)
    {
        temp_skip = skip;

        // Getting the next node to kill.
        while (temp_skip != 1)
        {
            prev = victim;
            victim = victim->next;
            temp_skip--;
        }

        // printf("\n prev :: %d",prev->data);
        printf("\n DEAD :: %d", victim->data);

        // Deleting the node & changing the links.
        del = victim;
        victim = victim->next;
        prev->next = victim;
        del->next = NULL;

        free(del);
    }
    // Printing & returning the last node alive.
    printf("\n\n ALIVE :: %d\n", victim->data);
    return victim->data;
}

// Main function.
int main()
{
    int total_node;
    int skip;
    // Taking all inputs.
    printf("\nENTER NUMBER OF ARMY: ");
    scanf("%d", &total_node);
    printf("\nENTER NUMBER OF SKIP: ");
    scanf("%d", &skip);

    // Creating all the nodes.
    create_nodes(total_node);
    // Showing the nodes.
    display();
    // Solving josephus problem.
    solve_josephus(skip);

    return 0;
}