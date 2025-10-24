#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertion_beginning(); // Function to implement linked list where insertion will be done at the beginning
void insertion_end();       // For insertion at the end of linked list
void insertion_position();  // For insertion at a specified position by the user
void deletion_beginning();  // Deletion from the beginning
void deletion_end();        // Deletion at the end
void deletion_position();   // Deletion at a specified position
void display();             // Displaying all the datas of the linked list

int info;

int main()
{
    int choice;
    while (1)
    {
        // Gettig what to do from the user??
        printf("\nEnter \n1 for insetion at beginning \n2 for insertion at the end \n3 for insertion at specified position \n4 for deletion from beginning \n5 for deletion from the end \n6 for deletion form specified postion \n7 for display \n8 for exit:\n");
        scanf("%d", &choice);

        // Switching betweent he choices that user made
        switch (choice)
        {
        case 1:
            insertion_beginning();
            break;

        case 2:
            insertion_end();
            break;

        case 3:
            insertion_position();
            break;

        case 4:
            deletion_beginning();
            break;

        case 5:
            deletion_end();
            break;

        case 6:
            deletion_position();
            break;

        case 7:
            display();
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("\nEnter one of the VALID OPTIONS!"); // If INVALD option is choosen by the user
        }
    }
}

void insertion_beginning()
{
    // Create a newnode
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) // Check for memory allocation failure
    {
        printf("\nMemory allocation failed!");
        return;
    }

    // Take i/p from user and assign the value to the data field of the node
    printf("\nEnter the data:");
    scanf("%d", &info);
    newnode->data = info;

    // Assigning the head to the next field of newnode and finally making the newnode the head
    newnode->next = head;
    head = newnode;
}

void insertion_end()
{
    // Create newnode
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) // Check for memory allocation failure
    {
        printf("\nMemory allocation failed!");
        return;
    }

    // Take i/p and assign to data field and assigning NULL to the next field
    printf("Enter the data:");
    scanf("%d", &info);
    newnode->data = info;
    newnode->next = NULL;

    // Check if the list is empty
    if (head == NULL)
    {
        // Making the newnode the head
        head = newnode;
    }

    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void insertion_position()
{
    int position, i, node_count = 0;
    struct node *ptr = head;

    // Count the number of nodes in the list
    while (ptr != NULL)
    {
        node_count++;
        ptr = ptr->next;
    }

    // Inform the user about the current size of the list
    printf("\nThe list currently has %d nodes.", node_count);

    // Check if the list is empty
    if (node_count == 0)
    {
        char choice;
        printf("\nThe list is currently empty. Do you want to create a new node at position 1? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume any leftover whitespace

        if (choice == 'y' || choice == 'Y')
        {
            position = 1;
        }
        else
        {
            printf("\nOperation cancelled. Returning to the main menu.");
            return;
        }
    }
    else
    {
        // Take the desired position from the user
        printf("\nEnter the position to insert (1 to %d):", node_count + 1);
        scanf("%d", &position);

        // Validate the position
        if (position < 1 || position > node_count + 1)
        {
            printf("\nInvalid position! The position must be between 1 and %d.", node_count + 1);
            return;
        }
    }

    // Create new node
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) // Check for memory allocation failure
    {
        printf("\nMemory allocation failed!");
        return;
    }

    printf("\nEnter the value to be inserted:");
    scanf("%d", &info);
    newnode->data = info;

    // Case 1: Insertion at the beginning
    if (position == 1)
    {
        newnode->next = head;
        head = newnode;
        printf("\nNode inserted successfully at position 1.");
        return;
    }

    // Navigate to the position just before the desired location
    ptr = head;
    for (i = 1; i < position - 1; i++)
    {
        ptr = ptr->next;
    }

    // Insert the new node at the correct position
    newnode->next = ptr->next;
    ptr->next = newnode;

    printf("\nNode inserted successfully at position %d.", position);
}

void deletion_beginning()
{
    //Checking if the list is empty or not?
    if(head==NULL)
    {
        printf("\nList is empty!");
        return;
    }

    //Checking if the list has only one node
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }

    //If the list has more than one nodes
    else
    {
        struct node* ptr=head;
        head=head->next;
        free(ptr);
    }
}

void deletion_end()
{
    //Check for empty list i.e., not list is there
    if(head==NULL)
    {
        printf("\nThe list is empty!");
        return;
    }

    //If the list has only one node
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }

    else
    {
        struct node* ptr1;
        struct node* ptr2;
        ptr1=head;
        ptr2=head->next;
        while(ptr2->next!=NULL)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr1->next=NULL;
        free(ptr2);
    }
}

void deletion_position()
{
    int node_count=0,i,position;

    struct node* ptr=head;

    while(ptr!=NULL)
    {
        node_count++;
        ptr=ptr->next;
    }

    if(head==NULL)
    {
        printf("\nThe list is already empty!");
        return;
    }

    else if(head->next==NULL)
    {
        char ans;
        printf("\nThere is only one element at position 1 so do you wanna delete it?(y,n)?");
        scanf(" %c",&ans);

        if(ans=='y' || ans=='Y')
        {
            free(head);
            head=NULL;
        }
        else
        {
            printf("\nOperation cancelled!");
            return;
        }
    }

    else
    {
        printf("\nInsert the position to delete(1 to %d):",node_count);
        scanf("%d",&position);
        
        struct node* ptr=head->next;
        struct node* temp=head;
        if(position==1)
        {
            head=head->next;
            free(ptr);
        }

        else
        {
            for(i=1;i<position-1;i++)
            {
                ptr=ptr->next;
                temp=temp->next;
                if(ptr==NULL)
                {
                    printf("\nPosition not found!");
                    return;
                }
            }
            temp=ptr->next;
            free(ptr);
        }
    }
}

void display()
{
    struct node *ptr;
    ptr = head;

    printf("\nLinked List Data: ");

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
