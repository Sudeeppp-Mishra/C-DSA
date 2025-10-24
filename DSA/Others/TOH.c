#include<stdio.h>

void TOH(int,char,char,char);
int main()
{
    int n;
    printf("Enter no. of disks:");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("There is nothing to move!");
    }
    else
    {
        TOH(n,'S','M','D');
    }
}

void TOH(int n, char A, char B, char C)
{
    if(n==1)
    {
        printf("\nMove disk 1 from %c to %c",A,C);
        return;
    }
    TOH(n-1,A,B,C);
    printf("\nMove disk %d from %c to %c",n,A,B);
    TOH(n-1,B,A,C);
}