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


    

return 0;
    
    
}
