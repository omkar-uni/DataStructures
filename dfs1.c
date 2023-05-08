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


void display(int n)
{
     int i,count[10];
     for(i=0;i<=n;i++)
        count[i]=0;
     printf("Adjacency List:\n");
     for(i=1;i<=n;i++)
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

void degree(struct node **adj,int n)
{
     int i,j;
     printf("\nVertex InDegree OutDegree TotalDegree");
    
        for(i=1;i<=n;i++)
        {
           for(temp=adj[i];temp!=NULL;temp=temp->next)
           {
               in[temp->vertex]++;
               out[i]++;
           }
                
           
        }          
     for (i=1;i<=n;i++)
         printf("\n   %d       %d        %d         %d",i,in[i],out[i],in[i]+out[i]);
     printf("\n");                
}

void dfs(int start)
{
     int stack[start],top= -1,w;
     
     visited[start]=1;
     stack[++top]=start;
     while(top!=-1)
     {
          int w=stack[top--];
          printf(" %d ",w);
          struct node * ptr ;
          for (ptr = adj[w];ptr!=NULL;ptr=ptr->next)
          {
              int v = ptr->vertex;  
              if(!visited[v])
              {
                 visited[v]=1;
                 stack[++top]=v;
              }
             
          }
                 
     }
     
}


void main()
{   
     int e,i,v1,v2,s,n;
     //nw1 = malloc(sizeof(struct node));
     printf("\nEnter the no. of vertices for directed graph : ");
     scanf("%d",&n);
     while(1)
     {
          printf("\nEnter the edge in (v1 v2) for directed graph : ");
          printf("\nEnter (0,0) to exit :");
          scanf("%d %d",&v1,&v2);
          if((v1==0) && (v2==0)) 
             break;
          if(v1>n || v2>n || v1<1 || v2<1)
          {
             printf("\n invalid edge");
             break;
          }
          else
            addedge(v1,v2);
     }
     
     display(n);
     degree(adj,n);
     printf("Enter the starting vertex : ");
     scanf("%d",&s);
     printf("Depth First Search Traversal is : ");
     dfs(s);
     printf("\n");
} 





















/*
void main()
{   
     int e,i,v1,v2,s;
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
     scanf("%d",&s);
     printf("Depth First Search Traversal is : ");
     dfs(s,vert);
     printf("\n");
}     
  */
  
  /*while(ptr!=NULL)
          {
               int v = ptr->vertex;
               if(!visited[v])
               {
                  visited[v]=1;
                  stack[++top]=v;
               }
               ptr=ptr->next;
          } */    
        
  
