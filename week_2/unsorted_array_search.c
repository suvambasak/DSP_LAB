#include <stdio.h>
#include <stdlib.h>

// Function for show the array.
void show(int *arr, int len)
{
    int i;
    printf("SHOW: ");
    for (i = 0; i < len; i++)
        printf("%d ", *(arr + i));

    printf("\n");
}

// Function for sorting.
void sort(int *arr, int len)
{
    int i, j, temp;
    for (i = 0; i < len; i++)
    {
        for (j = (i + 1); j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function for searching First and Last occurrence.
void find_occurrence(int *arr, int len)
{
    int i, j, value;
    i = 0;
    j = len - 1;

    printf("VALUE: ");
    scanf("%d", &value);

    // Searching the first and last occurence.
    while ((i <= j) && ((arr[i] != value) || (arr[j] != value)))
    {
        if (arr[i] != value)
            i++;
        if (arr[j] != value)
            j--;
    }

    // When value found.
    if (i <= j)
    {
        printf("Starting Occurrence :: %d", i + 1);
        printf("\nEnding Occurrence :: %d", j + 1);
    }
    else
    {
        // When value not found.
        printf("\tVALUE NOT FOUND!");
    }
}

// Main function.
int main()
{
    int *arr, len, i;

    // Size input.
    printf("ENTER THE SIZE: ");
    scanf("%d", &len);

    // Memory allocation.
    arr = (int *)malloc(sizeof(int) * len);

    // Input Array.
    printf("ENTER THE %d ELEMENT(S): ", len);
    for (i = 0; i < len; i++)
        scanf("%d", &arr[i]);

    // Showing the input.
    show(arr, len);
    // Sorting the array.
    sort(arr, len);
    // Showing the sorted array.
    show(arr, len);
    // find the occurrence.
    find_occurrence(arr, len);

    printf("\n");
    return 0;
}