#include<stdio.h>

int GCD(int,int,int);

int main()
{
    int n1,n2;
    printf("Enter two no.s:");
    scanf("%d%d",&n1,&n2);
    int lwr=n1<n2?n1:n2;

    printf("HCF is %d",GCD(n1,n2,lwr));
}

int GCD(int n1,int n2, int lwr)
{
    if(lwr==1)
        return 1;
    else
    {
        if(n1%lwr==0 && n2%lwr==0)
            return lwr;
        else
            return GCD(n1,n2,--lwr);
    }
}