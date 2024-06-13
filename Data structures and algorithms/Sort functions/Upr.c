#include <stdio.h>
#include <stdbool.h>

bool findInteger(int number, int searchedNumber)
{
    if(searchedNumber == 0)
    {
        printf("The number is not found");
        return false;
    }
    else if(number %10 == searchedNumber)
    {
        printf("The number is found");
        return true;   
    }
    else
    {
        return findInteger((number / 10), searchedNumber);   
    }
}

int findSumOfArray(int array[], int index, int sum)
{
    if(!array[index])
    {
        return sum;
    }

    return findSumOfArray(array, index + 1, sum + array[index]);
}
