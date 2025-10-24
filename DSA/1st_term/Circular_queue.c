#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE], rear = -1, front = -1;
void enqueue();
void dequeue();
void display();
int main()
{
    int choice;
    while (1)
    {
        printf("\nEnter \n1 for enqueue \n2 for dequeue \n3 for display\n4 for exit\n");
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
            exit(0);
            break;

        default:
            printf("Enter valid options only!!");
        }
    }
}

void enqueue()
{
    int data;
    if ((front == 0 && rear == SIZE-1) || (front == rear + 1))
    {
        printf("\nQueue Overflowed!");
    }
    else
    {
        if (rear == -1 && front == -1)
        {
            rear++;
            front++;
            printf("\nEnter the data:");
            scanf("%d", &data);
            queue[rear] = data;
            printf("\n%d enqueued successfully!", data);
            fflush(stdout);
        }
        else
        {
            rear = (rear + 1) % SIZE;
            printf("\nEnter the data:");
            scanf("%d", &data);
            queue[rear] = data;
            printf("\n%d enqueued successfully!", data);
            fflush(stdout);
        }
    }
}

void dequeue()
{
    int deleted_item;
    if (rear == -1 && front == -1)
    {
        printf("\nQueue Underflow!");
    }
    else
    {
        if(rear==front)
        {
            deleted_item=queue[front];
            rear=front=-1;
            printf("\n%d deleted successfully!",deleted_item);
            fflush(stdout);
        }
        else
        {
            deleted_item=queue[front];
            front=(front+1)%SIZE;
            printf("\n%d deleted successfully!",deleted_item);
            fflush(stdout);
        }
    }
}

/* Logic to be found....
void display()
{
    if(rear==-1 && front==-1)
    {
        printf("\nNothing to show the queue is already empty first enqueue something!");
    }
    else
    {
        int min=front>rear?rear:front;
        int max=front>rear?front:rear;
        for(int i=min;i<=max;i=(i+1)%SIZE)
        {
            printf("\n%d",queue[i]);
            fflush(stdout);
        }
    }
}
*/
void display()
{
 if (front == -1) {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
 
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}