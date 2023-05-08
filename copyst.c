// stacklib.h
#include <stdio.h>

typedef struct stack
{
    int data[200];
    int top;
} stack;
void push(stack *ps, int num)
{
    ps->data[++ps->top] = num;
}
int pop(stack *ps)
{
    int num;
    num = ps->data[ps->top--];
    return num;
}
int isempty(stack *ps)
{
    if (ps->top == -1)
        return 1;
    return 0;
}
int isfull(stack *ps)
{
    if (ps->top == 20 - 1)
        return 1;
    return 0;
}
int peek(stack *ps)
{
    return ps->data[ps->top];
}
int init(stack *ps)
{
    ps->top = -1;
}

// Main program

// #include <stdio.h>

// #include "stackli.h"

int main(void)

{

    stack s1, t, s2;

    init(&s1);

    init(&s2);

    init(&t);

    int i, n, num;

    printf("How many elements in stack1: ");

    scanf("%d", &n);

    printf("Enter element in stack1: ");

    for (i = 0; i < n; i++)

    {

        scanf("%d", &num);

        push(&s1, num); // pushing elements in stack1
    }

    while (!isempty(&s1))

    {

        push(&t, pop(&s1)); // pushing stack1 elements in temporary stack
    }

    while (!isempty(&t))

    {

        push(&s1, peek(&t)); // pushing temporary stack element in stack1

        push(&s2, pop(&t)); // pushing temporary stack element in stack2
    }

    printf("\n-----Elements of stack1 is copied in stack2------\n");
}
