#include<stdio.h>
#include<stdlib.h>

void main()
{
     int n , i , key;
  
     printf("Enter the size:- \n");
     scanf("%d" , &n);
    
     int arr[n];
    
     for (i = 0;i < n;i++)
     { 
          arr[i] = rand() % 100;
     }
    
     printf("Array elements are:- \n");
     for(i = 0;i < n;i++)
     {
     printf("%d\t" , arr[i]);
     }

     printf("Enter the searched elements :- \n");
     scanf("%d" , &key);
     int found = 0;
     for (i = 0;i < n;i++)
     {
         if (arr[i]==key)
         { 
             printf("%d element is found at %d index" , key , i+1);
             found = 1;
         }
     }
     if (found==0)
     {
        printf("%d element not found in an array" , key);
     }

}