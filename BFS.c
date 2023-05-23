#include <stdio.h>
#define m 100
int adj[m][m], in[m] = {0}, out[m] = {0}, tot[m] = {0}, vis[m];
int q[m], f = -1, r = -1;
void bfs(int st, int v)
{
    vis[st] = 1;
    q[++r] = st;
    while (f != r)
    {
        st = q[++f];
        printf("%d ", st + 1);
        for (int i = 0; i < v; i++)
        {
            /* code */
            if (adj[st][i] == 1 && vis[i] == 0)
            {
                vis[i] = 1;
                q[++r] = i;
            }
        }
    }
}
int main()
{
    int v1, v2, v, e, st;
    printf("Enter the no. of vertex : ");
    scanf("%d", &v);
    // printf("Enter the no. of edge : ");
    // scanf("%d", &e);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)

            adj[i][j] = 0;
    }

    while (1)
    {
        printf("Enter Edge from vertex to vertex (v1,v2): ");
        scanf("%d%d", &v1, &v2);
        if (v2 == 0 && v1 == 0)
            break;
        else
        {
            adj[v1 - 1][v2 - 1] = 1;
            // adj[v2 - 1][v1 - 1] = 1;
        }
    }

    printf("Adj is : \n");
    // printf("\t\t\tindegree\n");
    printf("\t");
    for (int i = 0; i < v; i++)
    {
        printf("%d\t", i + 1);
    }
    printf("indegree  outdegree    total ");
    printf("\n");
    for (int i = 0; i < v; i++)
    {
        printf("%d\t", i + 1);
        for (int j = 0; j < v; j++)
        {
            printf("%d\t", adj[i][j]);
            if (adj[i][j] == 1)
            {
                out[i]++;
            }
            if (adj[j][i] == 1)
                in[i]++;
        }
        printf("%d\t%d\t%d", in[i], out[i], in[i] + out[i]);
        printf("\n");
    }
    printf("Enter the st v :-");
    scanf("%d", &st);
    printf("bst :- \n");
    bfs(st - 1, v);
    return 0;
}