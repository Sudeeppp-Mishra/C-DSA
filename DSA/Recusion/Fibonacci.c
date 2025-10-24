#include<stdio.h>

int fib(int);
int i;
int main()
{
    int n;
    printf("Enter no. of terms:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",fib(i));
    }
    return 0;
}

int fib(int n)
{
    if(n<=1)
        return n;
    else
        return fib(n-1)+fib(n-2);
}