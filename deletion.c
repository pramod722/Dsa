#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *deleteatfirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node *deletelast(struct Node *head)
{
   struct Node *p = head;
    struct Node*q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    
  
  p->next=q->next;
    free(q);
    return head;
}

struct Node *deleteatindex(struct Node *head,int index)
{
    struct Node *p = head;
    struct Node*q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    
  
  p->next=q->next;
    free(q);
    return head;
}
struct Node *deleteatkey(struct Node *head,int value)
{
    struct Node *p = head;
    struct Node* q= head->next;
   
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
    }
    return head;
}


void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d,", ptr->data);
        ptr = ptr->next;
    }
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
   int value =4;

    // allocate memory for nodes in the heap

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second node
    head->data = 1;
    head->next = second;

    // link second and third
    second->data = 2;
    second->next = third;

    // link third node and fourth
    third->data = 3;
    third->next = fourth;
    // fourth ode and terminate;
    fourth->data = 4;
    fourth->next = NULL;
    printf("linked list before deletion \n");
    linkedlisttraversal(head);
    printf("\n");
  //  head = deleteatfirst(head);
  //  head=deleteatindex(head,3);
   // head=deletelast(head);
   head=deleteatkey(head,value);
    printf("linked list after deletion \n");
    linkedlisttraversal(head);

    return 0;
}