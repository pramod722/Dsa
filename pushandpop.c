#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;

};

void display(struct stack * ptr)
{  
    ptr->top=-1;
    while (ptr->top < ptr->size-1)
    {
        printf("%d,",ptr->arr[ptr->top]);
       ptr->top++;
    }
    
}

 int isFull(struct stack *ptr)
 {
   if(ptr->top==ptr->size-1)
   {
    return 1;
   }
   return -1;
 }

 int isEmpty(struct stack * ptr)
{    printf("\n");
    ptr->top=0;
    for(ptr->top=0;ptr->top<ptr->size-1;ptr->top++)
    {
        printf("%d,",ptr->arr[ptr->top]);
    };
    printf("\n");

}

int push(struct stack * ptr,int val)
{
    if(isFull(ptr)){
        printf("stack is Full");
    }
    ptr->top++;
    ptr->arr[ptr->top]=val;
    return 1;
}

int pop(struct stack * ptr)
{
    if(isEmpty(ptr)){
        printf("stack is Empty");
    }
    int value=ptr->arr[ptr->top];
     ptr->top=ptr->top-1;
    return value;
}
int main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=8;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    push(s , 1);
    push(s,2);
    push(s,3);
    push(s,4);
    
    
    


}