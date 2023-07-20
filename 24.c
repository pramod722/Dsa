//implementing stack using array
#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};


int isEmpty(struct stack * ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    return -1;

}
void main()
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=6;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int ));

    if(isEmpty(s))
    {
        printf("stack is empty");
    }
    else{
        printf("stack is not empty");
    }
}