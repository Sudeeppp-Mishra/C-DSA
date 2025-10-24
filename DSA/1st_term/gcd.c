#include<stdio.h>

int gcd(int, int, int);
int main()
{
    int n1, n2, min;
    printf("Enter two no;");
    scanf("%d%d",&n1,&n2);

    min=n1<n2?n1:n2;

    printf("GCD is %d",gcd(n1,n2,min));
}

int gcd(int n1, int n2, int min)
{
    if(min==0)
    {
        return n2!=0?n2:n1;
    }
    else if(n1%min==0 && n2%min==0)
    {
        return min;
    }
    else
    {
        return gcd(n1,n2,min-1);
    }
}