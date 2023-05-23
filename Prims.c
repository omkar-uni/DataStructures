#include <stdio.h>
#include<stdlib.h>
#define m 999
// #define k 10

int adj[m][m],p[m],mst[m],wt[m];
int n,i,j,v1,v2;

int min()
{
    int mini=m,mi,i;
    for (int i = 0; i < n; i++)
    {
        if(mst[i]==0 && wt[i]<mini)
        {
            mini = wt[i];
            mi = i;
        }
    }
    return mi;
    
}
 
void prims()
{
    int i,j,u,v;
    for (int i = 0; i < n; i++)
    {
        p[i]=-1;
        wt[i]=m;
        mst[i]=0;
    }
    wt[0]=0;
    p[0]=-1;
    for (int i = 0; i < n-1; i++)
    {
        u=min();
        mst[u]=1;
        for (int j = 0; j < n; j++)
        {
            if(adj[u][j]!=0 && mst[j]==0 && adj[u][j]<wt[j])
            {
                p[j]=u;
                wt[j]=adj[u][j];
                
            }
        }

    } 
}

int main()
{
    int wt, mw = 0;
    printf("Enter the no. of vertices : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = 999;
        }
    while (1)
    {
        printf("\nEnter the edge in (v1 v2) for Undirected graph : ");
        printf("\nEnter (0,0) to exit :");
        scanf("%d %d", &v1, &v2);

        if ((v1 == 0) && (v2 == 0))
            break;
        if (v1 > n || v2 > n || v1 < 1 || v2 < 1)
        {

            break;
        }
        printf("Enter the weight of the edge between %d and %d : ", v1, v2);
        scanf("%d", &wt);
        adj[v1 - 1][v2 - 1] = wt;
        adj[v2 - 1][v1 - 1] = wt;
    }
    printf("\nAdjacency matrix for Undirected graph is :\n");
    printf("  ");
    for (i = 0; i < n; i++)
    {
        printf(" %d  ", i + 1);
    }
    for (i = 0; i < n; i++)
    {
        // ind[i]=0;
        printf("\n%d", i + 1);
        for (j = 0; j < n; j++)
        {
            printf(" %2d ", adj[i][j]);
        }
    }
    printf("\n");
    prims();
    printf("\nEdge \t Weight\n");
    for (int i = 1; i < n; i++)
    { 
        printf("%d<-->%d      %d\n",p[i]+1,i+1,adj[i][p[i]]);
        mw = mw+adj[i][p[i]];  
    }
    
    printf("\n min :- %d",mw);
    return 0;
}
