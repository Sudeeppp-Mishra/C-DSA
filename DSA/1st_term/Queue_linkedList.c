#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node
{
    int data;
    struct node *next;
};

// Initialize the head and tail of the queue as NULL
struct node *head = NULL;
struct node *tail = NULL;

// Function prototypes
void enqueue(); // Insertion at beginning
void dequeue(); // Deletion at end
void display(); // Display the queue

int main()
{
    int choice;
    while (1)
    {
        printf("\nEnter \n1 for enqueue\n2 for dequeue\n3 for display\n4 for exit\n");
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
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}

void enqueue()
{
    int data;
    printf("\nEnter the data: ");
    scanf("%d", &data);

    // Allocate memory for the new node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    // Initialize the new node with data
    newnode->data = data;
    newnode->next = head;

    // Update the head to point to the new node
    head = newnode;

    // If the queue was empty, set the tail to the new node as well
    if (tail == NULL)
    {
        tail = newnode;
    }

    printf("Node enqueued successfully\n");
}

void dequeue()
{
    if (tail == NULL)
    {
        printf("Queue underflow\n");
        return;
    }

    // If there is only one node in the queue
    if (head == tail)
    {
        free(tail);
        head = tail = NULL;
    }
    else
    {
        // Traverse the queue to find the node just before the tail
        struct node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        // Update the tail to the previous node
        free(tail);
        tail = temp;
        tail->next = NULL;
    }

    printf("Node dequeued successfully\n");
}

void display()
{
    if (head == NULL)
    {
        printf("The queue is empty\n");
        return;
    }

    // Traverse the queue and print each node's data
    struct node *temp = head;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}