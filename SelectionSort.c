#include <stdio.h>

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void selectionsort(int arr[], int n)
{
    int indexofmin, temp;

    for (int i = 0; i < n - 1; i++)
    {
        indexofmin = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[indexofmin])
                indexofmin = j;
        if (indexofmin != i)
        {
            temp = arr[i];
            arr[i] = arr[indexofmin];
            arr[indexofmin] = temp;
        }
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

    selectionsort(arr, n);
    printf("\n The Data in Ascending Sorted order : \n");
    printarray(arr, n);
}