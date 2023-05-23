#include <stdio.h>

void swap(int * a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n,int i)
{
    int large = i;
    int lc = 2*i+1;
    int rc = 2*i+2;

    if(lc<n && arr[lc]>arr[large])
           large = lc;
     if(rc<n && arr[rc]>arr[large])
           large = rc;      
     if(large!=i)
     {
        swap(&arr[i],&arr[large]);
        heapify(arr,n,large);
     }      
}

void sort(int arr[],int n)
{
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr,n,i);
    }
    
    for (int i = n-1; i >= 0; i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
    
}

void max(int arr[],int n)
{
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr,n,i);
    }
    
}

int main()
{
    int n;
    printf("Enter n :- ");
    scanf("%d",&n);
    int arr[n];

    printf("enter the data :-");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("OG :- ");
    for (int  i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }

    max(arr,n);
    printf("Heap :- ");
    for (int  i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }

    sort(arr,n);
    printf("sorted :- ");
    for (int  i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    
    return 0;
}
