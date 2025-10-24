#include<stdio.h>

int insertion_sort(int[], int);
int display(int[],int);

int main()
{
    int a[]={10, 56, 1, 88, 44, 32, 87};
    int size=sizeof(a)/sizeof(a[0]);

    insertion_sort(a, size);
    display(a, size);
    return 0;
}

int insertion_sort(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[min]>arr[j])
                min=j;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

int display(int arr[], int size)
{
    printf("Sorted Array: ");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
}