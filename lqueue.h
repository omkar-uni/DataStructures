#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void insert();
void delete();
void display();
int isfull();
int isempty();
void peek();
void init();

int queue_array[MAX], rear, front;
void init()
{
    front = rear = -1;
}

void insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("queue is full\n");
    else
    {
        printf("insert element : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void delete()
{
    int i;
    printf("\nElement deleted fron queue is %d\n", queue_array[++front]);
}

void peek()
{
    int i;
    printf("\nFront element is %d\n", queue_array[front + 1]);
    printf("\n");
}

void display()
{
    int i;
    printf("Queue is :\n");
    printf("\nFRONT::");
    for (i = front + 1; i <= rear; i++)
        printf("%d::", queue_array[i]);
    printf("REAR\n\n");
}

int isempty()
{
    if (front == rear)
        return 1;
    return 0;
}

int isfull()
{
    if (rear == MAX - 1)
        return 1;
    return 0;
}