#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int binary_search(int a[], int n, int key)
{
    int low, high, mid;
    low = 0;
    high = n-1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if (key == a[mid])
            return mid;

        if (key > a[mid])
            low = mid + 1;
        else
            high = mid -1;
    }
    return -1;
}

int binary_search_recursive(int a[], int low, int high, int key)
{
    int mid;

    if (low > high)
        return -1;

    mid = (low + high) / 2;

    if (a[mid] == key)
        return mid;

    if (key > a[mid])
        return binary_search_recursive(a, mid+1, high, key);
    else
        return binary_search_recursive(a, low, mid-1, key);
}

int main()
{
    int size,key;
    printf("Enter size of array : ");
    scanf("%d", &size);

    int* a = malloc(size*sizeof(int));
    printf("\nEnter elements of array :\n");
    for(int i=0; i<size; i++)
        scanf("%d", &a[i]);

    printf("\nEnter the key to search : ");
    scanf("%d", &key);

    //int result = binary_search(a,size,key);
    int result = binary_search_recursive(a,0,size,key);

    result==-1?printf("Key not found!"):printf("Key found at index %d", result);

    return 0;
}
