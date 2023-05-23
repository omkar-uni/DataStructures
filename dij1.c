#include <stdio.h>
#include <stdlib.h>
#define m 999
#define N 10
int p[m], wt[m], mst[m], adj[m][m];
int n, s, v1, v2, i, j;

int min()
{
    int mini = m, mi;
    for (int i = 0; i < n; i++)
    {
        if (mst[i] == 0 && wt[i] < mini)
        {
            mini = wt[i];
            mi = i;
        }
    }
    return mi;
}

void dij(int s)
{
    int u;
    for (int i = 0; i < n; i++)
    {
        wt[i] = m;
        mst[i] = 0;
    }
    wt[s - 1] = 0;
    for (int i = 0; i < n; i++)
    {
        u = min();
        mst[u] = 1;
        for (int j = 0; j < n; j++)
        {
            if (mst[j] == 0 && adj[u][j] != 0 && wt[u] != m && wt[u] + adj[u][j] < wt[j])
            {
                wt[j] = wt[u] + adj[u][j];
            }
        }
    }
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        if (i != s)
        {
            printf("%d->%d %d\n", s, i + 1, wt[i]);
        }
        else
            printf("%d->%d %d\n", s, i + 1, wt[i]);
    }
}
void main()
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
        adj[v2 - 1][v1 - 1] = wt;
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
    printf("\nEnter the start vertex : ");
    scanf("%d", &s);
    dij(s);
    print();

    printf("\n");
}

// #include <stdio.h>
// #include <stdlib.h>
// #define m 999
// #define N 10
// int parent[N], mst[N], adj[N][N], mw = 0, wt[N], sol[N][N];
// int n, s, v1, v2, i, j, k;

// void fw()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             sol[i][j] = adj[i][j];
//         }
//     }
//     for (int k = 0; k < n; k++)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (sol[i][k] + sol[k][j] < sol[i][j])
//                     sol[i][j] = sol[i][k] + sol[k][j];
//             }
//         }
//     }
// }

// void print()
// {
//     printf("\nAdjacency matrix for directed graph is :\n");
//     printf("  ");
//     for (i = 0; i < n; i++)
//     {
//         printf(" %d  ", i + 1);
//     }
//     for (i = 0; i < n; i++)
//     {
//         // ind[i]=0;
//         printf("\n%d", i + 1);
//         for (j = 0; j < n; j++)
//         {
//             printf(" %2d ", sol[i][j]);
//         }
//     }
// }

// int main()
// {
//     int wt, mw = 0;
//     printf("Enter the no. of vertices : ");
//     scanf("%d", &n);

//     for (i = 0; i < n; i++)
//         for (j = 0; j < n; j++)
//         {
//             if (i == j)
//                 adj[i][j] = 0;
//             else
//                 adj[i][j] = 999;
//         }
//     while (1)
//     {
//         printf("\nEnter the edge in (v1 v2) for directed graph : ");
//         printf("\nEnter (0,0) to exit :");
//         scanf("%d %d", &v1, &v2);

//         if ((v1 == 0) && (v2 == 0))
//             break;
//         if (v1 > n || v2 > n || v1 < 1 || v2 < 1)
//         {

//             break;
//         }
//         printf("Enter the weight of the edge between %d and %d : ", v1, v2);
//         scanf("%d", &wt);
//         adj[v1 - 1][v2 - 1] = wt;
//         adj[v2 - 1][v1 - 1] = wt;
//     }
//     printf("\nAdjacency matrix for directed graph is :\n");
//     printf("  ");
//     for (i = 0; i < n; i++)
//     {
//         printf(" %d  ", i + 1);
//     }
//     for (i = 0; i < n; i++)
//     {
//         // ind[i]=0;
//         printf("\n%d", i + 1);
//         for (j = 0; j < n; j++)
//         {
//             printf(" %2d ", adj[i][j]);
//         }
//     }
//     fw();
//     print();
//     int s;
//     printf("Enter the starting ele :- ");
//     scanf("%d", &s);
//     for (int j = 0; j < n; j++)
//     {
//         if (s != j)
//         {
//             printf("\n%d->%d=%d", s, j + 1, sol[s-1][j]);
//         }
//         else
//             printf("\n%d->%d=%d", s, j + 1, sol[s-1][j]);
//     }

//     return 0;
// }
