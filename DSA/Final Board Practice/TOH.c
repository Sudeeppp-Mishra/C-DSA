#include<stdio.h>

void hanoi(char, char, char, int);
int main()
{
    int n;
    top:
    printf("Enter no. of disks:");
    scanf("%d",&n);

    if(n<0)
    {
        printf("Disk can't be -ve! Please enter +ve no!\n");
        goto top;
    }
    else if(n==0)
    {
        printf("Nothing to move!");
    }
    else
    {
        hanoi('S','A','D',n);
    }
    return 0;
}

void hanoi(char src, char aux, char dest, int n)
{
    if(n==1)
    {
        printf("\nMove disk %d from %c to %c!",n,src, dest);
        return;
    }

    hanoi(src,dest,aux,n-1);
    printf("\nMove disk %d from %c to %c!",n,src,dest);
    hanoi(aux,src,dest,n-1);
}