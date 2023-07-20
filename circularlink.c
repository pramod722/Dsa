#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node *next;
    
};

void traverse(struct Node * head)
{
    struct Node *ptr=head;
    do{
        printf("%d,",ptr->data);
        ptr=ptr->next;
    }while (ptr!=head);
   
}

struct Node * insertatfirst( struct Node * head,int data)
{
   struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
   ptr->data=data;
struct Node *p=head->next;
do{
    p=p->next;
}while(p->next!=head);

p->next=ptr;
ptr->next=head;
head=ptr;
return(head);
   
}

struct Node * insertlast(struct Node * head,int data)
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * q =head->next;
    while(q->next!=head)
    {
        q=q->next;
    }
    q->next=ptr;
    ptr->next=head;
    return head;


}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));
    fifth=(struct Node *)malloc(sizeof(struct Node));

    //link Node

    head->data=1;
    head->next=second;
     
     //link

     second->data=2;
     second->next=third;

     //link

     third->data=3;
     third->next=fourth;

     //link

     fourth->data=4;
     fourth->next=fifth;

     // link

     fifth->data=5;
     fifth->next=head;

     traverse(head);
     //
     head=insertatfirst(head,6);
     printf("after insertion;");
     traverse(head);
      head=insertatfirst(head,7);
     printf("after insertion;");
     traverse(head);
     traverse(head);
      head=insertlast(head,8);
     printf("after insertion;");
     traverse(head);
return 0;
    
}