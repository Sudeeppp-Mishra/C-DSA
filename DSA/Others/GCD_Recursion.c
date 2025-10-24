#include <stdio.h>

int gcd(int, int, int); // Function prototype
int main()
{
    int n1, n2;

    // Prompt the user to enter two numbers
    printf("Enter two no.s:");
    scanf("%d%d", &n1, &n2);

    // Determine the smaller number
    int min = n1 < n2 ? n1 : n2;

    // Calculate and print the GCD
    printf("HCF is: %d", gcd(n1, n2, min));
}

// Recursive function to calculate GCD
int gcd(int n1, int n2, int min)
{
    // if min is zero, return non-zero number
    if (min == 0)
        return n1 != 0 ? n1 : n2;

    // condition of GCD
    else if (n1 % min == 0 && n2 % min == 0)
        return min;

    // Recur with min decrement by one
    else
        return gcd(n1, n2, min - 1);
}