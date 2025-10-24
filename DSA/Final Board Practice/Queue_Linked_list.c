/*
|
    Queue implementation using linked list i.e., maintaining FIFO principle i.e., insetion at beginning while deletion from the end
*/

#include<stdio.h>
#include<stdlib.h>
int info;

struct node
{
    int data;
    struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;
    while(1)
    {
    printf("\nEnter \n1 for enqueue \n2 for dequeue \n3 for display \n4 for exit:\n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        enqueue();
        break;

    case 2:
        dequeue();
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

void enqueue()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nUnable to create new node!");
        return;
    }
    printf("\nEnter data:");
    scanf("%d",&info);
    newnode->data=info;

    if(front==NULL && rear==NULL)
    {
        newnode->next=rear;
        rear=newnode;
        front=newnode;
    }
    else
    {
        newnode->next=rear;
        rear=newnode;
    }
    printf("\n%d enqueued successfully!",info);
}

void dequeue()
{
    struct node* ptr1=rear;
    struct node* ptr2=rear->next;

    if(rear==NULL && front==NULL)
    {
        printf("\nList is empty!");
        return;
    }

    else
    {
        if(rear->next==NULL)
        {
            free(rear);
            rear=NULL;
            front=NULL;
        } 
        else
        {
            while(ptr2->next!=NULL)
            {
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            ptr1->next=NULL;
            int deleted_item=ptr2->data;
            free(ptr2);
            printf("\n%d deleted successfully!",deleted_item);
        }
    }  
}

void display()
{
    struct node* ptr=rear;
    printf("\nQueue Elements: ");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}