#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
}n1, n2, n3, n4, n5, n6;

// In-order Traversal : Left - Root - Right
void inorderTraversal(struct node *root)
{
    if(root==NULL)
        return;

    inorderTraversal(root->left);
    printf("%d\t",root->data);
    inorderTraversal(root->right);
}


// Pre-order Traversal: Root - Left - Right
void preorderTraversal(struct node *root)
{
    if(root==NULL)
        return;

    printf("%d\t", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//Post-order Traversal: Left - Right - Root
void postorderTraversal(struct node *root)
{
    if(root==NULL)
        return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d\t",root->data);
}

// Creation of a binary search tree
void createTree()
{
    n1.data = 2;
    n2.data = 5;
    n3.data = 1;
    n4.data = 6;
    n5.data = 8;
    n6.data = 3;

    n1.left = &n3;
    n1.right = &n2;
    n2.left = &n6;
    n2.right = &n4;
    n4.right = &n5;
    n3.left = NULL;
    n3.right = NULL;
    n6.left = NULL;
    n6.right = NULL;
    n4.left = NULL;
    n5.left = NULL;
    n5.right = NULL;
};

int main()
{
    createTree();

    printf("\nInorder Traversal: ");
    inorderTraversal(&n1);

    printf("\nPreorder Traversal: ");
    preorderTraversal(&n1);

    printf("\nPostorder Traversal: ");
    postorderTraversal(&n1);

    return 0;
}