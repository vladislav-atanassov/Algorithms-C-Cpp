#include <iostream>

template<typename T>
int partition(T arr[], int low, int high)
{
    // Choose the pivot
    int pivot = arr[high];

    // Index of smaller element and Indicate
    // the right position of pivot found so far
    int i = (low - 1);
    
    for(int j = low; j <= high; j++)
    {
        // If current element is smaller than the pivot
        if(arr[j] < pivot)
        {
            // Increment index of smaller element
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[i + 1], arr[high]);
  
    return (i + 1);
}

template<typename T>
void qSort(T arr[], int low, int high)
{
    // When low is less than high
    if(low < high)
    {
        int partitionIndex = partition(arr, low, high);

        // Recursion calls smaller element than 
        // pivot goes left and higher element goes right
        qSort(arr, low, partitionIndex - 1);
        qSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    char charArr[] = {'s', 'a', 'd', 'b', 'c'};
    int intArr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(intArr) / sizeof(intArr[0]);

    qSort(intArr, 0, size-1);

    std::cout << "Sorted Array: ";

    for(int i = 0; i < size; i++)
    {
       std::cout << intArr[i] << " ";
    }

    return 0;
}