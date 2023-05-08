#include "singly.h"

void main()
{
    int c = 1;

    while (c >= 1 && c <= 7)
    {
        printf("\nOperations on Singly Linked List : \n");
        printf("1: Create Singly Linked List\n");
        printf("2: Display Singly Linked List\n");
        printf("3: Insert by position\n");

        printf("4: delete by position\n");
        printf("5: delete by value\n");
        printf("6: search\n");
        printf("7: reverse\n");
        printf("8: Exit\n");
        printf("\nEnter the operation\n");
        scanf("%d", &c);

        switch (c)
        {

        case 1:
            if (head != NULL)
                printf("Singly Linked List already Exists :|\n");
            else
            {
                printf("enter the number of nodes:-\n");
                scanf("%d", &n);
                if (n <= 0)
                    printf("you cannot enter 0 element\n");
                else
                    create();
            }

            break;
        case 2:
            display();
            break;
        case 3:
            if (head == NULL)
                printf("Singly Linked List is Empty :(\n");
            else
            {
                printf("enter position\n");
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1)
                    printf("You have entered invalid position for insertion :( \n");
                else
                    insert(pos);
            }
            break;
            // case  : insert1(val);
            //          break;
        case 4:
            if (head == NULL)
                printf("Singly Linked List is Empty :(\n");
            else
            {
                printf("enter position\n");
                scanf("%d", &pos);
                if (pos < 1 || pos > n || head == NULL)
                    printf("You have entered invalid position for deletion :(\n");
                else
                    delete (pos);
            }
            break;
        case 5:
            if (head == NULL)
                printf("Singly Linked List is Empty :(\n");
            else
            {
                printf("enter value\n");
                scanf("%d", &val);
                delete1(val);
            }
            break;
        case 6:
            if (head == NULL)
                printf("Singly linked list is empty :(\n");
            else
            {
                printf("enter value\n");
                scanf("%d", &val);
                search(val);
            }
            break;
        case 7:
            if (head == NULL)
                printf("Singly linked list is empty :(\n");
            else
                reverse();
            break;

        case 8:
            exit(0);

        default:
            printf("you entered invalid operation :(\n");
        }
        if (head == NULL)
            printf("Singly Linked List is Empty :(\n");
        else
            display();
        printf("no. of nodes = %d\n", n);
    }
}