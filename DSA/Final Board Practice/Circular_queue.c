#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int front=-1, rear=-1, queue[SIZE];

void enqueue();
void dequeue();
void front_element();
void display();
int is_full();
int is_empty();

int main()
{
    int choice;

    while(1)
    {
        printf("\nEnter \n1 for enqueue \n2 for dequeue \n3 for deisplay \n4 for front \n5 for exit\n");
        scanf("%d",&choice);

        switch(choice)
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
                front_element();
                break;

            case 5:
                exit(5);
                break;

            default:
                printf("Enter VALID OPTIONS!");
        }
    }
}

int is_full()
{
    return (front==0 && rear==SIZE-1) || (front==rear+1);
}

int is_empty()
{
    return (front==-1 && rear==-1);
}

void enqueue()
{
    if(is_full())
    {
        fprintf(stderr, "\nQueue Overflow1!");
        exit(1);
    }
    else
    {
        int value;
        printf("\nEnter value to be enqueued:");
        scanf("%d",&value);
        if(is_empty())
        {
            rear++;
            front++;
        }
        else
        {
            rear=(rear+1)%SIZE;
        }
        queue[rear]=value;
        printf("\n%d enqueued successfully!", value);
    }
}

void dequeue()
{
    if(is_empty())
    {
        fprintf(stderr,"\nQueue Underflow!");
        exit(11);
    }
    else
    {
        int deleted_data=queue[front];
        if(front==rear)
        {
            front==-1;
            rear==-1;
        }
        else
        {
            front=(front+1)%SIZE;
        }
        printf("\n%d dequeued successfullY!!",deleted_data);
    }
}

void front_element()
{
    if(is_empty())
    {
        printf("\nQueue is empty!");
    }
    printf("\nFront element: %d",queue[0]);
}

void display()
{
    printf("\nQueue Elements: ");
    if(front<=rear)
    {
        for(int i=front; i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    else
    {
        for(int i=front; i<=SIZE-1;i++)
        {
            printf("%d\t",queue[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
}