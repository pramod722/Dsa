#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ,", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d, ", root->data);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}

struct node *create_node(int data)
{
    struct node *n;                                 // creation a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // allocate memory in heap

    n->left = NULL; // left child null
    n->data = data;
    n->right = NULL; // right child null
    return n;        // created node
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!(isBST(root->left)))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;

        return isBST(root->right);
    }

    else
    {
        return 1;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("insertion failed %d value already exist in the tree", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = create_node(key);
    if (key < prev->data)
    {
        prev->left = new;
        printf("inserted at left of root %d", prev->data);
    }
    else
    {
        prev->right = new;
        printf("inserted at right of root %d", prev->data);
    }
}

struct node *inOrderPredecessor(struct node *root){
   root = root->left;
   while(root->right !=  NULL)
   {
       root = root->right;
   }
   return root;
}

struct node * delete_node(struct node * root, int key)
{
    struct node * iPre;

    if(root == NULL)
    {
        
        return NULL;
    }

    if(root->left == NULL && root->right == NULL) //leaf node
    {
        printf("deletion successful ");
        free(root);
       
        return NULL;
    }
   //search the node to be delete
   if(key < root->data)
   {
    root->left = delete_node(root->left, key);
   }
   else if(key > root->data)
   {
   root->right = delete_node(root->right, key);
   }

   // deletion strategy when the node is found
   else{
    iPre=  inOrderPredecessor(root);
    printf("deletion successful of %d ",root->data);
    root->data= iPre->data;
    
    root->left=delete_node(root->left, iPre->data);
    
   }
   
   return root;
}


int main()
{
    // struct node *p;
    // p=(struct node *)malloc(sizeof(struct node));
    // p->left = NULL;
    // p->right = NULL;

    //    struct node *p1;
    // p1=(struct node *)malloc(sizeof(struct node));
    // p1->left=NULL;
    // p1->right=NULL;

    //    struct node *p2;
    // p2=(struct node *)malloc(sizeof(struct node));
    // p2->left=NULL;
    // p2->right=NULL;

    // p->left = p1;
    // p->right = p2;

    // constructing the node
    struct node *p = create_node(5);
    struct node *p1 = create_node(2);
    struct node *p2 = create_node(7);
    struct node *p3 = create_node(1);
    struct node *p4 = create_node(4);

    // linking of nodes

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;
    printf("Printing preorder traversal: ");
    preorder(p);
    printf("\n");
    printf("Printing postorder traversal: ");
    postorder(p);
    printf("\n");
    printf("Printing inorder traversal: ");

    inorder(p);
    printf("\n");
    printf("checking bst or not if 1 then yes if 0 then not: ");

    printf("%d", isBST(p));

    // searching elment
    printf("\n");
    printf("searching element in bst");
    printf("\n");
    struct node *n = search(p, 1);
    if (n != NULL)
    {
        printf("Element found : %d", n->data);
    }
    else
    {
        printf("Element Not found");
    }

    printf("\n");
    // printf(" inserting element 6 in bst: ");

    // insert(p, 6);
    // printf("\n");
    // printf("Printing inorder traversal after insetion: ");

    // inorder(p);

    // printf("\n");
    // printf(" inserting element 8 in bst: ");

    // insert(p, 8);
    // printf("\n");
    // printf("Printing inorder traversal after insetion: ");

    // inorder(p);

    // printf("\n");
    // printf(" inserting element 8 in bst: ");

    // insert(p, 8);
    // printf("\n");
    // printf("Printing inorder traversal after insetion: ");

    // inorder(p);

     printf("\n");
    printf(" deleting element 5 in bst: ");

   delete_node(p, 2);
    printf("\n");
    printf("Printing inorder traversal after deletion: ");

    inorder(p);
    return 0;
}