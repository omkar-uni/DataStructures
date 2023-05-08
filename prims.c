#include<stdio.h>
#include<stdlib.h>
#define m 999
#define N 10
int parent[N],mst[N],wt[N],adj[N][N];
int n,i,j,v1,v2;
int min_key()
{
    int minimum = m,min,i;
    for(i=0;i<n;i++)
       if(mst[i]==0&&wt[i]<minimum)
       {
          minimum=wt[i];
          min=i;
       }
       return min;      
}
void prims()
{
     int i,j,u,v;
     for (i=0;i<n;i++)
     {
         parent[i]=-1;
         wt[i]=m;
         mst[i]=0;
     }
     wt[0]=0;
     parent[0]=-1;
     for (i=0;i<n-1;i++)
     {
         u=min_key();
         mst[u]=1;
         for (j=0;j<n;j++)
         {
             if (adj[u][j]!=0 && mst[j] == 0 && adj[u][j]<wt[j])
             {
                parent[j]=u;
                wt[j]=adj[u][j];
             }
         }
     }
}
                

void main()
{
    int wt,mw=0;
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
      prims();
      printf("\nEdge \t Weight\n");
      for(i=1;i<n;i++)
      {
         printf("%d<-->%d      %d\n",(parent[i]+1),i+1,adj[i][parent[i]]);
         mw=mw+adj[i][parent[i]];
      }   
     //display(n);
     //degree(adj,n);
     printf("Prims Minimum spanning Tree : %d\n",mw);
    
     printf("\n");
        
}  

/*
sy44@pc46:~/DS_SEM_IV-32/Assignment_5$ cc prims.c
sy44@pc46:~/DS_SEM_IV-32/Assignment_5$ ./a.out
Enter the no. of vertices : 5

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :1
2
Enter the weight of the edge between 1 and 2 : 3

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :2
5
Enter the weight of the edge between 2 and 5 : 6

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :2
3
Enter the weight of the edge between 2 and 3 : 10

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :2
4
Enter the weight of the edge between 2 and 4 : 2

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :3
4
Enter the weight of the edge between 3 and 4 : 4

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :4
5
Enter the weight of the edge between 4 and 5 : 1

Enter the edge in (v1 v2) for Undirected graph : 
Enter (0,0) to exit :0
0

Adjacency matrix for Undirected graph is :
   1   2   3   4   5  
1  0   3   0   0   0 
2  3   0  10   2   6 
3  0  10   0   4   0 
4  0   2   4   0   1 
5  0   6   0   1   0 

Edge 	 Weight
1<-->2      3
4<-->3      4
2<-->4      2
4<-->5      1
Prims Minimum spanning Tree : 10

*/     
