//Division Method
#include<stdio.h>
void main()
{
     int key,n,i,cnt,data,j;
     printf("Enter the size of hash table : ");
     scanf("%d",&n);
     printf("Enter the size of Data set : ");
     scanf("%d",&cnt);
     
     int hash[n];
     if (n<cnt)
     {  
        printf("OverFlow\n");
        return;  
     }
     else
     {
         printf("Enter the key : ");
         scanf("%d",&key);
     }
     printf("\ninitially hash table : \n hash index data\n");
     for (i=0;i<n;i++)
     {
          hash[i]=-1;
          printf(" %6d %6d\n",i,hash[i]);
     }
     for(i=0;i<cnt;i++)
     {
         printf("Enter the data value : ");
         scanf("%d",&data);
         if (hash[data%key]!=-1)
         {
            printf("\nCollision at index %d for value %d\n",data%key,data);
            cnt++;
            continue;
         }   
         else
            hash[data%key]=data;
         printf("\nUpdated hash table \n hash index data\n");
         for (j=0;j<n;j++)
             printf(" %6d %6d\n",j,hash[j]);             
     }
}
