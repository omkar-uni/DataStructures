#include "doubly.h"

void main()
{
    int c = 1;

    while (c >= 1 && c <= 7)
    {
        printf("\nOperations on Doubly Linked List : \n");
        printf("1: Create Doubly Linked List\n");
        printf("2: Display Doubly Linked List\n");
        printf("3: Insert by position\n");

        printf("4: delete by position\n");
        printf("5: rev\n");
        printf("6: search\n");
        printf("7: delete by value\n");
        printf("8: Exit\n");
        printf("\nEnter the operation\n");
        scanf("%d", &c);

        switch (c)
        {

        case 1:
            if (headl != NULL && headr != NULL)
                printf("Doubly Linked List already Exists\n");
            else
            {
                printf("enter the number of nodes:-\n");
                scanf("%d", &n);
                create();
            }

            break;
        case 2:
            display();
            break;
        case 3:
            printf("enter position\n");
            scanf("%d", &pos);
            if (pos < 1 || pos > n + 1)
                printf("invalid position for insertion :( \n");
            else
                insert(pos);
            break;
            // case  : insert1(val);
            //          break;
        case 4:
            printf("enter position\n");
            scanf("%d", &pos);
            if (pos < 1 || pos > n || headl == NULL && headr == NULL)
                printf("invalid position for deletion :(\n");
            else
                delete (pos);
            break;
        case 5:
            rev();
            break;
            /*     case 5 :if (head==NULL)
                            printf("Singly linked list is empty :(\n");
                         else
                         {
                            printf("enter val\n");
                            scanf("%d",&val);



                            delete1(val);
                         }
                         break;*/
        case 6:
            if (headr == NULL && headl == NULL)
                printf("Doubly linked list is empty :(\n");
            else
            {
                printf("enter val\n");
                scanf("%d", &val);
                search(val);
            }
            break;
        case 7:
            if (headl == NULL && headr == NULL)
                printf("Singly linked list is empty :(\n");
            else
            {
                printf("enter val\n");
                scanf("%d", &val);
                delete1(val);
            }
            break;

        case 8:
            exit(0);

        default:
            printf("invalid operation :(\n");
        }
        // display();
        printf("no. of nodes = %d\n", n);
    }
}