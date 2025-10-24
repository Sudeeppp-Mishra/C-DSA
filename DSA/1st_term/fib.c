#include<stdio.h>

int fib(int);
int main()
{
    int n;
    printf("Enter no. of terms:");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",fib(i));
    }
}

int fib(int n)
{
    if(n<=1)
        return n;
    else
        return fib(n-1)+fib(n-2);
}