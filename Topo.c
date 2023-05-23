#include <stdio.h>
#define m 100
int adj[m][m], i, j,st[m],top=-1,vis[m];

void dfs(int v)
{
    vis[v]=1;
    for (int i = 1; i <= m; i++)
    {
        if (adj[v][i]==1 && !vis[i])
        {
            dfs(i);
        }
        
    }
    st[++top]=v;
}

void topo(int v)
{
    int i;
    for ( i = 1; i <= v; i++)
    {
        if(!vis[i])
           dfs(i);
    }
    printf("Topo is :- ");
    while(top!=-1)
        printf("%d ",st[top--]);
    
}

int main()
{
    int v, v1, v2;
    printf("Enter no . of v :-");
    scanf("%d", &v);
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            adj[i][j] = 0;
        }
    }
    while (1)
    {
        printf("Enter the edge :-");
        scanf("%d%d", &v1, &v2);
        if (v1 == 0 && v2 == 0)
            break;
        else
            adj[v1][v2] = 1;
    }
    printf("Adjacency matrix :\n");
    printf("  ");
    for (i = 1; i <= v; i++)
    {
        printf(" %d ", i);
    }
    for (i = 1; i <= v; i++)
    {
        printf("\n");
        printf("%d ", i);
        for (j = 1; j <= v; j++)
        {
            printf(" %d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    topo(v);
    return 0;
}
