#include "dyqueue.h"

void main()
{
    int op = 1, val;
    printf("Dynamic implementation using Queue");
    init();
    while (op >= 1 || op <= 6)
    {
        printf("\nOperations on Queue are as follows : \n");
        printf("\n1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.peek\n");
        printf("5.isempty\n");
        printf("6.exit\n");
        printf("enter the operation : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nenter the element to enqueue : ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            if (isempty())
                printf("\nQueue is empty\n");
            else
                printf("\n%d element popped from Queue\n", dequeue());
            break;
        case 3:
            if (isempty())
                printf("\nQueue is empty\n");
            else
                display();
            break;
        case 4:
            if (isempty())
                printf("\nQueue is empty\n");
            else
                peek();
            break;
        case 5:
            if (isempty())
                printf("\nQueue is empty\n");
            else
                printf("\nQueue is not empty\n");
            break;
        case 6:
            exit(0);

        default:
            printf("\nplease enter valid options\n");
        }
        if (isempty())
            printf("Queue is empty\n");
        else
            display();
    }
}