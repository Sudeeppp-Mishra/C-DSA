#include<stdio.h>

int main()
{
    int n1,n2;
    printf("Enter two no.s:");
    scanf("%d%d",&n1,&n2);

    int lwr=n1>n2?n2:n1;

    if(lwr==1)
        printf("1 is HCF");
    else
    {
    while(lwr!=1)
    {
        if(n1%lwr==0 && n2%lwr==0)
        {
            printf("%d is HCF.",lwr);
            break;
        }
            lwr--;
    }
}
}