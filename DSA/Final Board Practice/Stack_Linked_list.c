/*
Stack using singly linked list i.e., maintaining LIFO principle for this using insertion at the beginning and deletion at the beginning as well
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* top=NULL;
int info;

void push();
void pop();
void display();

int main()
{
    int choice;
    while(1)
    {
        printf("\nEnter \n1 for push \n2 for pop \n3 for display \n4 for exit: \n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;
        
        default:
            printf("\nEnter valid option!");
        }
    }
}

void push()
{
    struct node* newnode= (struct node*)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("\nFailed to create new node!");
        return;
    }

    int value;
    printf("\nEnter an integer data:");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=top;
    top=newnode;
    printf("\n%d pushed successfully!",value);
}

void pop()
{
    if(top==NULL)
    {
        printf("\nList is empty!");
    }

    else
    {
        struct node* ptr=top;
        int deleted_value=top->data;
        top=ptr->next;
        free(ptr);
        printf("\n%d popped successfully!",deleted_value);
    }
}

void display()
{
    struct node* ptr=top;
    printf("\nStack Elements: ");

    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}