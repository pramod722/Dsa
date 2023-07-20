#include<stdio.h>
#include<stdlib.h>
 struct Node
 {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
 };

 int max(int a,int b)
 {
    return a>b?a:b;
 }

 int getHeight(struct Node *n)
 {
    if(n==NULL)
        return 0;

    return n->height;
 } 

   struct Node *createNode(int key)
   {
      struct Node * node=(struct Node *)malloc(sizeof(struct Node));
      node->key=key;
      node->left=NULL;
      node->right=NULL;
      node->height=1;
      return node;
   }

int getBalanceFactor(struct Node *n)
{
    if(n==NULL)
    {
        return 0;
    }
    return getHeight(n->left)-getHeight(n->right);
}

struct Node *rightrotation(struct Node *y)
{
    /* data */
    struct Node * x= y->left;
    struct Node* t2 = x->right;

    x->right=y;
    y->left = t2;

    y->height = max(getHeight(y->left),getHeight(y->right)) +1;
    x->height = max(getHeight(x->right),getHeight(x->left)) +1;
    return x;
}

struct Node *leftrotation(struct Node *x)
{
      struct Node * y= x->right;
    struct Node* t2 = y->left;

    y->left=x;
    x->right = t2;

    x->height = max(getHeight(y->left),getHeight(y->right)) +1;
    y->height = max(getHeight(x->right),getHeight(x->left)) +1;
    return y;
    
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d, ", root->key);
        inorder(root->right);
    }
}

struct Node *insertavl(struct Node *node,int key)
{
    if(node == NULL)
    return(createNode(key));

    if(key< node->key)
        node->left= insertavl(node->left,key);
    else if(key> node->key)
        node->right= insertavl(node->right,key);
        return node;
    
    node->height = 1+ max(getHeight(node->left),getHeight(node->right));
    int bf=getBalanceFactor(node);

    //left left case
    if(bf>1 && key < node->left->key){
       return rightrotation(node);
    }
    //right right case
        if(bf<-1 && key > node->right->key){
        return leftrotation(node);
    }
    //left right case
    if(bf>1 && key > node->left->key)
    {
        node->left =leftrotation(node->left);
        return rightrotation(node);
    }
    //right left case
     if(bf<-1 && key < node->left->key)
    {
        node->right =rightrotation(node->right);
        return   leftrotation(node);
    }

}



int main()
{
     struct Node *p = createNode(5);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(7);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    // linking of nodes

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    insertavl(p,3);
    inorder(p);

}
  
    
 
  