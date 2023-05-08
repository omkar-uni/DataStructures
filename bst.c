#include<stdio.h>
#include<stdlib.h>

struct bst
{
   int data;
   struct bst *lc ,*rc; 
}*root,*temp,*t,*new2,*t2,*t1;

int cont,leafcnt,k,cnt=0,lcnt=0;

void init();
struct bst * create();
struct bst* insert(struct bst*,struct bst*);
void inorder(struct bst*);
void preorder(struct bst*);
void postorder(struct bst*);
void display(struct bst*);
int search(struct bst*,int);
struct bst* delete(struct bst*,int);
int count(struct bst*);
int leafcount(struct bst*);

void main()
{
     int c = 1,n,val;
     init();
     while (c>=1 && c<=7)
     {
           printf("\nOperations on Binary Search Tree : \n");
           printf("1: Create a Binary Search Tree \n");
           printf("2: Display a Binary Search Tree\n");
           printf("3: Insert a Node in a Binary Search Tree\n");
           printf("4: Search a Node in a Binary Search Tree\n");
           printf("5: Delete a Node in a Binary Search Tree\n");
           printf("6: Total Nodes\n");
           printf("7: LeafCount\n");
           printf("8: Exit\n");
           printf("\nEnter the operation\n");
           scanf("%d",&c);
             
     
           switch (c)
           {
      
                  case 1 : if (root!=NULL)
                               printf("BST already Exists :| \n");
                           else
                           {
                              printf("enter the no. of nodes \n");
                              scanf("%d",&n);
                              if(n<0)
                                 printf("invalid size!!!\n");
                              else
                              {
                                  for (int i=1;i<=n;i++)
                                  {
                                     new2=create();
                                     printf("Enter the %d node for BST : ",i);
                                     scanf("%d",&new2->data);
                                     if (root==NULL)
                                        root = new2;
                                     else
                                        insert(root,new2);
                                  }
                              }     
                          }         
                           break;
                           
                  case 2 : if(root==NULL)
                             printf("BST doesn't exists\n");
                           else
                             display(root);
                           break;
                  case 3 : t2 = create();
                           printf("enter the data to be insert : ");
                           scanf("%d",&t2->data);
                           if (root==NULL)
                              root=t2;
                           else
                              insert(root,t2);  
                           break;
                case 4 :   if(root==NULL)
                              printf("doesn't exists\n");
                           else
                           {
                              printf("Enter data to be searched : ");
                              scanf("%d",&val); 
                              k = search(root,val);
                              if (k==0)
                                 printf("%d not found\n",val);
                              else
                                 printf("%d found\n",val);
                           }
                           break;      
                  case 5:  
                           if(root==NULL)
                              printf("doesn't exists\n");
                           else
                           {  
                              printf("Enter the Data to be Deleted : \n");
                              scanf("%d",&val);
                              k = search(root,val);
                              if (k==0)
                                 printf("%d not found\n",val);
                              else
                                 t1 = delete(root,val);
                          }
                           break;
                  case 6 : if (root==NULL)
                              printf("BST doen't exists\n");
                           else
                           {
                              cnt=0;
                              cnt = count(root);
                              printf("\nTotal nodes = %d\n",cnt); 
                           }  
                           break;   
                  case 7 : if (root==NULL)
                              printf("BST doen't exists\n");
                           else
                           {
                              lcnt=0;
                              lcnt = leafcount(root);
                              printf("\nTotal leaf nodes = %d\n",lcnt);  
                           }    
                           break;    
                                               
                  case 8 : exit(0);                                    
                  
                  
                 default : printf("you entered invalid operation :( \n");
                           break;
           }   
      }        
}      


void inorder(struct bst* temp)
{
     if(temp!=NULL)
     {
         inorder(temp->lc);
         printf("%d\t",temp->data);
         inorder(temp->rc);
     }
}

void preorder(struct bst* temp)
{
     if(temp!=NULL)
     {
         printf("%d\t",temp->data);
         preorder(temp->lc);
         preorder(temp->rc);
     }
}
         
void postorder(struct bst* temp)
{
     if(temp!=NULL)
     {
         postorder(temp->lc);
         postorder(temp->rc);
         printf("%d\t",temp->data);
     }
}
     
void display(struct bst* temp)
{
     printf("\nTraverse in Inorder :\n");
     inorder(temp);     
     printf("\nTraverse in preorder :\n");   
     preorder(temp);
     printf("\nTraverse in postorder :\n");
     postorder(temp);
}

void init()
{
     root = NULL;
}
struct bst * create()
{
       struct bst * temp= (struct bst*)malloc(sizeof(struct bst));
       temp->lc = NULL;
       temp->rc = NULL;
       return temp;
}        

struct bst* insert(struct bst* r,struct bst* new1)
{
       if (new1->data < r->data)
       {
           if (r->lc==NULL)
               r->lc = new1; 
           else
              insert(r->lc,new1);   
       }   
       if (new1->data > r->data)
       {
           if (r->rc==NULL)
               r->rc = new1; 
           else
              insert(r->rc,new1);   
       }  
} 

int search(struct bst * r1,int key)
{
       t1 = r1;
       while (t1!=NULL)
       {
              if(key == t1->data)
                return 1;
              else if(key < t1->data)
                search(t1->lc,key);
              else if(key > t1->data)
                 search(t1->rc,key);
       }
       return 0;
}                   
      
int count(struct bst* temp)
{
    if (temp!=NULL)
    {
       cnt++;
       count(temp->lc);  
       count(temp->rc);
    }
    return cnt;
    
}           
         
int leafcount(struct bst* temp)
{  
    if(temp!=NULL)
    {
       if (temp->lc == NULL && temp->rc == NULL)
          lcnt++;
          leafcount(temp->lc);
          leafcount(temp->rc);
       
    }
    return lcnt;
}           
         
struct bst* delete(struct bst* root,int data)
{
   if (root==NULL)
      return root;
   if (data < root->data)
      root->lc = delete(root->lc,data);
   else if (data > root->data)
      root->rc = delete(root->rc,data);
   else 
   {
       if (root->lc==NULL)
       {
          temp = root->rc;
          free(root);
          return temp;
       }
       else if (root->rc==NULL)
       {
               temp = root->lc;
               free(root);
               return temp;
       } 
       temp = root->rc;
       while (temp->lc!=NULL)
              temp = temp->lc;
       root->data = temp->data;
       root->rc = delete(root->rc,temp->data);                 
   }   
   return root;   
        
}         
         
