#include <stdio.h>

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void bubblesort(int arr[], int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n ; j++)
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void main()
{
    int n, arr[100];

    printf("Enter the size\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d Element of an array : \n", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\n The Data before Sorting : \n");
    printarray(arr, n);
    bubblesort(arr, n);
    printf("\n The Data in Ascending Sorted order : \n");
    printarray(arr, n);
}