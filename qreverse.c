#include <stdio.h>
void push();
void pop();
int isempty();
void peek();
void init();
int isfull();
void display();
int q[50], opt = 0, n, front, rear, stack[50], top, v;
int main()
{

    printf("\nenter no of elements");
    scanf("%d", &n);
    init();
    while (opt != 4)
    {
        printf("\nenter option");
        printf("\n1. push \n2.pop \n3. peek");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            if (isfull())
                printf("\n Overflow");
            else
            {
                push();
                display();
                reverse();
            }
            break;

        case 2:
            if (isempty())
                printf("\n Underflow");
            else
            {
                pop();
                display();
            }
            break;

        case 3:
            if (isempty())
                printf("\n underflow");
            else
            {
                peek();
                display();
            }
            break;
        }
    }
}
void init()
{
    front = -1;
    rear = -1;
}
void pop()
{
    printf("\n deleted element: %d ", q[front]);
    front = front + 1;
}
int isfull()
{
    return rear == n - 1;
}
void display()
{
    if (front == -1)
    {
        printf("\nstack underflow");
    }
    else
    {
        int i;
        printf("\nfront-->");
        for (i = front; i <= rear; i++)
            printf(" %d-->", q[i]);
    }
    printf("rear");
}
void push()
{
    if (front == -1)
        front = 0;
    printf("\nenter value");
    scanf("%d", &v);
    rear = rear + 1;
    q[rear] = v;
}
void peek()
{
    printf("\n frontmost element: %d ", q[front]);
}
int isempty()
{
    if (front == -1 || front > rear)
        return 1;
    return 0;
}
void reverse()
{
    int i, j, temp;
    for (i = front, j = rear; i < j; i++)
    {
        temp = q[i];
        q[i] = q[j];
        q[j] = temp;
    }
    display();
}