#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *temp, *newnode, *t, *t1;

void create();
void display();
void insert(int);
void insert1(int);
void delete(int);
void delete1(int);
void search(int);
void reverse(void);
int n, pos, val, i;

void create()
{
    newnode = malloc(sizeof(struct node));
    printf("enter node 1:\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    head = newnode;
    temp = head;
    for (int i = 2; i <= n; i++)
    {
        newnode = malloc(sizeof(struct node));
        printf("enter node %d:\n", i);
        scanf("%d", &newnode->data);
        temp->next = newnode;
        newnode->next = NULL;
        temp = temp->next;
    }
}

void display(void)
{
    if (head == NULL)
        printf("Singly Linked List is empty :(\n");
    else
    {
        temp = head;
        printf("\nHead-->");
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}

void insert(int pos)
{

    temp = malloc(sizeof(struct node));

    printf("enter the data :)\n");
    scanf("%d", &temp->data);
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        int i;
        for (t = head, i = 1; i < pos - 1; i++, t = t->next)
            ;
        temp->next = t->next;
        t->next = temp;
    }
    n++;
}

void delete(int pos)
{

    if (pos == 1)
    {
        temp = head;
        head = head->next;
    }
    else
    {
        int i;
        for (t = head, i = 1; i < pos - 1; i++, t = t->next)
            ;
        temp = t->next;
        t->next = temp->next;
    }
    n--;
    // free(temp);
}

void delete1(int val)
{
    if (head->data == val)
    {
        head = head->next;
        n--;
    }
    else
    {
        for (temp = head; temp->next != NULL; temp = temp->next)
        {
            if (temp->next->data == val)
            {
                t = temp->next;
                temp->next = t->next;
                // free(t);
                n--;
                return;
            }
        }
    }
    printf("%d element not found :(\n", val);
}

void search(int val)
{
    for (temp = head, i = 1; temp != NULL, i <= n; temp = temp->next, i++)
    {
        if (temp->data == val)
        {
            printf("%d element is found at %d position\n", temp->data, i);
            return;
        }
    }
    printf("%d element not found :(\n", val);
}

void reverse()
{

    t = NULL;
    temp = t1 = head;
    while (temp != NULL)
    {
        temp = temp->next;
        t1->next = t;
        t = t1;
        t1 = temp;
    }
    head = t;
    printf("reversed :)\n");
}