#include<stdio.h>
int i,j,c=0,n,v1,v2,maxedg,in[10],out[10];
void main()
{
     printf("\nEnter the no. of vertices for directed graph : ");
     scanf("%d",&n);
     int adj[n][n];
     maxedg=n*(n-1);
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           adj[i][j]=0;                                     
     for(i=0;i<=maxedg;i++)
     {
        printf("\nEnter the edge in (v1 v2) for directed graph : ");
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
          // adj[v2-1][v1-1]=1;
        }
     }
     printf("\nAdjacency matrix for Directed graph is :\n");
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
     {
        for(j=0;j<n;j++)
        {   if(adj[i][j]==1)
             out[i]++;
           if(adj[j][i] ==1)
             in[i]++;
        }      
     }
     printf("Vertex Indegree Outdegree TotalDegree");
     for(i=0;i<n;i++)
        printf("\n   %d\t   %d\t   %d\t      %d",i+1,in[i],out[i],in[i]+out[i]);
     printf("\n");   
}                                 










