//Digit folding 
#include<stdio.h>

void main()
{
     int key,n,i,cnt,data,j,ind,sqr;
     printf("Enter the size of hash table : ");
     scanf("%d",&n);
     printf("Enter the size of Data set : ");
     scanf("%d",&cnt);
     
     int hash[n];
    
     printf("\ninitially hash table : \n hash index data\n");
    
     for(i=0;i<n;i++)
     {
         hash[i]=-1;
         printf(" %6d %6d\n",i,hash[i]);  
                      
     }
     for(i=0;i<cnt;i++)
     {
         printf("Enter the value : ");
         scanf("%d",&data);
         sqr=data*data;
         printf("\nThe square of %d is %d : ",data,sqr);
            if (sqr<10)
            {
               ind = sqr;
               if (hash[ind]!=-1)
               {
                   printf("\nCollision at index %d for value %d\n",ind,data);
                   cnt++;
                   continue;
               }
               else
                  hash[ind] = data;
            }
            else
               if (sqr<100)
               {
                  
                  ind = sqr % 10;
                  if (hash[ind]!=-1)
                  {
                     printf("\nCollision at index %d for value %d\n",ind,data);
                     cnt++;
                     continue;
                  }
                  else
                     hash[ind]=data;
               }
               else
                  if (sqr < 1000)
                  {
                     sqr/=10;
                     ind = sqr%10;
                     if (hash[ind]!=-1)
                     {
                        printf("\nCollision at index %d for value %d\n",ind,data);
                        cnt++;
                        continue;
                     }
                     else
                        hash[ind]=data;
                  }
                  else
                     if (sqr < 10000)
                     {
                        sqr/=10;
                        ind = sqr%100;
                        if (hash[ind]!=-1)
                        {
                           printf("\nCollision at index %d for value %d\n",ind,data);
                           cnt++;
                           continue;
                        }
                        else
                           hash[ind]=data;
                     }
          
          printf("\nUpdated hash table \n hash index data\n");
          for (j=0;j<n;j++)
              printf(" %6d %6d\n",j,hash[j]);  
      }           
}
