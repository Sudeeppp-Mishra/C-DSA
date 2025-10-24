#include<stdio.h>

void head(int n)
{
    if(n>0) // Base Case
    {
        head(n-1); // Head Recursive call i.e., first statement inside the function is recursive call
        printf("%d\n",n);
    }
}

int main()
{
    int p=3;
    head(p);
    return 0;
}