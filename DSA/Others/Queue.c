/*
Linear Queue
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

int rear = -1, front = -1, queue[N];

int is_full();
int is_empty();
void enqueue();
void dequeue();
void display();
void last();
void make_empty();
int returnCount();
// void reverse();
int main()
{
    int choice;
    while (1)
    {
        printf("\nEnter\n1 for Enqueue\n2 for Dequeue\n3 for Display\n4 for showing the last element\n5 for making queue empty\n6 for counting\n7 for reversing the order\n8 for exit");
        scanf("%d", &choice);
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
            last();
            break;

        case 5:
            make_empty();
            break;

        case 6:
            printf("\nNo. of elements in the queue is %d", returnCount());
            break;

            //  case 7:
            //    reverse();
            //  break;

        case 8:
            exit(0);
            break;

        default:
            printf("\nPlease enter only choices between 1 and 5!!");
            break;
        }
    }
}

int is_full()
{
    if (rear == N - 1)
        return 1;
    else
        return 0;
}

int is_empty()
{
    if (rear == -1 && front == -1)
        return 1;
    else
        return 0;
}

void enqueue()
{
    int data;
    if (is_full())
    {
        printf("\nQueue Overflow!");
        return;
    }
    if (is_empty())
    {
        front++;
        printf("\nEnter the data:");
        scanf("%d", &data);
        queue[++rear] = data;
        printf("\n%d enqueued successfully!", data);
    }
    else
    {
        printf("\nEnter the data:");
        scanf("%d", &data);
        queue[++rear] = data;
        printf("\n%d enqueued successfully!", data);
    }
}

void dequeue()
{
    if (is_empty())
    {
        printf("\nQueue Underflow! Please firstly enqueue something!");
    }
    else
    {
        int deleted_element = queue[front++];
        printf("\n%d deleted successfully!", deleted_element);
    }
}

void display()
{
    if (is_empty())
    {
        printf("\nThere is nothing to display since the queue is empty!");
        return;
    }
    else
    {
        int i;
        for (i = front; i <= rear; i++)
        {
            printf("\n%d", queue[i]);
        }
    }
}

void last()
{
    if (is_empty())
    {
        printf("\nThe queue is empty!!");
    }
    else
    {
        printf("\n%d", queue[rear]);
    }
}

void make_empty()
{
    if (!is_empty())
    {
        front = rear = -1;
    }
    else
    {
        printf("\nQueue is already empty!");
    }
}

int returnCount()
{
    int i, count = 0;
    if (!is_empty())
    {
        for (i = front; i <= rear; i++)
        {
            count++;
        }
    }
    else
    {
        printf("\nQueue is empty!");
    }
    return count;
}
/* Something has caused an logical error in this
void reverse()
{
    int i,j=0, temp;
    temp=queue[0];
    for(i=rear;i>=front;i--)
    {
        if(i==0)
        {
            queue[N-1]=temp;
            printf("\nQueue reversed successfully!");
            return;
        }
        queue[j]=queue[(i%(N-1))];
        j++;
    }
}
*/