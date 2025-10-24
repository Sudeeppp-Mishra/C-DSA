#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head=NULL;

void insertion_beginning(); //Function to implement linked list where insertion will be done at the beginning
void insertion_end(); //For insertion at the end of linked list
void insertion_position(); //For insertion at a specified position by the user
void display(); //Displaying all the datas of the linked list

int info;

int main()
{
    int choice;
    while(1)
    {
        //Gettig what to do from the user??
        printf("\nEnter \n1 for insetion at beginning\n 2 for insertion at the end \n3 for insertion at specified position \n4 for deletion from beginning \n5 for deletion from the end \n6 for deletion form specified postion \n7 for display \n8 for exit:\n");
        scanf("%d",&choice);


        //Switching betweent he choices that user made
        switch(choice)
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
                printf("\nEnter one of the VALID OPTIONS!"); //If INVALD option is choosen by the user
        }
    }
}

void insertion_beginning()
{
    //Create a newnode
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    //Take i/p from user and assign the value to the data field of the node
    printf("\nEnter the data:");
    scanf("%d",&info);
    newnode->data=info;

    //Assigning the head to the next field of newnode and finally making the newnode the head
    newnode->next=head;
    head=newnode;
}

void insertion_end()
{
    //Create newnode
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    //Take i/p and assign to data field and assigning NULL to the next field
    printf("Enter the data:");
    scanf("%d",&info);
    newnode->data=info;
    newnode->next=NULL;

    //Check if the list is empty
    if(head==NULL)
    {
        //Making the newnode the head
        head=newnode;
    }

    else
    {
        struct node* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}

void insertion_position()
{
    //Taking the postion where we need to insert the node
    int position;
    printf("\nEnter the position:");
    scanf("%d",&position);
    int i;

    //Create newnode
    struct node* newnode=(struct node*)malloc(sizeof(struct node));

    //Taking value and assigning it to the data field
    printf("\nEnter the value to be inserted:");
    scanf("%d",&info);
    newnode->data=info;

    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }

    else
    {
        struct node* ptr=head;
        for(i=0;i<position;i++)
        {
            ptr=ptr->next;
            newnode->next=ptr->next;
            ptr->next=newnode;
            if(ptr==NULL)
            {
                printf("\nPostion not found!");
            }
        }
    }
}




void display()
{
    struct node* ptr;
    ptr=head;

    printf("\nLinked List Data: ");

    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}
