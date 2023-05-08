#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

int top = -1;
char stack[MAX];
char pop();
void push(char);

int main()
{
    char str[20];
    int i;
    printf("enter the string : ");
    // gets(str);
    scanf("%s", str);
    if (strlen(str) > MAX)
        printf("Stack overflow condition occured\n");
    else
    {
        for (i = 0; i < strlen(str); i++)
            push(str[i]);
        for (i = 0; i < strlen(str); i++)
            str[i] = pop();
        printf("Reversed string is : ");
        puts(str);
    }
    return 0;
}

void push(char item)
{

    stack[++top] = item;
}

char pop()
{
    if (top == -1)
    {
        printf("\nstack  underflow");
        exit(1);
    }
    return stack[top--];
}