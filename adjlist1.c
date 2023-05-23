#include <stdio.h>
#include<stdlib.h>
#define m 100
struct node 
{
    int data;
    struct node * next;
}*nw;
struct node *adj[m];
int v;
void ad(int v1,int v2)
{
     nw = (struct node *)malloc(sizeof(struct node));
     nw->data = v2;
     nw->next = adj[v1];
     adj[v1] = nw; 
}

void display()
{
    int cnt[10]={0};
    printf("list : ");
    for (int i = 1; i <= v; i++)
    {
        printf("\n%d-->",i);
        struct node *curr = adj[i];
        while(curr!=NULL)
        {
            printf("%d-->",curr->data);
            curr = curr->next;
            cnt[i]++;
        }
        printf("NULL :::::%d\n",cnt[i]);
    }
    
}

int main()
{
    int v1,v2;
    printf("Enter the v :- ");
    scanf("%d",&v);

    while (1)
    {
        printf("Enter data :- ");
        scanf("%d%d",&v1,&v2);
        if(v1==0 && v2==0)
          break;
        else
          ad(v1,v2);  
    }
    display();
    return 0;
}
