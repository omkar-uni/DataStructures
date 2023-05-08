#include <stdio.h>
struct circularqueue
{
    int size;
    int f,r;
    int *arr;
};

void enqueue(struct circularqueue * q,int val)
{
    if((q->r+1)%q->size==q->f)
      printf("overflow\n");
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }  
}
int dequeue(struct circularqueue * q)
{
    int val=-1;
    if(q->r==q->f)
      printf("empty\n");
    else
    {
        q->f=(q->f+1)%q->size;
        val = q->arr[q->f];
    }
    return val;  
}

int main()
{
    
    return 0;
}
