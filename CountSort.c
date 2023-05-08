#include <stdio.h>

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int maximum(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
        if (max < arr[i])
            max = arr[i];

    return max;
}

void countsort(int arr[], int n)
{
    int max = maximum(arr, n);
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    int output[100];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // for (int i = n - 1, j = max; i >= 0, j > 0;)
    // {
    //     if (count[j] != count[j - 1])
    //     {
    //         output[i] = j;
    //         count[j]--;
    //         i--;
    //     }
    //     else
    //         j--;
    // }
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
    countsort(arr, n);
    printf("\n The Data in Ascending Sorted order : \n");
    printarray(arr, n);
}