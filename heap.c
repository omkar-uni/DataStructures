#include<stdio.h>

void swap(int * a,int *b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
     
}

void heapify(int arr[],int n,int i)
{
     int large = i;
     int left = 2*i+1;
     int right = 2*i+1;
     
     if(left < n && arr[left]>arr[large])
        large = left;
     else if(right < n && arr[right]>arr[large])
             large = right;
             
    if(large!=i)
    {
       swap(&arr[i],&arr[large]);
       heapify(arr,n,large);
    }         
              
}

void heapsort(int arr[],int n)
{
     for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
     for(int i=n-1;i>=0;i--)
     {
         swap(&arr[i],&arr[large]);
         heapify(arr,n,large);
     }   
}
