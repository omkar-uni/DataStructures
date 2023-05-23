#include <stdio.h>
#define max 10
#define m 999
int parent[max], min, mw = 0, adj[max][max];
int i, j, k, a, b, u, v, n, edge;
int find(int i)
{
    while (parent[i] > 0)
        i = parent[i];
    return i;
}

void uni(int i, int j)
{
    parent[j] = i;
}

void kruskal()
{
    for (edge = 1; edge <= n - 1;)
    {
        for (i = 0, min = 999; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (adj[i][j] < min)
                {
                    min = adj[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        u = find(a);
        v = find(b);
        if (u != v)
        {
            uni(v, u);
            printf("\n%d   %d->%d    %d", edge++, a + 1, b + 1, min);
            mw += min;
        }
        adj[a][b] = adj[b][a] = 999;
    }
    printf("\n%d ", mw);
}
void main()
{
    int w;
    printf("\n Enter no of vertices : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = 999;
        }
    printf("\n Enter edges for Undirected Graph: \n ");
    while (1)
    {
        printf("\n Enter the edge  from vertex and To vertex   :  ");
        scanf("%d%d", &i, &j);
        if (i == 0 || j == 0)
            break;
        printf("\n Enter weight of edge between  v1 and v2  :  ");
        scanf("%d", &w);
        adj[i - 1][j - 1] = w;
        adj[j - 1][i - 1] = w;
    }
    printf("\n Adjacency matrix of Undirected  Graph  : \n    ");
    for (i = 0; i < n; i++)
        printf("   %d   ", i + 1);
    for (i = 0; i < n; i++)
    {
        printf("\n  %d ", i + 1);
        for (j = 0; j < n; j++)
            printf(" %4d ", adj[i][j]);
    }
    printf("\n\n  Minimum cost spanning tree for given undirected graph with  vertices  %d", n);
    kruskal();
    printf("\n");
}
