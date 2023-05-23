#include <stdio.h>
#define m 100
int adj[m][m], out[m], in[m], vis[m];
int q[m], f = -1, r = -1;
void bfs(int st, int v)
{
    vis[st] = 1;
    q[++r] = st;
    while (f != r)
    {
        st = q[++f];
        printf("%d\t", st + 1);
        for (int i = 0; i < v; i++)
        {
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
    int v, v1, v2;
    printf("Enter the no. of vert :- ");
    scanf("%d", &v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            /* code */
            adj[i][j] = 0;
        }
    }

    while (1)
    {
        printf("Enter v1->v2");
        scanf("%d%d", &v1, &v2);
        if (v1 == 0 && v2 == 0)
            break;
        else
            adj[v1 - 1][v2 - 1] = 1;
    }
    printf("Adj is : \n");
    printf("\t");
    for (int i = 0; i < v; i++)
    {
        printf("%d\t", i + 1);
    }
    printf("in\tout\ttot");
    printf("\n");
    for (int i = 0; i < v; i++)
    {
        printf("%d\t", i + 1);
        for (int j = 0; j < v; j++)
        {
            printf("%d\t", adj[i][j]);
            if (adj[i][j] == 1)
                out[i]++;
            if (adj[j][i] == 1)
                in[i]++;
        }
        printf("%d\t%d\t%d", in[i], out[i], in[i] + out[i]);
        printf("\n");
    }
    int st;
    printf("Enter st :- \n");
    scanf("%d", &st);
    bfs(st - 1, v);

    return 0;
}
