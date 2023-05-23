#include <stdio.h>
#define max 100
int adj[max][max], v, e;
int visited[max];
void dfs(int i)
{
    int j;
    printf(" %d ", i);
    visited[i] = 1;
    for (int j = 1; j <= v; j++)
    {
        if (adj[i][j] == 1 && !visited[j])
            dfs(j);
    }
}
int main()
{
    int v1, v2;
    printf("Enter the no. of Vertices : ");
    scanf("%d", &v);
    printf("Enter the no. of Edges : ");
    scanf("%d", &e);

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            adj[i][j] = 0;
        }
    }
    for (int i = 1; i <= e; i++)
    {
        printf("Enter the start and end Vertex for edge %d : ", i);
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = 1;
        // adj[v2 - 1][v1 - 1] = 1;
    }
    printf("Adjacency Matrix is : \n");
    printf("   ");
    for (int i = 1; i <= v; i++)
    {
        printf("  %d  ", i);
    }
    // printf("\n-------------------------");
    printf("\n");
    for (int i = 1; i <= v; i++)
    {
        printf("\n%d  ", i);
        // printf("")
        for (int j = 1; j <= v; j++)
        {
            printf("  %d  ", adj[i][j]);
        }

        printf("\n");
    }
    int st;
    printf("Enter the starting Vertex : ");
    scanf("%d", &st);
    printf("DFS Traversal is : ");
    dfs(st);

    return 0;
}
