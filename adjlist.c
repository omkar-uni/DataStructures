#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node
{
    int vertex;
    struct node *next;
} *newnode1, *newnode2, *temp;
struct node *adj[MAX];
int vert;
void addedge(int v1, int v2)
{
    newnode1 = (struct node *)malloc(sizeof(struct node));
    newnode1->vertex = v2;
    newnode1->next = adj[v1];
    adj[v1] = newnode1;

    // newnode2 = (struct node *)malloc(sizeof(struct node));
    // newnode2->vertex = v1;
    // newnode2->next = adj[v2];
    // adj[v2] = newnode2;
}

void displaylist()
{
    int i, count[10] = {0};
    printf("Adjacency list:\n");
    for (i = 1; i <= vert; i++)
    {
        printf("%d : --> ", i);
        struct node *curr = adj[i];
        while (curr != NULL)
        {
            printf("%d--> ", curr->vertex);
            curr = curr->next;
            count[i]++;
        }
        printf("NULL  : %d\n", count[i]);
    }
}

void degree(struct node **adj, int vert)
{
    int i, j;
    printf("\nVertex in_Degree Out_Degree Total_Dgree ::\n");
    for (i = 1; i <= vert; i++)
    {
        int in = {0};
        int out = {0};
        temp = adj[i];
        while (temp)
        {
            out++;
            temp = temp->next;
        }
        for (j = 1; j <= vert; j++)
        {
            temp = adj[j];
            while (temp)
            {
                if (temp->vertex == i)
                {
                    in++;
                }
                temp = temp->next;
            }
        }
        printf("    %d        %d        %d       %d", i, in, out, in + out);
        printf("\n");
    }
}

void main()
{
    int e, i, v1, v2;

    printf("Enter the number of vertices: ");
    scanf("%d", &vert);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (i = 1; i <= e; i++)
    {
        printf("Enter edge %d : (v1,v2) : ", i);
        scanf("%d%d", &v1, &v2);
        addedge(v1, v2);
    }
    displaylist();
 degree(adj,vert);

    // degree(adj,vert);
}