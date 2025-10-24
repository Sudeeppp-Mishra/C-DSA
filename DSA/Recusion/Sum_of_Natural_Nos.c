#include<stdio.h>

int sum(int);

int main()
{
    int n;
    printf("Enter the natural no. upto which sum is required:");
    scanf("%d",&n);
    printf("\nSum of natural no.s upto %d is %d",n,sum(n));
    return 0;
}

int sum(int n)
{
    if(n==0)
        return 0;
    else   
        return n+sum(n-1);
}