#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insert(int);
void insert1(int);
void delete(int);
void delete1(int);
void search(int);
void rev();
struct node
{
    int data;
    struct node *next, *prev;
} *headl = NULL, *headr = NULL, *temp, *t, *t1, *t2;

int n, pos, val, i;
void create()
{
    temp = malloc(sizeof(struct node));
    temp->next = temp->prev = NULL;
    printf("enter node 1:\n");

    scanf("%d", &temp->data);
    // if (i = 1)
    headl = headr = t = temp;

    for (int i = 2; i <= n; i++)
    {
        temp = malloc(sizeof(struct node));
        printf("enter node %d:\n", i);
        scanf("%d", &temp->data);
        t->next = temp;
        temp->prev = t;
        t = t->next;
        headr = t;
    }
    display();
}

void display(void)
{
    if (headl == NULL && headr == NULL)
        printf("Doubly Linked List is empty :\n");
    else
    {
        printf("\nDoubly linked list from left to right:-\n");
        printf("Headl-->");
        for (temp = headl; temp->next != NULL; temp = temp->next)
            printf("%d-->", temp->data);
        printf("%d-->NULL\n", temp->data);
        printf("\nDoubly linked list from right to left:-\n");
        printf("Headr-->");
        for (temp = headr; temp->prev != NULL; temp = temp->prev)
            printf("%d-->", temp->data);
        printf("%d-->NULL\n", temp->data);
    }
}

void insert(int pos)
{

    temp = malloc(sizeof(struct node));

    printf("enter the data :)\n");
    scanf("%d", &temp->data);
    if (pos == 1)
    {
        headl->prev = temp;
        temp->next = headl;
        headl = temp;
    }
    else
    {

        for (t = headl, i = 1; i < pos - 1; i++, t = t->next)
            ;
        temp->next = t->next;
        temp->prev = t;
        t->next = temp;

        if (t == headr)
            headr = temp;
        else
            temp->next->prev = temp;
    }
    n++;
    display();
}

void delete(int pos)
{
    // temp = headl;
    if (pos == 1)
    {
        if (headl == headr)
            headl = headr = NULL;
        else
        {
            headl = headl->next;
            headl->prev = NULL;
        }
    }
    else
    {

        for (t = headl, i = 1; i < pos - 1 && t->next != NULL; i++, t = t->next)
            ;
        temp = t->next;
        t->next = temp->next;
        if (temp != headr)
            temp->next->prev = t;
        else
        {
            t->next = NULL;
            headr = t;
        }
    }
    n--;
    display();
    // free(temp);
}

/*void delete1(int val)
{
     if (headl->data == val)
     {
         headl = headl->next;
         headl->next->prev = headl;
         n--;
     }
     else
     {
         for (temp = headl;temp->next!=NULL;temp=temp->next)
         {
             if (temp->next->data==val)
             {
                t = temp->next;
                temp->next = t->next;

                //free(t);
                n--;
                return;
             }
         }
     }
     printf("not found :(\n");
}*/

void delete1(int val)
{

    for (t = headl, i = 1; t != NULL; i++, t = t->next)
    {
        if (t->data == val)
            break;
        temp = t;
    }
    if (t == NULL)
    {
        printf("%d not present in doubly linked list", val);
        return;
    }
    if (t == headl && t == headr)
        headl = headr = NULL;
    else
    {
        if (t == headl)
        {
            headl = temp->next;
            headl->prev = NULL;
        }
        else
        {
            if (t == headr)
            {
                temp->next = NULL;
                headr = temp;
            }
            else
            {
                temp->next = t->next;
                t->next->prev = temp;
            }
        }
        n--;
    }

    display();
}

void rev()
{
    temp = headl;
    headl = headr;
    headr = temp;
    printf("Headl-->");
    for (temp = headl; temp->prev != NULL; temp = temp->prev)
        printf("%d-->", temp->data);
    printf("%d-->NULL\n", temp->data);
    headl->next = NULL;
    printf("Headr-->");
    for (temp = headr; temp->next != NULL; temp = temp->next)
        printf("%d-->", temp->data);
    printf("%d-->NULL\n", temp->data);
    headr->prev = NULL;
}

/*void rev()
{
     temp = headl;
     t1 = temp->next;
     t2 = t1->next;
     while (t1->next!=NULL)
     {
           t1->next = temp;
           temp = t1;
           t1 = t2;
           t2 = t2->next;
     }
     t1->next = temp;
     headl->next = NULL;
     headl = t1;

     temp = headr;
     t1 = temp->prev;
     t2 = t1->prev;
     while (t1->prev!=NULL)
     {
           t1->prev = temp;
           temp = t1;
           t1 = t2;
           t2 = t2->next;
     }
     t1->prev = temp;
     headr->next = NULL;
     headr = t1;
}*/

void search(int val)
{
    for (temp = headl, i = 1; temp != NULL; temp = temp->next, i++)
    {
        if (temp->data == val)
        {
            printf("from left to right:\n");
            printf("%d element is found at %d position\n", temp->data, i);
            // return;
        }
    }
    for (temp = headr, i = 1; temp != NULL; temp = temp->prev, i++)
    {
        if (temp->data == val)
        {
            printf("from right to left:\n");
            printf("%d element is found at %d position\n", temp->data, i);
            display();
            return;
        }
    }
    printf("not found :(\n");
}