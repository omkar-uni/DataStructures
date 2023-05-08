#include <stdio.h>

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int h)
{
    int i, j, k, b[100];
    i = l;
    j = m + 1;
    k = l;
    while (i <= m && j <= h)

        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            b[k] = arr[j];
            k++;
            j++;
        }

    while (i <= m)
    {
        b[k] = arr[i];
        k++;
        i++;
    }
    while (j <= h)
    {
        b[k] = arr[j];
        k++;
        j++;
    }
    for (int i = 0; i <= h; i++)
        arr[i] = b[i];
}

void ms(int arr[], int l, int h)
{
    int m;
    if (l < h)
    {
        m = (l + h) / 2;
        ms(arr, l, m);
        ms(arr, m + 1, h);
        merge(arr, l, m, h);
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
    ms(arr, 0, n - 1);
    printf("\n The Data in Ascending Sorted order : \n");
    printarray(arr, n);
}