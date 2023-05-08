#include <stdio.h>

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void insertionsort(int arr[], int n)
{
    int key, j;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void main()
{
    int n, arr[100];

    printf("Enter the size\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the %d Element of an array : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n The Data before Sorting : \n");
    printarray(arr, n);

    insertionsort(arr, n);
    printf("\n The Data in Ascending Sorted order : \n");
    printarray(arr, n);
}