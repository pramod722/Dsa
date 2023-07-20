#include<stdio.h>
#include<stdlib.h>
  
struct Node
{
    int data;
    struct Node * next;
    
};
void linkedlisttraversal(struct Node*ptr)
{
    while (ptr!=NULL)
    {
        printf("%d,",ptr->data);
        ptr=ptr->next;
    }
    
}
struct Node * insertatfirst(struct Node * head,int data)
{
    struct Node * ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
struct Node * insertafter(struct Node * head,struct Node *preNode,int data)
{
   struct Node * ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=preNode->next;
    preNode->next=ptr;
    return head;
}
struct Node * insertatindex(struct Node * head,int data,int index)
{
    struct Node * ptr =(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node * insertatend(struct Node * head,int data)
{
    struct Node * ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    
    return head;
}

int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;

    // allocate memory for nodes in the heap
   
   head=(struct Node *)malloc(sizeof(struct Node));
   second=(struct Node *)malloc(sizeof(struct Node));
   third=(struct Node *)malloc(sizeof(struct Node));
    
    //link first and second node
     head->data=7;
    head->next=second;

    // link second and third
    second->data=8;
    second->next=third;

    //link third node and terminate
    third->data=9;
    third->next=NULL;
    
    linkedlisttraversal(head);

//    head=insertatfirst(head,1);
//    printf("after insertion\n");
//     linkedlisttraversal(head);

//     insertatindex(head,98,2);
//     printf("\n");
//     linkedlisttraversal(head);
//   head=  insertatend(head,123);
//     printf("\n");
//     linkedlisttraversal(head);
    head=  insertafter(head,second,120);
    printf("\n");
    linkedlisttraversal(head);
    

return 0;
    
    
}
