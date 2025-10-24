#include <stdio.h>
#include <stdlib.h>

struct node // Creating a node that will contain an integer data and the link of next node to be added
{
    int data;
    struct node *next;
};

struct node *head = NULL; // Initializing head to NULL at first when there is no nodes

void push();    // Function that will push the data in the stack
void pop();     // Function that will pop the dta in the stack
void display(); // Function that will display the elements in the stack

int main()
{
    int choice;
    while (1)
    {
        printf("\nEnter\n1 for push\n2 for pop\n3 for display\nenter anything else to exit\n");
        scanf("%d", &choice); // Getting input of which operation to do from user?

        // Checking which choice is selected by the user and executing instructions accordingly
        if (choice == 1)
        {
            push();
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            display();
        }
        else
        {
            exit(0);
        }
    }
}

void push()
{
    struct node *newnode;
    int data;
    newnode = (struct node *)malloc(sizeof(struct node)); // Creating a new node using malloc function

    if (newnode == NULL) // Checking if memory allocation is done properly or not
    {
        printf("\nMemory Allocation Failed!!");
        return;
    }

    printf("\nEnter a data:");
    scanf("%d", &data);   // Taking integer data as in input for the data field of the node
    newnode->data = data; // Putting the given data in the data field of the new node
    newnode->next = head; // Linking the head node to the new node
    head = newnode;       // Making the new node as the head since we are inserting at the beginning of the linked list

    printf("\n%d pushed successfully!!", data); // Showing the user that data is successfully pushed
}

void pop()
{
    if (head == NULL) // Checking if the stack is empty or not?
    {
        printf("\nStack undrflow!"); // If empty showing the users that stack is now in underflow condition
    }
    struct node *ptr1 = head;       // creating a new pointer pointing to the head node
    struct node *ptr2 = head->next; // creating another pointer pointing to node next to head
    while (ptr2->next != NULL)      // Moving the pointers to another node untill we get to the final node whe
    {
        // Moving both the pointers to thier respective next nodes
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    printf("\n%d popped successfully!!", ptr2->data); // Showing the use that data is popped successfully
    free(ptr2);                                       // Freeing the final node coz we are doing deletion at the end
    ptr1->next = NULL;                                // Setting the previous node of last node to NULL because last one is already deleted and new last node is the previos node of last node
}

void display()
{
    if (head == NULL) // Checking whether there is any node or not?
    {
        printf("\nStack is empty already!!");
    }
    struct node *ptr = head; // Creating a pointer pointing to the head
    printf("\nThe elements in the stack are:\t");
    while (ptr != NULL) // Moving the pointer forward untill last node is met
    {
        printf("%d\t", ptr->data); // Printing the elements of nodes
        ptr = ptr->next;           // Moving the pointer one step forward
    }
}