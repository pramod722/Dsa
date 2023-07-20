#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
int isFull(struct queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    else
    return 0;
};

void enqueue(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("q is full");
    }
        q->r++;
        q->arr[q->r]=val;
        printf("value enque is: %d\n",q->arr[q->r]);
};

int dequeue(struct queue *q){
	int a=-1;
	if(isEmpty(q)){
		printf("queue is empty");
	}
	else{
		q->f++;
	  a=	q->arr[q->f];
	}
	return a;
	
	
}



int isEmpty(struct queue *q)
{
    if(q->r==q->f)
    {
        return 1;
    }
    return 0;
};

int main(){
    struct queue q;
    q.size=2;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,10);
    enqueue(&q,20);
    printf("dequeued element %d",dequeue(&q));

    return 0;
}
