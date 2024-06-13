#include <stdio.h>
#include <string.h>

void printSubarray(int arr[], int start, int end)
{
    printf("Longest Increasing Subarray: [");
    for (int i = start; i <= end; i++)
    {   
        if(i != end)
            printf("%d, ", arr[i]);
        else
            printf("%d]", arr[i]);
    }
    printf("\n");
}

int findLongestIncreasingSubarray(int arr[], const int size)
{
    int currMaxSeq = 1, tempMaxSeq = 1;
    int startIndex = 0, endIndex = 0;
    int tempStartIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            tempMaxSeq++;
        }
        else
        {
            if (tempMaxSeq > currMaxSeq)
            {
                currMaxSeq = tempMaxSeq;
                startIndex = tempStartIndex;
                endIndex = i - 1;
            }

            tempMaxSeq = 1;
            tempStartIndex = i;
        }
    }

    if(tempMaxSeq > currMaxSeq)
    {
        currMaxSeq = tempMaxSeq;
        startIndex = tempStartIndex;
        endIndex = size - 1;
    }

    printSubarray(arr, startIndex, endIndex);
    
    return currMaxSeq;
}

/*
Example input array for testing

int main()
{
    int arr[8] = {-1, 0, 4, 3, 5, 6, 7, 8};

    printf("Length of Longest Increasing Subarray: %d\n", findLongestIncreasingSubarray(arr, 8));

    return 0;
}
*/