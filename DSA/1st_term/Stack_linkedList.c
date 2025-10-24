#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int n;
    struct node *next;
};

// Initialize the head of the list as NULL
struct node *head = NULL;

// Function prototypes
void push(); // Insertion at beginning
void pop();  // Deletion at beginning
void display(); // Display the list

int main() {
    int choice;
    while (1) {
        printf("\nEnter \n1 for push\n2 for pop\n3 for display\n4 for exit\n");
        scanf("%d", &choice);
        switch (choice) {
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
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}

void push() {
    int data;
    printf("\nEnter the data: ");
    scanf("%d", &data);

    // Allocate memory for the new node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Initialize the new node with data
    newnode->n = data;
    newnode->next = head;

    // Update the head to point to the new node
    head = newnode;

    printf("Node pushed successfully\n");
}

void pop() {
    if (head == NULL) {
        printf("Stack underflow\n");
        return;
    }

    // Save the head node's address
    struct node *temp = head;

    // Update the head to point to the next node
    head = head->next;

    // Free the memory of the old head
    free(temp);

    printf("Node popped successfully\n");
}

void display() {
    if (head == NULL) {
        printf("The stack is empty\n");
        return;
    }

    // Traverse the stack and print each node's data
    struct node *temp = head;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->n);
        temp = temp->next;
    }
    printf("\n");
}