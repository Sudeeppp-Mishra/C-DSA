#include<stdio.h>

int using_iteration()
{
    int n;
    long int fact=1;
    printf("Enter a no:");
    scanf("%d",&n);
    for(int i=n;i>0;i--)
    {
        fact*=i;
    }
    printf("%d!=%ld\n\n",n,fact);
    return 0;
}

long int fact(int);
int main()
{
    printf("Using ITERATION\n\n");
    using_iteration();

    printf("\n\nUsing Recursion\n\n");
    int n;
    printf("Enter the no. whose factorial is to be determined:");
    scanf("%d",&n);
    printf("\n%d!=%ld",n,fact(n));
    return 0;
}

long int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
