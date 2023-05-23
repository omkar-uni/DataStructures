#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct bst
{
    int data;
    struct bst *lc, *rc;
} *root, *t1, *t2, *new2, *new1;

int i = 0, n, lcnt, cnt;

typedef struct queue
{
    struct bst *data1[MAX];
    int front, rear;
} queue;

void initq(queue *p)
{
    p->front = p->rear = -1;
}
void addq(queue *p, struct bst *t)
{
    // p->data[++p->rear]=t;
    p->rear++;
    p->data1[p->rear] = t; // assigning tree value in queue
}
struct bst *remove1(queue *p)
{
    return p->data1[++p->front];
}
int isempty(queue *p)
{
    if (p->front == p->rear)
        return 1;
    else
        return 0;
}

void init()
{
    root = NULL;
}
struct bst *create()
{
    struct bst *temp = (struct bst *)malloc(sizeof(struct bst));
    temp->lc = NULL;
    temp->rc = NULL;
    return temp;
}
void insert(struct bst *r, struct bst *new1)
{
    if (new1->data < r->data)
    {
        if (r->lc == NULL)
            r->lc = new1;
        else
            insert(r->lc, new1);
    }
    if (new1->data > r->data)
    {
        if (r->rc == NULL)
            r->rc = new1;
        else
            insert(r->rc, new1);
    }
}
void inorder(struct bst *temp)
{
    if (temp != NULL)
    {
        inorder(temp->lc);
        printf("%d  ", temp->data);
        inorder(temp->rc);
    }
}

void preorder(struct bst *temp)
{
    if (temp != NULL)
    {
        printf("%d  ", temp->data);
        preorder(temp->lc);
        preorder(temp->rc);
    }
}
void postorder(struct bst *temp)
{
    if (temp != NULL)
    {
        postorder(temp->lc);
        postorder(temp->rc);
        printf("%d  ", temp->data);
    }
}
void btreetraverse(struct bst *root)
{
    printf("\n Preorder Traversal : ");
    preorder(root);
    printf("\n Inorder Traversal : ");
    inorder(root);
    printf("\n Postorder Traversal : ");
    postorder(root);
}

void levelorder(struct bst *root, int n)
{
    queue q;
    initq(&q);
    addq(&q, root);
    addq(&q, NULL);
    struct bst *curr;
    int count = 0;
    int i = 0;
    int level_count = 0;
    printf("Level %d = ", i);

    while (!isempty(&q))
    {
        curr = remove1(&q);
        if (curr == NULL)
        {
            i++;
            if (isempty(&q))
                break;
            addq(&q, NULL);
            printf("(Count: %d)\n", count);
            level_count += count;
            count = 0;
            printf("Level %d = ", i);
        }
        else
        {
            printf("%d ", curr->data);
            count++;
            if (curr->lc != NULL)
                addq(&q, curr->lc);
            if (curr->rc != NULL)
                addq(&q, curr->rc);
        }
    }
    level_count += count;
    printf("(Count: %d)\n", count);
    printf("Total levels = %d\n", i);
    printf("Total nodes = %d\n", level_count);
}

void main()
{
    int op = 1, val, i;
    init();
    while (op >= 1 && op <= 7)
    {
        cnt = 0, lcnt = 0;
        printf("\n BINARY SEARCH TREE IMPLEMENTATION \n");
        printf("\n  1 : create bst");
        printf("\n  2 : display bst");
        printf("\n  3 : insert node in bst");
        printf("\n  4 : Traverse by level order");
        printf("\n Enter the desired option :");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            if (root != NULL)
                printf("\n Bst already exist");
            else
            {
                printf("\n Enter number of nodes to be enntered : ");
                scanf("%d", &n);
                if (n < 0)
                {
                    printf("\n Invalid no of nodes ..");
                }
                else
                {
                    for (i = 1; i <= n; i++)
                    {
                        new2 = create();
                        printf("\n Enter data for node %d : ", i);
                        scanf("%d", &new2->data);
                        if (root == NULL)
                            root = new2;
                        else
                            insert(root, new2);
                    }
                }
            }
            break;
        case 2:
            if (root == NULL)
                printf("\n Bst does not exist");
            else
                btreetraverse(root);
            break;
        case 3:
            t2 = create();
            printf("\n Enter data for node  : ");
            scanf("%d", &t2->data);
            if (root == NULL)
                root = t2;
            else
                insert(root, t2);
            break;
        case 4:
            if (root == NULL)
                printf("\n Bst does not exist");
            else
            {
                printf("\n Tree in level order : \n");
                levelorder(root, n);
            }
            break;
        default:
            printf("\n Enter valid option");
            break;
        }
    }
}