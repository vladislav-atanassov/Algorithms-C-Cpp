#include <stdio.h>

// Knapsack problem using Dynamic Programming approach
// The solution is always produces the maximum amount 

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int knapsack(int values[], int weights[], int numItems, int capacity) 
{
    // Initialize a 2D array to store results of subproblems
    int dp[numItems + 1][capacity + 1];

    // Fill the DP table
    for (int i = 0; i <= numItems; i++) 
    {
        for (int j = 0; j <= capacity; j++) 
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;  // Base case: no items or no capacity
            }
            else if(weights[i - 1] <= j)
            {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The result is in the bottom-right corner of the DP table
    return dp[numItems][capacity];
}
/*
Example input

int main() 
{
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int numItems = 3;
    int capacity = 50;

    int maxValue = knapsack(values, weights, numItems, capacity);

    printf("Maximum value: %d\n", maxValue); // Expected 220

    return 0;
}
*/
