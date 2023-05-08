#include<stdio.h>
#include<stdlib.h>
#define m 999
#define N 10
int parent[N],mst[N],adj[N][N],mw=0;
int n,i,j,v1,v2,u,v,a,b,edge;

int find(int i)
{
    while (parent[i]>0)
          i=parent[i];
    return i;      
}

void uni(int i,int j)
{
     parent[j]=i;
}

void kruskal()
{
     int min;
    // printf("The edge of min cost spanning Tree is : \n");
     printf("Edge Weight");
     printf("\n");
     for(edge=1;edge<=n-1;)
     {
        for(i=0,min=999;i<n;i++)
        {
           for(j=0;j<n;j++)
           {
              if (adj[i][j]<min)
              {
                 min = adj[i][j];
                 a=u=i;
                 b=v=j;
              }
           }        
        }
     
      u = find(a);
      v = find(b);
      if (u!=v)
      {
         uni(u,v);
         printf("%d:%d->%d %d\n",edge++,a+1,b+1,min);
         mw+=min;
      }
       adj[a][b]=adj[b][a]=999;
     }
     printf("\n minimum cost = %d\n",mw);    
}               

void main()
{
    int wt;
    printf("Enter the no. of vertices : ");
    scanf("%d",&n);
    
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {   if (i==j)
               adj[i][j]=0;
            else
               adj[i][j]=999;
        }          
    while(1)
     {
          printf("\nEnter the edge in (v1 v2) for Undirected graph : ");
          printf("\nEnter (0,0) to exit :");
          scanf("%d %d",&v1,&v2);
          
          if((v1==0) && (v2==0)) 
             break;
          if(v1>n || v2>n || v1<1 || v2<1)
          {
             
             break;
          }
          printf("Enter the weight of the edge between %d and %d : ",v1,v2);
          scanf("%d",&wt);
           adj[v1-1][v2-1]=wt;
           adj[v2-1][v1-1]=wt;
     }
     printf("\nAdjacency matrix for Undirected graph is :\n");
     printf("  ");
     for(i=0;i<n;i++)
     {
        printf(" %d  ",i+1);
     }
     for(i=0;i<n;i++)
     {
       // ind[i]=0;
        printf("\n%d",i+1);
        for(j=0;j<n;j++)
        {
            printf(" %2d ",adj[i][j]);
            
        }
              
     }
     printf("\n");
     
   
     printf("Kruskal Minimum spanning tree : ");
     kruskal();
     //display(n);
     //degree(adj,n);

    
     printf("\n");
        
}      
/*
sy44@pc46:~/DS_SEM_IV-32/Assignment_5$ cc kruskal.c
sy44@pc46:~/DS_SEM_IV-32/Assignment_5$ ./a.out
Enter the no. of vertices : 5

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :1
2
Enter the weight of the edge between 1 and 2 : 3

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :2
3
Enter the weight of the edge between 2 and 3 : 10

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :3
4
Enter the weight of the edge between 3 and 4 : 4

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :4
2
Enter the weight of the edge between 4 and 2 : 2

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :4
5
Enter the weight of the edge between 4 and 5 : 1

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :5
2
Enter the weight of the edge between 5 and 2 : 6

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :0
0

Adjacency matrix for Undirected graph is :
   1   2   3    4    5  
1  0   3  999  999  999 
2  3   0   10   2    6 
3 999  10  0    4   999 
4 999   2  4    0    1 
5 999   6  999  1    0 
Kruskal Minimum spanning tree : Edge Weight
1:4->5 1
2:2->4 2
3:1->2 3
4:3->4 4

 minimum cost = 10



*/



 
