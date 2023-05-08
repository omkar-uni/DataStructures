#include <stdio.h>

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int i = low, j = high, temp;
    int pivot = arr[low];

    do
    {

        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

void quicksort(int arr[], int low, int high)
{
    int i = low;
    int j = high;

    if (i < j)
    {
        int par = partition(arr, low, high);
        quicksort(arr, low, par - 1);
        quicksort(arr, par + 1, high);
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
    quicksort(arr, 0, n - 1);
    printf("\n The Data in Ascending Sorted order : \n");
    printarray(arr, n);
}