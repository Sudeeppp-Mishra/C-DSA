
#include<stdio.h>
#include<stdlib.h>

void TOH(char, char, char, int);
int main()
{
    int n;
    printf("Enter no. of disks:");
    scanf("%d",&n);

    //Exception handling for non-positive number of disks
    if(n<=0)
    {
        printf("\nThere is nothing to move!");
        exit(0);
    }

    TOH('S', 'D', 'I', n);

    return 0;
}

void TOH(char from, char to, char aux, int n)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",from, to);
        return;
    }

    TOH(from, aux, to, n-1);
    printf("Move disk %d from %c to %c\n",n, from, to);
    TOH(aux, to, from, n-1);
}


/*
#include <stdio.h>
#include <stdlib.h>

// Function prototype for Tower of Hanoi
void TOH(char from, char to, char aux, int n);

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Exception handling for non-positive number of disks
    if (n <= 0) {
        printf("\nThere is nothing to move!\n");
        exit(0);
    }

    // Call the TOH function to solve the puzzle
    TOH('S', 'D', 'I', n);

    return 0;
}

// Function to perform the Tower of Hanoi algorithm
void TOH(char from, char to, char aux, int n) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    // Move n-1 disks from 'from' to 'aux' using 'to' as auxiliary
    TOH(from, aux, to, n - 1);
    
    // Move the nth disk from 'from' to 'to'
    printf("Move disk %d from %c to %c\n", n, from, to); // Added \n here
    
    // Move the n-1 disks from 'aux' to 'to' using 'from' as auxiliary
    TOH(aux, to, from, n - 1);
}
*/