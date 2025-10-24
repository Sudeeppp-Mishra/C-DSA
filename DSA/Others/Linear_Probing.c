#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];
int array[SIZE];

void display();
void insert(int num);

int main()
{
    int n;
    printf("Enter no. of items: ");
    scanf("%d", &n);

    // Initialize hashTable and array
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;  // -1 indicates an empty slot in the hash table
    }

    printf("Enter the items: ");
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        insert(num);
    }

    display();

    return 0;
}

void insert(int num)
{
    int index = num % SIZE;
    int originalIndex = index;
    int count = 0;

    // Linear probing for collision resolution
    while (hashTable[index] != -1 && hashTable[index] != num) {
        index = (originalIndex + ++count) % SIZE;
        if (index == originalIndex) {
            printf("Hash table is full. Unable to insert %d\n", num);
            return;
        }
    }

    hashTable[index] = num;
}

void display()
{
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("%d: %d\n", i, hashTable[i]);
        else
            printf("%d: \n", i);
    }
}