#include <stdio.h>
#include <stdlib.h>

void main()
{
    int arr[100], n, key;

    printf("Enter the size:- \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of an array:- \n");
        scanf("%d", &arr[i]);
    }
    printf("Array elements are:- \n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    printf("\nEnter the searched elements :- \n");
    scanf("%d", &key);

    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;

    while (arr[i] != key)
        i++;

    arr[n - 1] = last;

    if (i < n - 1 || arr[n - 1] == key)
    {
        printf("%d element found at %d position in the data set\n", key, i + 1);
    }
    else
        printf("%d element not found\n ", key);
}