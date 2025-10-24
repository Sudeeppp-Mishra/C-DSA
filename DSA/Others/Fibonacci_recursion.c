#include<stdio.h>

int fib(int);
int main()
{
    int i, n;
    printf("Enter no. of terms:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",fib(i));
    }
}

int fib(int i)
{
    if(i<=1)
        return i;
    else
        return fib(i-1)+fib(i-2);
}