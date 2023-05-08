#include<stdio.h>
#define MAX 100
int n,i,j;
int adj[MAX][MAX]={0},ind[MAX],vis[MAX];
int queue[MAX],f=-1,r=-1;
void insert(int v)
{
     queue[++f]=v;
}

int del()
{
     int item;
     r++;
     item = queue[r];
     return item; 
}        

/*int indeg(int v)
{
    int i,in=0;
    for(i=0;i<n;i++)
       if(adj[i][v]==-1)
         in++;
       return in;
}*/

void topo()
{
     int k,i;
     
     printf("\n");
     printf("Topological order is : ");
     
     while (f!=r)
     {
           k = del();
           printf(" %d ",k+1);
           for (i=0;i<n;i++)
           {
               if (adj[k][i]==1)
               {
                   //adj[k-1][i]=0;
                   ind[i]=ind[i]-1;
                   if (ind[i]==0)
                      insert(i);
               }
           }
     }
}

int main()
{
   int v1,v2;
    printf("Enter the no. of vertices : ");
    scanf("%d",&n);
  
    for (i=0;i<n;i++)
    {
        ind[i]=0;
        vis[i]=0;
        for(j=0;j<n;j++)
        {
           adj[i][j]=0;
          
        }
    }
    while(1)
     {
          printf("\nEnter the edge in (v1 v2) for directed graph : ");
          printf("\nEnter (0,0) to exit :");
          scanf("%d %d",&v1,&v2);
          if((v1==0) && (v2==0)) 
             break;
          if(v1>n || v2>n || v1<1 || v2<1)
          {
             
             break;
          }
          else
           adj[v1-1][v2-1]=1;
          // adj[v2-1][v1-1]=1;
     }
     printf("\nAdjacency matrix for Directed graph is :\n");
     printf("  ");
     for(i=0;i<n;i++)
     {  printf(" ");
        printf("%d  ",i+1);
     }
     printf(" Indegree");
     for(i=0;i<n;i++)
     {
       // ind[i]=0;
        printf("\n%d",i+1);
        for(j=0;j<n;j++)
        {
            printf(" %2d ",adj[i][j]);
            if(adj[j][i]==1)
               ind[i]++;
        }
        printf("      %d",ind[i]);       
     }
     for(i=0;i<n;i++)
     {
         
         if(ind[i]==0)
         {   insert(i);
            vis[i]=1;
         }   
     }       
     //display(n);
     //degree(adj,n);
     topo();
     printf("\n");
                     
}         
/*
sy44@pc46:~/DS_SEM_IV-32/Assignment_5$ cc topo.c
sy44@pc46:~/DS_SEM_IV-32/Assignment_5$ ./a.out
Enter the no. of vertices : 5

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :1
2

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :2
5

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :2
3

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :3
5

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :4
3

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :4
5

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :1
3

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :1
4

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :0
0

Adjacency matrix for Directed graph is :
   1   2   3   4   5   Indegree
1  0   1   1   1   0       0
2  0   0   1   0   1       1
3  0   0   0   0   1       3
4  0   0   1   0   1       1
5  0   0   0   0   0       3
Topological order is :  1  2  4  3  5 
*/
