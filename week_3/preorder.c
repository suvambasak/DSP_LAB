#include <stdio.h>
#include <stdlib.h>

// Structure for node.
struct node
{
    struct node *left, *right;
    int data;
} *root = NULL;
int *in, *post, size;

// Function to find node.
int findnextnode(int start, int end)
{
    int i, j;
    for (i = size - 1; i >= 0; i--)
    {
        for (j = start; j <= end; j++)
        {
            if (post[i] == in[j])
                return j;
        }
    }
    return -1;
}

// Function to build tree from inorder and post order.
struct node *buildtree(struct node *root, int start, int end)
{
    if (start > end)
        return NULL;

    // Creating node.
    root = (struct node *)malloc(sizeof(struct node));
    root->left = root->right = NULL;

    // getting the value of the node.
    int index = findnextnode(start, end);
    root->data = in[index];

    // Last node in that path.
    if (start == end)
        return root;

    // Left and Right subtree.
    root->left = buildtree(root->left, start, index - 1);
    root->right = buildtree(root->right, index + 1, end);

    return root;
}

// Function to print preorder.
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Main function.
int main()
{
    int i;
    // Size input.
    // printf("\n ENTER NUMBER OF NODES : ");
    scanf("%d", &size);

    // Allocating memory for the inorder and post order.
    in = (int *)malloc(sizeof(int) * size);
    post = (int *)malloc(sizeof(int) * size);

    // Input inorder.
    // printf("\n ENTER IN-ORDER : ");
    for (i = 0; i < size; i++)
        scanf("%d", &in[i]);

    // Input postorder.
    // printf("\n ENTER POST-ORDER : ");
    for (i = 0; i < size; i++)
        scanf("%d", &post[i]);

    // Building the tree.
    root = buildtree(root, 0, size - 1);

    // Print preorder traversal.
    // printf("\n PRE-ORDER : ");
    preorder(root);

    // printf("\n");
    return 0;
}

/*

Appraoch:

int nodes = 7

int[] inOrder = { 4, 2, 5, 1, 6, 3, 7 };

int[] postOrder = { 4, 5, 2, 6, 7, 3, 1 };.

Last element in the postorder [] will be the root of the tree, here it is 1.
Now the search ele­ment 1 in inorder[], say you find it at posi­tion i, once you find it, make note of ele­ments which are left to i (this will con­struct the left­sub­tree) and ele­ments which are right to i ( this will con­struct the rightSubtree).
Suppose in previous step, there are X number of elements which are left of ‘i’ (which will construct the leftsubtree), take first X elements from the postorder[] traversal, this will be the post order traversal for elements which are left to i. similarly if there are Y number of elements which are right of ‘i’ (which will construct the rightsubtree), take next Y elements, after X elements from the postorder[] traversal, this will be the post order traversal for elements which are right to i
From previous two steps construct the left and right subtree and link it to root.left and root.right respectively.
Pre order will be 1,2,4,5,3,6,7


*/