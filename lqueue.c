#include "lqueue.h"

void main()
{
    int choice = 1;
    printf("Static implemention using Queue(linear Queue)\n");
    init();
    while (choice >= 1 || choice <= 7)
    {
        printf("1.insert element in queue\n");
        printf("2.delete element from queue\n");
        printf("3.display\n");
        printf("4.peek\n");
        printf("5.isfull\n");
        printf("6.isempty\n");
        printf("7.exit\n");
        printf("enter the choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isfull())
                printf("queue is full\n");
            else
                insert();
            break;

        case 2:
            if (isempty())
                printf("queue is empty\n");
            else
                delete ();
            break;

        case 3:
            if (isempty())
                printf("queue is empty\n");
            else
                display();
            break;
        case 4:
            if (isempty())
                printf("queue is empty\n");
            else
                peek();
            break;

        case 5:
            if (isfull())
                printf("queue is full\n");
            else
                printf("queue is not full\n");
            break;

        case 6:
            if (isempty())
                printf("queue is empty\n");
            else
                printf("queue is not empty\n");
            break;

        case 7:
            exit(0);
        default:
            printf("\nplease enter valid options\n");
        }
        if (isempty())
        {
            printf("queue is empty\n");
            init();
        }
        else
            display();
    }
}