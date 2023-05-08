#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX]={0};

void dfs(int start,int visited[],int n)
{
     int i;
     visited[start]=1;
     printf(" %d ",start+1);
     for(i=0;i<n;i++)
     {
        if(adj[start][i]==1 && visited[i]==0)
           dfs(i,visited,n);
     }      
}

void main()
{
     int ver,edg,i,j,v1,v2,start,n;
     
     printf("Enter the no. of vertices :");
     scanf("%d",&ver);
     
     printf("Enter the no. of edges :");
     scanf("%d",&edg);
     
     for(i=0;i<ver;i++)
     {
        for(j=0;j<ver;j++)
           adj[i][j] = 0;
     }
     
     for(i=0;i<edg;i++)
     {
        printf("Enter the edge %d (v1 v2):",i+1);
        scanf("%d %d",&v1,&v2);
       // addedge(v1-1,v2-1);
        adj[v1-1][v2-1]=1;
        adj[v2-1][v1-1]=1;
     }
     
     printf("Undirected Adjancency matrix is :\n");
     printf("   ");
     for(i=0;i<ver;i++)
     {
         printf("%d ",i+1);
     }
     for(i=0;i<ver;i++)
     {
        printf("\n %d ",i+1);
        for(j=0;j<ver;j++)
            printf("%d ",adj[i][j]);
        printf("\n");    
     }  
     printf("Enter the starting element : ");
     scanf("%d",&start);
     printf("Depth First Search traversal for Undirected Graph is : ");
     printf(" ");
     dfs(start-1,visited,ver);
     printf("\n");
 }

