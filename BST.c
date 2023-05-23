#include <stdio.h>
#include <stdlib.h>
struct bst
{
    int data;
    struct bst *lc, *rc;
} *root, *t, *nw;

int lcnt = 0, cnt = 0;

struct bst *create()
{
    struct bst *temp = (struct bst *)malloc(sizeof(struct bst));
    temp->lc = NULL;
    temp->rc = NULL;
    return temp;
}

struct bst *insert(struct bst *r, struct bst *nw)
{
    if (nw->data < r->data)
    {
        if (r->lc == NULL)
            r->lc = nw;
        else
            insert(r->lc, nw);
    }
    if (nw->data > r->data)
    {
        if (r->rc == NULL)
            r->rc = nw;
        else
            insert(r->rc, nw);
    }
}

void in(struct bst *r)
{

    if (r != NULL)
    {
        in(r->lc);
        printf("%d", r->data);
        in(r->rc);
    }
}
void post(struct bst *r)
{

    if (r != NULL)
    {
        post(r->lc);
        post(r->rc);
        printf("%d", r->data);
    }
}
void pre(struct bst *r)
{

    if (r != NULL)
    {
        printf("%d", r->data);
        pre(r->lc);
        pre(r->rc);
    }
}

int count(struct bst *r)
{
    if (r != NULL)
    {
        cnt++;
        count(r->lc);
        count(r->rc);
    }
    return cnt;
}
int lcount(struct bst *r)
{
    if (r != NULL)
    {
        if (r->lc == NULL && r->rc == NULL)
            lcnt++;
        lcount(r->lc);
        lcount(r->rc);
    }
    return lcnt;
}

void display(struct bst *r)
{
    printf("\nIn :- ");
    in(r);
    printf("\nIn :- ");
    pre(r);
    printf("\nIn :- ");
    post(r);
}

int hg(struct bst *r)
{
    if (r == NULL)
        return 0;
    else
    {
        int right = hg(r->rc);
        int left = hg(r->lc);
        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
}

int printlvl(struct bst *r, int l, int *co)
{
    if (r == NULL)
        return 0;
    else if (l == 1)
    {
        printf(" %d ", r->data);
        (*co)++;
    }
    else if (l > 1)
    {
        printlvl(r->lc, l - 1, co);
        printlvl(r->rc, l - 1, co);
    }
}

int print(struct bst *root)
{
    int h = hg(root);
    printf("\nTotal lvl : - %d\n", h);
    for (int i = 1; i <= h; i++)
    {
        int co = 0;
        printf("Lvl %d :", i);
        printlvl(root, i, &co);
        printf("|count %d|\n", co);
    }
}

int main()
{
    int n, c = 1;
    root = NULL;
    while (c >= 1 && c <= 5)
    {
        printf("\ncreate\ninsert\ndisplay");
        printf("Choose:\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if (root != NULL)
            {
                printf("Exists\n");
            }
            else
            {
                printf("Enter the size :-");
                scanf("%d", &n);
                for (int i = 1; i <= n; i++)
                {
                    nw = create();
                    printf("Enter data :-");
                    scanf("%d", &nw->data);
                    if (root == NULL)
                        root = nw;
                    else
                        insert(root, nw);
                }
            }

            break;
        case 2:
            if (root == NULL)
            {
                printf("Empty\n");
            }
            else
                display(root);
            break;
        case 3:
            if (root == NULL)
            {
                printf("Empty\n");
            }
            else
                cnt = 0;
            cnt = count(root);
            printf("Count = %d", cnt);
            lcnt = 0;
            lcnt = lcount(root);
            printf("lCount = %d", lcnt);
            break;
        case 4:
            t = create();
            printf("Enter data :-");
            scanf("%d", &t->data);
            if (root == NULL)
                root = t;
            else
                insert(root, t);
            break;
        case 5:

            // printf("Total level:-%d", hg(root));
            print(root);
            break;
        default:
            break;
        }
    }
    return 0;
}
