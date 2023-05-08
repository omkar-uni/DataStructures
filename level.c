#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#include"level.h"

void main()
{    
     int n,val;
     init(root);
     if (root!=NULL)
        printf("BST already Exists :| \n");
     else
     {
        printf("enter the no. of nodes \n");
        scanf("%d",&n);
        if(n<=0)
          printf("invalid size!!!\n");
       else
       {
          for (int i=0;i<n;i++)
          {
              new2=create();
              printf("Enter the %d node for BST : ",i);
              scanf("%d",&new2->data);
              if (root==NULL)
                  root = new2;
              else
                  insert(root,new2);
          }
       }     
    }
    if (root==NULL)
       printf("BST doesn't exists\n");
    else
       display(root);
    if (root==NULL)
       printf("Doesn't exist\n");
    else
    {
       printf("\nTree in level order:\n");
       levelorder(root);
    } 
    printf("\n");   
}               
