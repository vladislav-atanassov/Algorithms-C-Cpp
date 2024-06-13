#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DESCENDING '>'
#define ASCENDING '<'

void print_array(const int arr[], const unsigned int size)
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

    printf("]");
}

bool compare(int a, int b, char operator)
{
    if(operator == ASCENDING)
    {
        return a < b;
    }
    else if(operator == DESCENDING)
    {
        return a > b;
    }

    printf("Invalid operator!");
    return false;
}

int* longestAscendingOrDescending(const int arr[], const unsigned int size, const char operator, int *length)
{
    if(!arr || size <= 0)
    {
        // Handle invalid input
        *length = 0;
        return NULL;
    }

    int temp_position = arr[0];
    int temp_counter = 1;
    int current_max_count = 0;
    int end_index = 0;

    for(int i = 1; i < size; i++)
    {
        // Move the temp_position and increment the temp_counter
        if(compare(temp_position, arr[i], operator))
        {
            temp_position = arr[i];
            temp_counter++;
        }
        else
        {
            // Assign current_max_count when every streak ends
            if(temp_counter > current_max_count)
            {
                end_index = i;
                current_max_count = temp_counter;
            }

            // And set the temp variables to start the counting again
            temp_position = arr[i];
            temp_counter = 1;
        }
    }

    // Handle edge case if the streak ends at the last index
    if(temp_counter > current_max_count)
    {
        end_index = size;
        current_max_count = temp_counter;
    }

    if(end_index == 0)
    {
        // No streak found
        *length = 0;
        return NULL;
    }

    int start_index = end_index - current_max_count;

    int* temp_arr = (int*)malloc(current_max_count * sizeof(int));
    if(temp_arr == NULL)
    {
        // Handle memory allocation failure
        *length = 0;
        return NULL;
    }

    // Fill the temp_array with the found streak
    for(int i = 0; i < current_max_count; i++)
    {
        temp_arr[i] = arr[start_index + i];
    }

    // Pass the length argument to keep track of the size of the array
    *length = current_max_count;

    return temp_arr;
}

void longestStreak(const int arr[], const unsigned int size)
{
    int lengthAscending, lengthDescending;

    int *arrAscendingMax = longestAscendingOrDescending(arr, size, ASCENDING, &lengthAscending);
    int *arrDescendingMax = longestAscendingOrDescending(arr, size, DESCENDING, &lengthDescending);

    if(lengthAscending == lengthDescending)
    {
        printf("The streaks are equal. They are both %d elements: \n", lengthAscending);
        print_array(arrAscendingMax, lengthAscending);
        printf(", ");
        print_array(arrDescendingMax, lengthDescending);
    }
    else if(lengthAscending > lengthDescending && lengthAscending > 0)
    {
        printf("The longest streak is ascending. It is %d elements: \n", lengthAscending);
        print_array(arrAscendingMax, lengthAscending);
    }
    else if(lengthDescending > 0)
    {
        printf("The longest streak is descending. It is %d elements: \n", lengthDescending);
        print_array(arrDescendingMax, lengthDescending);
    }
    else
    {
        printf("No valid streak found.\n");
    }

    free(arrAscendingMax);
    free(arrDescendingMax);
}

/*
Example input

int main()
{
    int arr[] = {3, 4, 7, 3, 5, 1, 2, 5, 6, 3, 5, 2, 3, 2, 1, 0, -1, -2};

    int size = sizeof(arr) / sizeof(arr[0]);

    longestStreak(arr, size);

    return 0;
}
*/