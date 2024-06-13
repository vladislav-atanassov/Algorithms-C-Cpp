#include <stdio.h>
#include <stdlib.h>

void printArr(int* arr, const unsigned int size) 
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

void secondaryDiagonalInArray(int array2D[][3]) 
{
    int tempArray[3];
    int size = 0;

    while(array2D[size][size] != '\0') 
    {
        size++;
    }

    size--;

    for(int currRow = 0; currRow < size; currRow++) 
    {
        int currCol = size - currRow - 1;
        tempArray[currRow] = array2D[currRow][currCol];
    }

    printArr(tempArray, size);
}

/*
Example input

int main() 
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    secondaryDiagonalInArray(arr);
    return 0;
}
*/