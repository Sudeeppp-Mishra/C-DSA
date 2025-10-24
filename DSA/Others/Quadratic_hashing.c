#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void insert(int);
void display();

int main()
{
    int key, i, n;

    printf("Enter no. of items: ");
    scanf("%d", &n);

    // Initialize hashTable with -1 to indicate empty slots
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1; // -1 indicates an empty slot in the hash table
    }

    // Input keys to be inserted into the hash table
    printf("Enter the keys: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    // Display the hash table
    display();

    return 0;
}

void insert(int data)
{
    int index = data % SIZE;      // Calculate the initial index
    int originalIndex = index;    // Store the original index for reference
    int count = 0;                // Initialize the count for quadratic probing

    // Quadratic probing loop to resolve collisions
    while (hashTable[index] != -1 && hashTable[index] != data) // hashTable[index]!=data helps for solving duplication of data in quadratic probing
    {
        count++; // Increment the count for probing

        // If all slots have been probed, the table is full
        if (count == SIZE)
        {
            printf("Hash table is full! Unable to insert %d\n", data);
            return;
        }

        // Calculate the next index using quadratic probing
        index = (originalIndex + count * count) % SIZE;
    }

    // Insert the data into the found index
    hashTable[index] = data;
}

void display()
{
    int i;
    // Display the contents of the hash table
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != -1)
            printf("%d: %d\n", i, hashTable[i]);
        else
            printf("%d: \n", i);
    }
}