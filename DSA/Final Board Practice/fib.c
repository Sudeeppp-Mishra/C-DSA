#include<stdio.h>

void using_iteration(int);
void using_recursion(int);
int recur(int);

int main()
{
    int terms;
    printf("Enter no. of terms:");
    scanf("%d",&terms);
    printf("\n\nUsing Iteration\n\n");
    using_iteration(terms);
    printf("\n\nUsing Recursion\n\n");
    using_recursion(terms);
    return 0;
}

void using_iteration(int n)
{
    int a=0, b=1, c;
    for(int i=1;i<=n;i++)
    {
        printf("%d\t",a);
        c=a+b;
        a=b;
        b=c;
    }
}

void using_recursion(int n)
{
    for(int i=0;i<n;i++)
        printf("%d\t",recur(i));
}

int recur(int a)
{
    if(a<=1)
        return a;
    else
        return recur(a-1)+recur(a-2);
}