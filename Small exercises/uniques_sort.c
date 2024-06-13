#include <stdio.h>
#include <stdlib.h>

void printArray(const int arr[], const unsigned int size)
{
    printf("[");

    for(int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);

        if(i < size - 1)
        {
            printf(", ");
        }
    }

    printf("]\n");
}

int* uniques_sort(int arr[], const unsigned int size, unsigned int* sorted_size)
{
    unsigned int i, j, index_sorted_arr = 0, temp;

    int* sorted_arr = (int*)malloc(sizeof(int) * size);

    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    sorted_arr[0] = arr[0];
    index_sorted_arr++;

    for (i = 0; i < size - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            sorted_arr[index_sorted_arr] = arr[i + 1];
            index_sorted_arr++;
        }
    }

    sorted_arr = (int*)realloc(sorted_arr, sizeof(int) * index_sorted_arr);
    *sorted_size = index_sorted_arr;

    return sorted_arr;
}

/*
Example input

int main()
{
    unsigned int size = 10;
    int arr[10] = {1, 2, 3, 2, 4, 2, 5, 3, 6};

    printf("This is the array you inputted: ");
    printArray(arr, size);

    int *arr_ptr = uniques_sort(arr, size, &size);
    int sorted_size = size;

    printf("These are the unique elements: ");
    printArray(arr_ptr, sorted_size);

    free(arr_ptr);

    return 0;
}
*/