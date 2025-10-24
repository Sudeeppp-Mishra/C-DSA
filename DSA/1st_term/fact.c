#include<stdio.h>

long int fact(int);
int main()
{
    int n;
    printf("Enter a nubmer:");
    scanf("%d",&n);
    printf("%d!=%ld",n,fact(n));
}

long int fact(int n)
{
    if(n==0)
        return 1;
    else
    return n*fact(n-1);
}