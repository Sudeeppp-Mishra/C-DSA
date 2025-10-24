#include<stdio.h>

long int fact(int);
int main()
{
    int no;
    printf("Enter the no whose factorial is to be found:");
    scanf("%d",&no);
    printf("%d!=%ld",no,fact(no));
    return 0;
}

long int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}