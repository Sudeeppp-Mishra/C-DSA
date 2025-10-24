#include<stdio.h>

long int power(int,int);
int main()
{
    int b, e;
    printf("Enter the base and the exponent(power):");
    scanf("%d%d",&b,&e);
    printf("%d^%d=%ld",b,e,power(b,e));
    return 0;
}

long int power(int b, int e)
{
    if(e==0)
        return 1; 
    else
        return b*power(b,e-1);
}