#include <stdio.h>
#include <stdlib.h>

// Main function.
int main()
{

    int arr[100];
    int len, i, j, minpos, temp;

    // Size input.
    printf("ENTER THE SIZE: ");
    scanf("%d", &len);

    // Input Array.
    printf("ENTER THE %d ELEMENT(S): ", len);
    for (i = 0; i < len; i++)
        scanf("%d", &arr[i]);

    // Selection sort.
    for (i = 0; i < len; i++)
    {
        minpos = i;
        for (j = i + 1; j < len; j++)
            if (arr[minpos] > arr[j])
                minpos = j;

        temp = arr[minpos];
        arr[minpos] = arr[i];
        arr[i] = temp;
    }

    // Show.
    printf("SORTED: ");
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}

/*
 input:
first line : number of elements : 10
next unsorted array :10, 14, 28, 11, 7, 16, 30, 50, 25, 18
output: 7, 10, 11, 14, 16, 18, 25, 28, 30, 50

input =
10
10 14 28 11 7 16 30 50 25 18

output =  10 11 14 16 18 25 28 30 50
*/