/*
Implementation of stack using array
*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void push(int); //Pushing element or data to the stack
int is_full();  //Checks whether the stack is full or not?
int pop();  //Deletes one element form the stack
void peek();    //Shows the top most element in the stack
void display(); //Shows all elements in the stack
int is_empty();

int stack[SIZE], top=-1;

int main()
{
    int choice, data;
    while(1)
    {
        printf("\nEnter: \n1 for push\n2 for pop\n3 for peek\n4 for display \n5 for exit\n: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the data:");
                scanf("%d",&data);
                push(data);
                printf("\n%d is pushed successfully!",data);
                break;

            case 2:
                data=pop();
                printf("\n%d popped successfully!",data);
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Enter valid option only!");
                
        }
    }
}

int is_full()
{
    if(top==SIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_empty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if(is_full())
    {
        printf("\nStack Overflow!");
        exit(0);
    }
    else
    {
        stack[++top]=data;
    }
}

int pop()
{
    if(is_empty())
    {
        printf("Stack Underflow!");
        exit(0);
    }
    else
    {
        int deleted_data=stack[top];
        top--;
        return deleted_data;
    }
}

void peek()
{
    if(is_empty())
    {
        printf("\nStack is Empty!");
    }
    else
    {
        printf("\n%d is on the top of stack",stack[top]);
    }
}

void display()
{
    if(is_empty())
    {
        printf("Stack is empty!");
    }
    else
    {
        printf("\nThe datas in the stack are:\n");
        for(int i=0;i<=top;i++)
        {
            printf("\n%d\n",stack[i]);
        }
    }
}