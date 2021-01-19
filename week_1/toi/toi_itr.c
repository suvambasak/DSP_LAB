// Compile with -lm flag    ::      $ cc toi_itr.c -lm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 20

//  Function to check STACK is full.
int is_full(int *top)
{
    if (SIZE - 1 == *top)
        return 1;
    else
        return 0;
}

// Function to check STACK is empty.
int is_empty(int *top)
{
    if (-1 == *top)
        return 1;
    else
        return 0;
}

// Function to push item into the STACK.
void push(int *stack, int *top, int item)
{
    if (is_full(top))
    {
        return;
    }
    *top = (*top + 1);
    stack[*top] = item;
}

// Function to pop item from the STACK.
int pop(int *stack, int *top)
{
    if (is_empty(top))
    {
        return -1;
    }
    int item;
    item = stack[*top];
    *top = (*top - 1);
    return item;
}

// Function to get top element of the stack with out poping.
int get_top(int *stack, int *top)
{
    if (is_empty(top))
    {
        return (SIZE + 1);
    }
    int item = stack[*top];
    return item;
}

// Function for printing all the element of a stack from top to bottom.
void show(int *stack, int *top)
{
    int i;
    printf(" CONTENT TOP TO BOTTOM:");
    for (i = *top; i >= 0; i--)
    {
        printf(" %d", stack[i]);
    }
}

// Function that returns the total number of move.
int number_of_move(int n)
{
    int move = pow(2, n);
    return --move;
}

// Main function.
int main()
{
    int n = 2;
    int i;
    int total_moves;
    int flag;

    printf("\n ENTER NUMBER OF DISK : ");
    scanf("%d", &n);

    // Getting total number of moves,
    total_moves = number_of_move(n);
    // Setting the flag in case of number of disk is odd.
    flag = (n % 2);

    // stack_s is source stack.
    // stack_a is auxiliary stack.
    // stack_d is destination stack.
    int stack_s[SIZE], stack_a[SIZE], stack_d[SIZE];
    int top_s = -1, top_a = -1, top_d = -1;

    // Inserting N (input value) disk into the source stack.
    for (i = n; i >= 1; i--)
    {
        push(stack_s, &top_s, i);
    }

    // Showing the source stack.
    printf("\n\n");
    printf(" SOURCE - ");
    show(stack_s, &top_s);
    printf("\n\n");

    // Moving the disk.
    for (i = 1; i <= total_moves; i++)
    {
        if ((i % 3) == 1)
        {
            // Move for odd number of disk.
            if (flag)
            {
                printf("\n MOVE (%d) B/W [S] AND [D] :: ", i);

                if (get_top(stack_s, &top_s) < get_top(stack_d, &top_d))
                {
                    int item = pop(stack_s, &top_s);
                    push(stack_d, &top_d, item);
                    printf("DISK %d FROM [S] TO [D]", item);
                }
                else
                {
                    int item = pop(stack_d, &top_d);
                    push(stack_s, &top_s, item);
                    printf("DISK %d FROM [D] TO [S]", item);
                }
            }
            // Move for even number of disk.
            else
            {
                printf("\n MOVE (%d) B/W [S] AND [A] :: ", i);

                if (get_top(stack_s, &top_s) < get_top(stack_a, &top_a))
                {
                    int item = pop(stack_s, &top_s);
                    push(stack_a, &top_a, item);
                    printf("DISK %d FROM [S] TO [A]", item);
                }
                else
                {
                    int item = pop(stack_a, &top_a);
                    push(stack_s, &top_s, item);
                    printf("DISK %d FROM [A] TO [S]", item);
                }
            }
        }
        if ((i % 3) == 2)
        {
            // Move for odd number of disk.
            if (flag)
            {
                printf("\n MOVE (%d) B/W [S] AND [A] :: ", i);

                if (get_top(stack_s, &top_s) < get_top(stack_a, &top_a))
                {
                    int item = pop(stack_s, &top_s);
                    push(stack_a, &top_a, item);
                    printf("DISK %d FROM [S] TO [A]", item);
                }
                else
                {
                    int item = pop(stack_a, &top_a);
                    push(stack_s, &top_s, item);
                    printf("DISK %d FROM [A] TO [S]", item);
                }
            }
            // Move for even number of disk.
            else
            {
                printf("\n MOVE (%d) B/W [S] AND [D] :: ", i);

                if (get_top(stack_s, &top_s) < get_top(stack_d, &top_d))
                {
                    int item = pop(stack_s, &top_s);
                    push(stack_d, &top_d, item);
                    printf("DISK %d FROM [S] TO [D]", item);
                }
                else
                {
                    int item = pop(stack_d, &top_d);
                    push(stack_s, &top_s, item);
                    printf("DISK %d FROM [D] TO [S]", item);
                }
            }
        }
        if ((i % 3) == 0)
        {
            // Same move for odd/even number of disk.
            printf("\n MOVE (%d) B/W [A] AND [D] :: ", i);

            if (get_top(stack_a, &top_a) < get_top(stack_d, &top_d))
            {
                int item = pop(stack_a, &top_a);
                push(stack_d, &top_d, item);
                printf("DISK %d FROM [A] TO [D]", item);
            }
            else
            {
                int item = pop(stack_d, &top_d);
                push(stack_a, &top_a, item);
                printf("DISK %d FROM [D] TO [A]", item);
            }
        }
    }

    // Showing the destination stack after all moves.
    printf("\n\n");
    printf(" DESTINATION - ");
    show(stack_d, &top_d);
    printf("\n\n");

    return 0;
}