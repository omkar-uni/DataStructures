#include <stdio.h>
#include <stdlib.h>
#define m 999
#define N 10
int parent[N], mst[N], adj[N][N], mw = 0, wt[N], sol[N][N];
int n, s, v1, v2, i, j, k;

void fw()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sol[i][j] = adj[i][j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (sol[i][k] + sol[k][j] < sol[i][j])
                    sol[i][j] = sol[i][k] + sol[k][j];
            }
        }
    }
}

void print()
{
    printf("\nAdjacency matrix for directed graph is :\n");
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
            printf(" %2d ", sol[i][j]);
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
        printf("\nEnter the edge in (v1 v2) for directed graph : ");
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
        adj[v2-1][v1-1]=wt;
    }
    printf("\nAdjacency matrix for directed graph is :\n");
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
    fw();
    print();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                printf("\n%d->%d=%d", i + 1, j + 1, sol[i][j]);
            }
            else
                printf("\n%d->%d=%d", i + 1, j + 1, sol[i][j]);
        }
    }

    return 0;
}
