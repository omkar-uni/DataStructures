#include<stdio.h>
int i,j,c=0,n,v1,v2,maxedg,degree[10];
void main()
{
     printf("\nEnter the no. of vertices for undirected graph : ");
     scanf("%d",&n);
     int adj[n][n];
     maxedg=n*(n-1);
     for(i=0;i<n;i++)
        degree[i]=0;
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           adj[i][j]=0;                                     
     for(i=0;i<=maxedg;i++)
     {
        printf("\nEnter the edge in (v1 v2) for undirected graph : ");
        printf("\nEnter (0,0) to exit :");
        scanf("%d %d",&v1,&v2);
        if((v1==0) && (v2==0)) 
           break;
        if(v1>n || v2>n || v1<1 || v2<1)
        {
           printf("\n invalid edge");
           i--;
        }
        else
        {
           adj[v1-1][v2-1]=1;
           adj[v2-1][v1-1]=1;
        }
     }
     printf("\nAdjacency matrix for Undirected graph is :\n");
     printf("    ");
     for(i=0;i<n;i++)
     {
         printf("%d  ",i+1);
     }
     for(i=0;i<n;i++)
     {
        printf("\n %d ",i+1);
        for (j=0;j<n;j++)
            printf(" %d ",adj[i][j]);
        printf("\n");
     }
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           if(adj[i][j] == 1)
             degree[i]++;
     printf("\nvertex\tdegree");     
     for(i=0;i<n;i++)
     {
        printf("\n  %d\t  %d",i+1,degree[i]);
        //printf("\n%d\t",degree[i]);
     }
     printf("\n");          
}                                 





































/*#include<stdio.h>
#define MAX 100

int adj[MAX][MAX];

void main()
{
     int ver,edg,i,j,v1,v2;
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
        adj[v1-1][v2-1]=1;
        adj[v2-1][v1-1]=1;
     }
     
     printf("Undirected Adjancency matrix is :\n");
     for(i=0;i<ver;i++)
     {
        for(j=0;j<ver;j++)
            printf("%d ",adj[i][j]);
        printf("\n");    
     }    
 } */          
