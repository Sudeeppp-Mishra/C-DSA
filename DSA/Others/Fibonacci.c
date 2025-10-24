#include<stdio.h>

int main()
{
    int terms;
    printf("Enter no. of terms:");
    scanf("%d",&terms);
    int a=0, b=1, c;
    for(int i=1;i<=terms;i++)
    {
        printf("%d\t",a);
        c=a+b;
        a=b;
        b=c;
    }
}