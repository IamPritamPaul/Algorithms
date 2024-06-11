#include <stdio.h>
#include <stdlib.h>

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", *(a + i));
    }
}

void swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

/* void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                swap(arr + j, arr + j + 1);
            }
        }
    }
} */

void bubble_sort(int *arr, int n)
{
    if (n == 1)
        return;
    for (int j = 0; j < n - 1; j++)
    {
        if (*(arr + j) > *(arr + j + 1))
        {
            swap(arr + j, arr + j + 1);
        }
    }
    bubble_sort(arr, n - 1);
}

int main()
{
    int *arr;
    int n;
    printf("How many numbers you want to take as input: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter any number: ");
        scanf("%d", arr + i);
    }
    printf("Before sorting");
    printf("\n-----------------\n");
    display(arr, n);
    bubble_sort(arr, n);
    printf("\nAfter sorting");
    printf("\n-----------------\n");
    display(arr, n);
    printf("\n");
    return 0;
}