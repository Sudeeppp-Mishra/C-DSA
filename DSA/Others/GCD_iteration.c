
#include<stdio.h>

int main()
{
    int n1, n2;
    printf("Enter two no.s:");
    scanf("%d%d",&n1,&n2);
    int max=n1>n2?n1:n2;
    int min=n1<n2?n1:n2;
    for(int i=min;i>1;i--)
    {
        if(n1%i==0 && n2%i==0)
        {
            printf("%d is HCF",i);
            break;
        }
    }
}