#include <iostream>

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], const int left, const int mid, const int right)
{
    const int subArrayOne = mid - left + 1;
    const int subArrayTwo = right - mid;
 
    // Create temp arrays
    int *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for(int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];

    for(int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    // Merge the temp arrays back into array[left..right]
    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
    {
        if(leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) 
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else 
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }

        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while(indexOfSubArrayOne < subArrayOne) 
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while(indexOfSubArrayTwo < subArrayTwo) 
    {
        array[indexOfMergedArray]= rightArray[indexOfSubArrayTwo];

        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], const int begin, const int end)
{
    if(begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;

    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);

    merge(array, begin, mid, end);
}
 
// UTILITY FUNCTIONS
// Function to print an array
void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
 
// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    std::cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    std::cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
 
// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes