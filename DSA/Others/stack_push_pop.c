#include<stdio.h>
#define SIZE 5

int top=-1, stack[SIZE];

void push(int value)
{
    if(top==SIZE-1)
    {
        printf("Stack Overflow!");
        return;
    }
    else
    {
        stack[++top]=value;
        printf("%d pushed successfully!",value);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow!");
        return;
    }
    else
    {
       int deleted_value=stack[top--];
        printf("%d popped successfully!",deleted_value);
    }
}

void dispay()
{
    if(top==-1)
    {
        printf("There is nothing to display:");
        return;
    }
    for(int i=0;i<=top;i++)
        printf("%d\t",stack[i]);
}

int main()
{
    int n;
    while(1)
    {
    printf("\nEnter 1 for push, 2 for pop, 3 for display:");
    scanf("%d",&n);
    if(n==1)
    {
        int value;
        printf("Enter the value you wanna push:");
        scanf("%d",&value);
        push(value);
    }
    if(n==2)
    {
        pop();
    }
    else
    {
        dispay();
    }
    }
}