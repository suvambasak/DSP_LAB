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
    if (NULL == root)
    {
        root = (tree_node *)malloc(sizeof(tree_node));
        root->data = value;
        root->left = root->right = NULL;
    }
    else
    {
        if (value > root->data)
            root->right = insert_node(root->right, value);
        if (value < root->data)
            root->left = insert_node(root->left, value);
    }
    return root;
}

// Function for get max value.
int max(int a, int b) { return (a < b ? b : a); }

// Function to get height of tree.
int tree_height(tree_node *root)
{
    if (NULL == root)
        return 0;
    return max(tree_height(root->left), tree_height(root->right)) + 1;
}

// Main function.
int main()
{
    tree_node *root = NULL;
    int number_of_nodes;
    int node;

    printf("\n NUMBER OF NODES : ");
    scanf("%d", &number_of_nodes);

    printf("\n INSERT NODES : ");
    for (int i = 0; i < number_of_nodes; i++)
    {
        scanf("%d", &node);
        root = insert_node(root, node);
    }

    printf("\n HEIGHT : ");
    printf("%d", tree_height(root));

    printf("\n");

    return 0;
}

/*

Given a binary search tree, find height of it. Height of empty tree is 0 and height of below tree is 3.

The height of a node is the length of the longest downward path to a leaf from that node. The height of the root is the height of the tree.

So, in order to calculate the height of the tree, we need to go through each node of the tree in order to obtain all permutations and combinations.


maxDepth('1') = max(maxDepth('2'), maxDepth('3')) + 1
                               = 2 + 1
                                  /    \
                                /         \
                              /             \
                            /                 \
                          /                     \
               maxDepth('2') = 1                maxDepth('3') = 1
= max(maxDepth('4'), maxDepth('5')) + 1
= 1 + 1   = 2         
                   /    \
                 /        \
               /            \
             /                \
           /                    \
 maxDepth('4') = 1     maxDepth('5') = 1

Input :

first line: Number of nodes [N]

Second line consists of node values of length N

Output: print the height of the tree. 

Eg: 

N=5

3 4 5 1 2 

Output: 3

*/