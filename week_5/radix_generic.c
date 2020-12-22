#include <stdio.h>
#include <stdlib.h>

// Structure for double linked list.
typedef struct node
{
    void *data;
    struct node *next;
    struct node *prev;
} node;

// Global Variables.
// List.
node *head_1 = NULL;
node *tail_1 = NULL;
node *head_2 = NULL;
node *tail_2 = NULL;
// input.
int max_data = -1;
int size;

// allocate memory for int and return void pointer.
void *allocate_int(int number)
{
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = number;
    return ((void *)ptr);
}

// For Invalid input.
void invalid()
{
    printf("INVALID INPUT");
    exit(0);
}

// Swaping head and tail of the list.
void swap_list()
{
    node *t;

    // Head swap.
    t = head_1;
    head_1 = head_2;
    head_2 = t;

    // Tail swap.
    t = tail_1;
    tail_1 = tail_2;
    tail_2 = t;
}

// Insert element into linked list.
void insert(int data)
{
    // List 1.
    node *new_node_1 = (node *)malloc(sizeof(node));
    new_node_1->data = allocate_int(data);
    new_node_1->next = NULL;
    new_node_1->prev = NULL;

    // List 2.
    node *new_node_2 = (node *)malloc(sizeof(node));
    new_node_2->data = NULL;
    new_node_2->next = NULL;
    new_node_2->prev = NULL;

    // Memory full.
    if (NULL == new_node_1)
    {
        printf("\nERROR!");
        exit(0);
    }

    // First node.
    if (NULL == head_1)
    {
        // List 1
        head_1 = new_node_1;
        tail_1 = new_node_1;

        // List 2
        head_2 = new_node_2;
        tail_2 = new_node_2;
    }
    else
    {
        // List 1
        tail_1->next = new_node_1;
        new_node_1->prev = tail_1;
        tail_1 = tail_1->next;

        // List 2
        tail_2->next = new_node_2;
        new_node_2->prev = tail_2;
        tail_2 = tail_2->next;
    }
}

// Insert value in given index.
void insert_index(node *head, void *data, int index)
{
    // Invalid index.
    if (index > size)
        invalid();

    // Valid index.
    for (int i = 0; i < index; i++)
        head = head->next;
    // printf("\n INDEX %d >> %d",index,head->data);
    head->data = data;
}

// Print the list.
void display()
{
    if (NULL == head_1)
        return;

    node *t = head_1;
    while (t)
    {
        printf("%d ", *(int *)t->data);
        t = t->next;
    }
}

// Frequency count based on place value.
void count_frequency(int *count, int place)
{
    node *t = head_1;
    while (t)
    {
        count[((*(int *)t->data) / place) % 10]++;
        t = t->next;
    }
}

// Sorting based on place value.
void build_output_list(int *count, int place)
{
    int index = size - 1;
    node *t = tail_1;

    while (t)
    {
        // printf("\n %d -> %d ",index,t->data);
        int update_index = ((*(int *)t->data) / place) % 10;
        count[update_index]--;
        insert_index(head_2, t->data, count[update_index]);

        t = t->prev;
        index--;
    }
}

// Counting sort.
void count_sort(int place)
{
    // Array for holding the frequency of each digit.
    int *count = (int *)calloc(10, sizeof(int));
    // Counting the frequency of each digit.
    count_frequency(count, place);

    // Cumulative frequency
    for (int i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];

    // Sort based on place.
    build_output_list(count, place);
    // Swaping list head and tail pointer.
    swap_list();
}

// Radix sort.
void radix_sort()
{
    for (int place = 1; (max_data / place) > 0; place = (place * 10))
        count_sort(place);
}

// Main fun
int main()
{
    int input;
    // Number of items.
    scanf("%d", &size);

    if (size > 0)
    {
        // Valid size.
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &input);
            // Positive integer numbers.
            if (input >= 0)
            {
                insert(input);

                // Max value.
                if (max_data < input)
                    max_data = input;
            }
            else
                invalid(); // Invalid input.
        }
    }
    else
        invalid(); // Invalid size.

    // Radix sort.
    radix_sort();
    // Sorted output.
    display();

    printf("\n");
    return 0;
}

/*

Implement a generic doubly linked list in C.

Using the implemented generic doubly linked list, implement Radix sorting technique to sort positive integer numbers.



Input/Output Specification:

Input is a sequent of positive numbers:

n i1 i2 i3 i4 ... in



n: number of elements to sort (n > 0)

ik: kth element of the list (ik >= 0 for all k)



-If input is invalid display INVALID INPUT

-otherwise display the sorted array



*/