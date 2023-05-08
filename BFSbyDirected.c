#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int q[MAX],front=-1,rear=-1;
int adj[MAX][MAX];
int visited[MAX];
void bfs(int start,int vertices)
{
     visited[start]=1;
     q[++rear]=start;
     while(front!=rear)
     {
          start=q[++front];
          printf(" %d ",start+1);
          for(int i=0;i<vertices;i++)
          {
             if(adj[start][i]==1 && visited[i]==0)
             {
                visited[i]=1;
                q[++rear]=i;
                
             }
          }
     }           
}

void main()
{
     int ver,edg,i,j,v1,v2,start;
     printf("Enter the no. of vertices for Directed Graph:");
     scanf("%d",&ver);
     
     printf("Enter the no. of edges for Directed Graph :");
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
        adj[v1-1][v2-1]=1;
        //adj[v2-1][v1-1]=1;
     }
     
     printf("Adjancency matrix for Directed graph is :\n");
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
     printf("Breadth First Search traversal is : ");
     printf(" ");
     bfs(start-1,ver);
     printf("\n");
 }
