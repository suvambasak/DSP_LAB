#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Compile with -lm flag :: $ cc toi_itr.c -lm
int number_of_move(int n)
{
    int move = pow(2, n);
    return --move;
}

int main()
{
    int n = 3;
    int i;
    int total_moves;
    int flag;
    printf("\n ENTER NUMBER OF DISK : ");
    scanf("%d", &n);
    total_moves = number_of_move(n);
    flag = (n % 2);

    // printf("%d",number_of_move(n));

    for (i = 1; i <= total_moves; i++)
    {
        if (flag)
        {
            if ((i % 3) == 1)
            {
                printf("\n MOVE (%d) B/W [S] AND [D].", i);
            }
            if ((i % 3) == 2)
            {
                printf("\n MOVE (%d) B/W [S] AND [A].", i);
            }
            if ((i % 3) == 0)
            {
                printf("\n MOVE (%d) B/W [A] AND [D].", i);
            }
        }
        else
        {
            if ((i % 3) == 1)
            {
                printf("\n MOVE (%d) B/W [S] AND [A].", i);
            }
            if ((i % 3) == 2)
            {
                printf("\n MOVE (%d) B/W [S] AND [D].", i);
            }
            if ((i % 3) == 0)
            {
                printf("\n MOVE (%d) B/W [A] AND [D].", i);
            }
        }
    }
    printf("\n\n");
    return 0;
}