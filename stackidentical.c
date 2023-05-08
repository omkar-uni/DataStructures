#include <stdio.h>

#include "stack.h"

int main(void)

{

    stack s1, s2;

    init(&s1);

    init(&s2);

    int num, n, i, j, size, number;

    printf("How many elements in stack1: ");

    scanf("%d", &n);

    printf("Enter element to push: ");

    for (i = 0; i < n; i++)

    {

        scanf("%d", &num);

        push(&s1, num);
    }

    printf("How many elements in stack2: ");

    scanf("%d", &size);

    printf("Enter elements in push: ");

    for (i = 0; i < size; i++)

    {

        scanf("%d", &number);

        push(&s2, number);
    }

    stack t1, t2;

    init(&t1);

    init(&t2);

    while (!isempty(&s1) && !isempty(&s2) && (peek(&s1) == peek(&s2)))

    {

        push(&t1, pop(&s1));

        push(&t2, pop(&s2));
    }
    if (isempty(&s1) && isempty(&s2))

    {

        printf("\nStacks are identical\n");
    }

    else

    {

        printf("\nNot Equal\n");
    }

    while (!isempty(&t1))

        push(&s1, pop(&t1));

    while (!isempty(&t2))

        push(&s2, pop(&t2));
}

// stack.h

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
