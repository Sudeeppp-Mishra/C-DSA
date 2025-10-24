/* 
Stack Implementation using array
Stack ADT:
push()
pop()
display()
peek()
is_full()
is_empty()
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int top;
int stack[SIZE];

void initialize();
void push(int);
void pop();
void peek();
void display();
int is_empty();
int is_full();

int main()
{
    initialize();
    int choice;

    while (1)
    {
        printf("\nEnter \n1 for push \n2 for pop \n3 for display \n4 for peek \n5 for exit:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (!is_full())
                {
                    int value;
                    printf("\nEnter the element to be pushed:\n");
                    scanf("%d", &value);
                    push(value);
                }
                else
                {
                    printf("\nSTACK OVERFLOW\n");
                }
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("\nEnter a valid option!!!!\n");
                break;
        }
    }

    return 0;
}

void initialize()
{
    top = -1;
}

int is_full()
{
    return top == SIZE - 1;
}

int is_empty()
{
    return top == -1;
}

void push(int value)
{
    stack[++top] = value;
    printf("\n%d pushed successfully!!\n", value);
}

void pop()
{
    if (!is_empty())
    {
        int deleted_value = stack[top--];
        printf("\n%d popped successfully!!\n", deleted_value);
    }
    else
    {
        printf("\nSTACK UNDERFLOW\n");
    }
}

void peek()
{
    if (is_empty())
    {
        printf("\nStack is Empty so nothing to show!\n");
    }
    else
    {
        printf("\nThe top element in the stack is: %d\n", stack[top]);
    }
}

void display()
{
    if (is_empty())
    {
        printf("\nStack is empty so nothing to show\n");
    }
    else
    {
        int i;
        printf("\nStack Elements: ");
        for (i = top; i >= 0; i--)
        {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}