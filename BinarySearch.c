#include <stdio.h>

int binarysearch(int arr[], int n, int key)
{
    int l = 0, m, h = n - 1;
    while (l <= h)
    {
        m = (l + h) / 2;

        if (arr[m] == key)
        {
            return m;
        }
        if (key < arr[m])
        {
            h = m - 1;
        }
        else
            l = m + 1;
    }
    return -1;
}

int main()
{
    int arr[100], n, key;

    printf("Enter the size:- \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of an array:- \n", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i - 1] > arr[i] && i >= 1)
        {
            printf("kindly enter sorted array \n");
            return 0;
        }
    }

    printf("Array elements are:- \n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    printf("\nEnter the searched elements :- \n");
    scanf("%d", &key);

    int result = binarysearch(arr, n, key);
    if (result == -1)
        printf("not found\n");
    else
        printf("%d element found at %d position", key, result + 1);
    return 0;
}