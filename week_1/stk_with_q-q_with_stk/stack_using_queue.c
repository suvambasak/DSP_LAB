#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

// Function to check QUEUE is empty.
int is_empty(int *front)
{
    if (-1 == *front)
        return 1;
    else
        return 0;
}

// Function to check QUEUE is full.
int is_full(int *rear)
{
    if (SIZE - 1 == *rear)
        return 1;
    else
        return 0;
}

// Function for enqueue operation.
void enqueue(int *queue, int *front, int *rear, int item)
{
    if (is_full(rear))
    {
        printf("\n\tOVERFLOW!");
        return;
    }
    if (-1 == *rear)
    {
        *front = (*front + 1);
        *rear = (*rear + 1);
        queue[*rear] = item;
        return;
    }
    *rear = (*rear + 1);
    queue[*rear] = item;
}

// Function for dequeue operation.
int dequeue(int *queue, int *front, int *rear)
{
    if (is_empty(front))
    {
        printf("\n\tUNDERFLOW!");
        return -1;
    }
    if (*rear == *front)
    {
        int item = queue[*front];
        *front = -1;
        *rear = -1;
        return item;
    }
    int item = queue[*front];
    *front = (*front + 1);
    return item;
}

// Main function.
int main()
{
    // Declaring two queue.
    int queue1[SIZE], front1 = -1, rear1 = -1;
    int queue2[SIZE], front2 = -1, rear2 = -1;

    int choice, input;
    while (1)
    {
        // Options
        printf("\n<<<<<<<<<<<<<<< OPTIONS >>>>>>>>>>>>>>>>");
        printf("\n1 PUSH");
        printf("\n2 POP");
        printf("\n\n0 EXIT\n");

        printf("---------------------------------------");

        printf("\nENTER CHOICE : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(1);
        case 1:
            printf("\nENTER ITEM : ");
            scanf("%d", &input);

            if (is_empty(&front1))
            {
                if (!is_full(&rear2))
                {
                    // Inserting into queue 2 when queue 1 is empty and queue 2 is not full.
                    enqueue(queue2, &front2, &rear2, input);
                }
                else
                {
                    // When queue 1 is empty and queue 2 is full.
                    printf("\n\tOVERFLOW!");
                }
            }
            else
            {
                if (!is_full(&rear1))
                {
                    // Inserting into queue 1 when queue 2 is empty and queue 1 is not full.
                    enqueue(queue1, &front1, &rear1, input);
                }
                else
                {
                    // When queue 2 is not empty and queue 1 is full.
                    printf("\n\tOVERFLOW!");
                }
            }
            break;
        case 2:
            if (is_empty(&front1))
            {
                if (is_empty(&front2))
                {
                    // When both queues are empty.
                    printf("\n\tUNDERFLOW!");
                }
                else
                {
                    // When Queue 2 is not empty. Moving all to queue 1 except the last element.
                    while (!is_empty(&front2))
                    {
                        int item = dequeue(queue2, &front2, &rear2);
                        if (is_empty(&front2))
                        {
                            printf("\nITEM POPED : %d", item);
                        }
                        else
                        {
                            enqueue(queue1, &front1, &rear1, item);
                        }
                    }
                }
            }
            else
            {
                // When Queue 1 is not empty. Moving all to queue 2 except the last element.
                while (!is_empty(&front1))
                {
                    int item = dequeue(queue1, &front1, &rear1);
                    if (is_empty(&front1))
                    {
                        printf("\nITEM POPED : %d", item);
                    }
                    else
                    {
                        enqueue(queue2, &front2, &rear2, item);
                    }
                }
            }
            break;
        default:
            printf("\nINVALID INPUT!");
        }
    }
    return 0;
}