#include <stdio.h>
#include <stdlib.h>

// Structure of tree node.
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} tree_node;

// Function for inserting new node.
tree_node *insert_node(tree_node *root, int value)
{
    if (root == NULL)
    {
        root = (tree_node *)malloc(sizeof(tree_node));
        root->data = value;
        root->left = root->right = NULL;
    }
    else
    {
        if (value > root->data)
        {
            root->right = insert_node(root->right, value);
        }
        if (value < root->data)
        {
            root->left = insert_node(root->left, value);
        }
    }
    return root;
}

// Function for preorder.
void preorder(tree_node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for inroder.
void inorder(tree_node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for postorder.
void postorder(tree_node *root)
{
    if (root != NULL)
    {
        // printf("printnode\n");
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function.
int main()
{
    tree_node *root = NULL;
    int number_of_nodes;
    int node;

    // printf("\n NUMBER OF NODES : ");
    scanf("%d", &number_of_nodes);

    // printf("\n INSERT NODES : ");
    for (int i = 0; i < number_of_nodes; i++)
    {
        scanf("%d", &node);
        root = insert_node(root, node);
    }

    // printf("\n PRE-ORDER : ");
    preorder(root);
    printf("\n");

    // printf("\n INORDER : ");
    inorder(root);
    printf("\n");

    // printf("\n POST-ORDER : ");
    postorder(root);
    // printf("\n");

    return 0;
}

/*

Given some node values, build the binary search tree, and print the Pre, In and Post order traversal of the built BST. 

Condition is that the Post order Traversal method should implement in Iterative Way. 

 

Input :

first line: Number of nodes [N]

Second line consists of node values of length N

Output: 

Print each traversal values in a new line 

Eg: 

N=5

3 4 5 1 2 

Output: 

3 1 2 4 5

1 2 3 4 5

2 1 5 4 3



*/