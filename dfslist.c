#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node 
{
       int vertex;
       struct node* next;
}*nw1,*nw2,*temp;

struct node * adj[MAX];
int vert,in[MAX],out[MAX],visited[MAX]; 
void addedge(int v1,int v2)
{
     nw1 = (struct node * )malloc(sizeof(struct node));
     nw1->vertex = v2;
     nw1->next = adj[v1];
     adj[v1]=nw1;
     
     //nw2= (struct node * )malloc(sizeof(struct node));
     //nw2->vertex = v1;
     //nw2->next = adj[v2];
     //adj[v2]=nw2;
     
}


void display()
{
     int i,count[10]={0};
     printf("Adjacency List:\n");
     for(i=1;i<=vert;i++)
     {
        printf("%d:->",i);
        struct node* curr = adj[i];
        while(curr!=NULL)
        {
             printf("%d-->",curr->vertex);
             curr=curr->next;
             count[i]++;
        }
        printf("NULL:(count : %d)\n",count[i]);
     }
}

void degree(struct node **adj,int vert)
{
     int i,j;
     

     printf("\nVertex InDegree OutDegree TotalDegree");
     /*for(i=1;i<=vert;i++)
     {
        in = 0;
        out = 0;
        temp = adj[i];
        while(temp)
        {
              out++;
              temp = temp->next;
        }*/
        for(i=1;i<=vert;i++)
        {
           for(temp=adj[i];temp!=NULL;temp=temp->next)
           {
               out[i]++;
               in[temp->vertex]++;
           }
                
           
        }        
       /* for(j=1;j<=vert;j++)
        {
           temp = adj[j];
           while(temp)
           {
                if(temp->vertex==i)
                {
                  in++;
                }
                temp = temp->next;
           }          
        }
        */
        
     for(i=1;i<=vert;i++)
     printf("\n   %d       %d        %d         %d",i,in[i],out[i],in[i]+out[i]);
     printf("\n");                
}

void dfs(int start,int vertex)
{
     int stack[MAX];
     int top= -1;
     
     visited[vertex]=1;
     stack[++top]=vertex;
     while(top!=-1)
     {
          int start=stack[top--];
          printf(" %d ",start);
          struct node * ptr = adj[start];
          while(ptr!=NULL)
          {
               int v = ptr->vertex;
               if(!visited[v])
               {
                  visited[v]=1;
                  stack[++top]=v;
               }
               ptr=ptr->next;
          }        
     }
     
}
void main()
{   
     int e,i,v1,v2,st;
     //nw1 = malloc(sizeof(struct node));
     printf("Enter the no. of vertices for directed Graph : ");
     scanf("%d",&vert);
     printf("Enter the no. of Edge for directed Graph : ");
     scanf("%d",&e);
     for(i=0;i<vert;i++)
     {
        adj[i] = NULL;
        in[i] = 0;
        out[i]=0;
     }
     for(i=0;i<e;i++)
     {
        printf("Enter the edge %d (v1 v2):",i+1);
        scanf("%d %d",&v1,&v2);
        addedge(v1,v2);
     }
     
     display();
     degree(adj,vert);
     printf("Enter the starting vertex : ");
     scanf("%d",&st);
     printf("Depth First Search Traversal is : ");
     dfs(st,vert);
     printf("\n");
}     
      
        
  
