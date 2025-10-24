#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int rear=-1,front=-1, queue[SIZE];

void enqueue();
void dequeue();
void display();
int is_full();
int is_empty();
void front_element();

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
    return (rear==SIZE-1);
}

int is_empty()
{
    return (rear==-1 && front==-1);
}

void enqueue()
{
    int value;
    if(is_full())
    {
        printf("\nQueue Overflow!");
        exit(1);
    }
    else
    {
        printf("\nEnter value to be enqueued:");
        scanf("%d",&value);
        if(is_empty())
        {
        front++;
        rear++;
        }
        else
        {
            rear++;
        }
        queue[rear]=value;
        printf("\n%d enqueued successfully!!",value);
    }
}

void dequeue()
{
    if(is_empty())
    {
        printf("\nQueue Underflow!");
        exit(2);
    }
    else
    {
        int deleted_value=queue[front++];
        printf("\n%d dequeued successfully!!",deleted_value);
    }
}

void display()
{
    if(is_empty())
    {
        printf("\nNothing to show please enqueue first!!");
    }
    printf("\nQueue Elements: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
    }
}

void front_element()
{
    if(is_empty())
        printf("\nNothing to show!!");
    else
        printf("\nFront element: %d",queue[front]);
}