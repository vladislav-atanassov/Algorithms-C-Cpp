/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
*/

#include <iostream>
#include <vector>

class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) 
    {
        int front_it = 0, tail_it = numbers.size() - 1;

        // Check if the vector consists of only 2 elements
        if((tail_it + 1) == 2) 
        {
            return {1, 2};
        }

        // Traverse until the iterators meet at the middle
        while(front_it < tail_it)
        {
            if(numbers[(size_t)front_it] + numbers[(size_t)tail_it] == target) 
            {
                return {front_it + 1, tail_it + 1}; 
            }
            else if(numbers[(size_t)front_it] + numbers[(size_t)tail_it] < target) 
            {
                front_it++;
            }
            else
            {
                tail_it--;
            } 
        }

        return {front_it, tail_it};  
    }
};
