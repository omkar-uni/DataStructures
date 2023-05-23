#include <stdio.h>
#define m 100
int adj[m][m], in[m] = {0}, out[m] = {0}, tot[m] = {0};
int main()
{
    int v1, v2, v, e;
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
    // printf("|  indegree | outdegree ");
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

    return 0;
}