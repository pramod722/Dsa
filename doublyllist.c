//doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * prev;
    struct Node * next;
};

void traverse(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d,",head->data);
        head=head->next;
    }
}

struct Node * reverse_list(struct Node*head_ptr) 
{ 
    //Creating temporary node
  struct  Node *temp_node = NULL; 
   struct Node *current_node = head_ptr; 
    /* swapping next and previous pointers until all nodes are reversed */
    while (current_node != NULL) 
    {         //swapping
        temp_node = current_node->prev; 
        current_node->prev = current_node->next; 
        current_node->next = temp_node;             
        current_node = current_node->prev; 
    }
    if(temp_node != NULL ) //update head_ptr
        head_ptr = temp_node->prev; 
        return head_ptr; 
}

int main()
{
   
    struct Node * N1=(struct Node *)malloc(sizeof(struct Node));
    struct Node * N2=(struct Node *)malloc(sizeof(struct Node));
    struct Node * N3=(struct Node *)malloc(sizeof(struct Node));
    struct Node * N4=(struct Node *)malloc(sizeof(struct Node));
    struct Node * head =N1;

    // link n1 and n2
     N1->data=1;
     N1->prev=NULL;
     N1->next=N2;

    //link n2 and n3

    N2->data=2;
    N2->prev=N1;
    N2->next=N3;

    // link n3 and n4

    N3->data=3;
    N3->prev=N2;
    N3->next=N4;

    // link N4 and terminate

    N4->data=4;
    N4->prev=N3;
    N4->next=NULL;

  traverse(head);
  head= reverse_list(head);
  printf("\n");
   traverse(head);

}
