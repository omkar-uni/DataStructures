#include <stdio.h>
#include <stdlib.h>
void init();
void enqueue(int);
int dequeue();
void peek();
void display();
int isempty();

struct node
{
    int data;
    struct node *next;
} *front, *rear, *temp;

void init()
{
    front = rear = NULL;
}

void enqueue(int value)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;
    if (front == NULL)
        front = rear = ptr;
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
    printf("node is inserted\n");
}

int dequeue()
{

    temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    return temp->data;
}

void display()
{
    struct node *temp;
    printf("the queue is:\n");
    printf("FRONT::");
    temp = front;
    while (temp)
    {
        printf("%d::", temp->data);
        temp = temp->next;
    }
    printf("REAR\n");
}

void peek()
{
    struct node *temp = front;
    printf("Front element is %d\n", front->data);
    printf("\n");
}

int isempty()
{
    if (front == NULL && rear == NULL)
        return 1;
    return 0;
}