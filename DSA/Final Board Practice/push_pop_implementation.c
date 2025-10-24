#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int top=-1, stack[SIZE];

void push()
{
    int value;
    if(top==SIZE-1)
    {
        printf("\nStack Overflow!");
    }
    else
    {
        printf("Enter value to be pushed:");
        scanf("%d",&value);
        stack[++top]=value;
        printf("%d pushed successfully!\n",value);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        int deleted_value=stack[top--];
        printf("\n%d popped successfully!",deleted_value);
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\nEnter 1 for push \n2 for pop \n3 for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Enter valid Option!");
        }
    }
}