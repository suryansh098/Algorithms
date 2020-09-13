#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int linear_search(int a[], int size, int key)
{
    for(int i=0; i<size; i++)
    {
        if(a[i]==key)
            return i+1;
    }
    return -1;
}

int linear_search_recursive(int a[], int size, int key)
{
    if(size==0)
        return -1;
    if(a[size-1]==key)
        return size;
    else
        return linear_search_recursive(a,size-1,key);
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

    //int result = linear_search(a,size,key);
    int result = linear_search_recursive(a,size,key);

    result==-1?printf("Key not found!"):printf("Key found at position %d", result);

    return 0;
}
