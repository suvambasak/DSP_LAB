#include <stdio.h>
#include <stdlib.h>

#define DEGREE 3

#define REDUNDANT_KEY 1
#define INSERT_KEY 2
#define INSERT_SUCCESS 3
#define FOUND 1
#define NOT_FOUND 0
#define CONTROL 1

// Structure for B Tree
typedef struct b_tree_node
{
    int key_counter;
    int keys[DEGREE - 1];
    struct b_tree_node *node_pointers[DEGREE];
} node;

// Root of the tree.
node *root = NULL;

// Function to search for place in a tree node.
int search_key_index(int key, int *keys, int total_keys)
{
    int index = 0;
    while (index < total_keys && key > keys[index])
        index++;
    return index;
}

// Function for Adding key and splitting node.
int insertion_helper(node *node_ptr, int key, int *parent_key, node **right_child)
{
    if (NULL == node_ptr)
    {
        *right_child = NULL;
        *parent_key = key;
        return INSERT_KEY;
    }

    int total_keys = node_ptr->key_counter;

    int index = search_key_index(key, node_ptr->keys, total_keys);

    if (index < total_keys && key == node_ptr->keys[index])
        return REDUNDANT_KEY;

    int local_key;
    node *new_node;
    int status = insertion_helper(node_ptr->node_pointers[index], key, &local_key, &new_node);
    if (INSERT_KEY != status)
        return status;

    // If the key is not the last key of this node.
    if (total_keys < DEGREE - 1)
    {
        index = search_key_index(local_key, node_ptr->keys, total_keys);

        // Shifting key and pointers to make place for key.
        for (int i = total_keys; i > index; i--)
        {
            node_ptr->keys[i] = node_ptr->keys[i - 1];
            node_ptr->node_pointers[i + 1] = node_ptr->node_pointers[i];
        }
        // Inserting the key.
        node_ptr->keys[index] = local_key;
        node_ptr->node_pointers[index + 1] = new_node;
        ++node_ptr->key_counter;

        return INSERT_SUCCESS;
    }

    int last_key;
    node *last_node_ptr;

    // If the key position is the last of the node.
    if ((DEGREE - 1) == index)
    {
        last_key = local_key;
        last_node_ptr = new_node;
    }
    // If the key position is not the last of the node.
    else
    {
        last_key = node_ptr->keys[DEGREE - 2];
        last_node_ptr = node_ptr->node_pointers[DEGREE - 1];

        // Shifting the key and pointer to make place for the key.
        for (int i = DEGREE - 2; i > index; i--)
        {
            node_ptr->keys[i] = node_ptr->keys[i - 1];
            node_ptr->node_pointers[i + 1] = node_ptr->node_pointers[i];
        }

        // Inserting key
        node_ptr->keys[index] = local_key;
        node_ptr->node_pointers[index + 1] = new_node;
    }

    // Spliting the node.
    int split_index = (DEGREE - 1) / 2;
    (*parent_key) = node_ptr->keys[split_index];

    // Creating child node.
    (*right_child) = (node *)malloc(sizeof(node));
    node_ptr->key_counter = split_index;                    // number of keys in left node
    (*right_child)->key_counter = DEGREE - 1 - split_index; // number of keys in right node.

    // copy the kays and pointers to the righ node.
    for (int i = 0; i < (*right_child)->key_counter; i++)
    {
        (*right_child)->node_pointers[i] = node_ptr->node_pointers[i + split_index + 1];
        if (i < (*right_child)->key_counter - 1)
            (*right_child)->keys[i] = node_ptr->keys[i + split_index + 1];
        else
            (*right_child)->keys[i] = last_key;
    }
    (*right_child)->node_pointers[(*right_child)->key_counter] = last_node_ptr;

    return INSERT_KEY;
}

// Function to insert key in B Tree.
void insert_key(int key)
{
    node *right_child;
    int parent_key;
    // Adding the key.
    int status = insertion_helper(root, key, &parent_key, &right_child);
    if (REDUNDANT_KEY == status)
        printf("Key already exist\n");
    if (INSERT_KEY == status)
    {
        // Creating the parent node after split.
        node *left_child = root;
        root = (node *)malloc(sizeof(node));
        root->key_counter = 1;
        root->keys[0] = parent_key;
        root->node_pointers[0] = left_child;
        root->node_pointers[1] = right_child;
    }
}

// Function for searching for a given key.
int search(int key)
{
    node *temp_root = root;
    while (temp_root)
    {
        int index = search_key_index(key, temp_root->keys, temp_root->key_counter);
        if (index < temp_root->key_counter && key == temp_root->keys[index])
            return FOUND;
        temp_root = temp_root->node_pointers[index];
    }
    return NOT_FOUND;
}

// Function for print the keys in preorder.
void preorder(node *root)
{
    if (root)
    {
        for (int i = 0; i < root->key_counter; i++)
            printf(" %d", root->keys[i]);
        for (int i = 0; i <= root->key_counter; i++)
            preorder(root->node_pointers[i]);
    }
}

// Function to get the height of B Tree.
int height(node *root)
{
    if (root)
    {
        int max = 0;
        for (int i = 0; i <= root->key_counter; i++)
        {
            int h = height(root->node_pointers[i]);
            max = (h + 1) > max ? (h + 1) : max;
        }
        return max;
    }
    else
        return 0;
}

int main()
{
    int input;

    while (CONTROL)
    {
        printf("\n----------------------------------------------\n");
        printf(" 1 - Insert element.\n");
        printf(" 2 - Delete element.\n");
        printf(" 3 - Search.\n");
        printf(" 4 - Hight of the B-Tree\n");
        printf(" 5 - Pre-order traversal.\n");
        printf(" 0 - Exit.\n");
        printf("\n----------------------------------------------\n");
        printf("INPUT : ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("INSERT KEY : ");
            scanf("%d", &input);
            insert_key(input);
            break;
        case 2:
            printf("Not available.");
            break;
        case 3:
            printf("SEARCH KEY : ");
            scanf("%d", &input);
            printf("%s\n", (search(input) == 1 ? "FOUND." : "NOT FOUND!"));
            break;
        case 4:
            printf("HEIGHT : %d\n", height(root));
            break;
        case 5:
            printf("PRE-ORDER : ");
            preorder(root);
            break;
        case 0:
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}