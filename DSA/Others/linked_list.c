#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
}*newnode;
typedef struct node node;

int *head=NULL;

int main()
{
    int data;
        newnode=(node*)malloc(sizeof(node));
        printf("Enter the data:");
        scanf("%d",&data);
        newnode->info=data;
        newnode->next=head;
        head=newnode;
        
}