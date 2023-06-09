#include<stdio.h>
#include<stdlib.h>
#define m 999
#define N 10
int parent[N],mst[N],adj[N][N],mw=0,wt[N];
int n,s,v1,v2,i,j;

int min_key()
{
    int minimum = m,min;
    for(i=0;i<n;i++)
       if(mst[i]==0&&wt[i]<minimum)
       {
          minimum=wt[i];
          min=i;
       }
       return min;      
}

void dij(int s)
{
     int u,v,i,j;
     for (i=0;i<n;i++)
     {
        // parent[i]=-1;
         wt[i]=m;
         mst[i]=0;
     }
     wt[s-1]=0;
     //parent[0]=-1;
     for (i=0;i<n;i++)
     {
         u=min_key();
         mst[u]=1;  
         for (j=0;j<n;j++)
         {
             if (mst[j] == 0 && adj[u][j] && wt[u]!=m && wt[u]+adj[u][j]<wt[j])
             {
               
                wt[j]=wt[u]+adj[u][j];
             }
         }
    }
}


void print()
{
     printf("Distance from source %d is : ",s);
     for (i=0;i<n;i++)
     {
         if (i!=s)
             printf("\nShortest Path %d->%d : %d",s,i+1,wt[i]);
         else
             printf("\nShortest Path %d->%d : %d",s,i+1,wt[i]);
     }        
}
   
void main()
{                                                                                                 
    int wt,mw=0;
    printf("Enter the no. of vertices : ");
    scanf("%d",&n);
    
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            if(i==j)
               adj[i][j]=0;
            else     
              adj[i][j]=999;
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
          printf("Enter the weight of the edge between %d and %d : ",v1,v2);
          scanf("%d",&wt);
           adj[v1-1][v2-1]=wt;
           //adj[v2-1][v1-1]=wt;
     }
     printf("\nAdjacency matrix for directed graph is :\n");
     printf("  ");
     for(i=0;i<n;i++)
     {
        printf(" %d  ",i+1);
     }
     for(i=0;i<n;i++)
     {
       // ind[i]=0;
        printf("\n%d",i+1);
        for(j=0;j<n;j++)
        {
            printf(" %2d ",adj[i][j]);
            
        }
              
     }
     printf("\nEnter the start vertex : ");
     scanf("%d",&s);
     dij(s);
     print();
      
    
     printf("\n");
        
}        

/*
sy44@pc46:~/DS_SEM_IV-32/Assignment_5$ cc dijkstra.c
sy44@pc46:~/DS_SEM_IV-32/Assignment_5$ ./a.out
Enter the no. of vertices : 5

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :1
2
Enter the weight of the edge between 1 and 2 : 10

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :4
5
Enter the weight of the edge between 4 and 5 : 2

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :1
4
Enter the weight of the edge between 1 and 4 : 5

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :2
4
Enter the weight of the edge between 2 and 4 : 2

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :2
3
Enter the weight of the edge between 2 and 3 : 1

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :3
5
Enter the weight of the edge between 3 and 5 : 4

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :4
2
Enter the weight of the edge between 4 and 2 : 3

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :5
1
Enter the weight of the edge between 5 and 1 : 7

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :4
3
Enter the weight of the edge between 4 and 3 : 9

Enter the edge in (v1 v2) for directed graph : 
Enter (0,0) to exit :0
0

Adjacency matrix for directed graph is :
   1   2   3   4   5  
1  0  10   0   5   7 
2 10   0   1   3   0 
3  0   1   0   9   4 
4  5   3   9   0   2 
5  7   0   4   2   0 
Enter the start vertex : 1
Distance from source 1 is : 
Shortest Path 1->1 : 0
Shortest Path 1->2 : 8
Shortest Path 1->3 : 9
Shortest Path 1->4 : 5
Shortest Path 1->5 : 7
*/



   
