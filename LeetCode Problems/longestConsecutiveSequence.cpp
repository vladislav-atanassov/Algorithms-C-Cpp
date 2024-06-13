/*
Given an unsorted array of integers nums, 
return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int longestConsecutive(std::vector<int>& nums) 
    {
        if(nums.size() == 0)
        {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int currentLongest = 1, longest = 0;

        for(size_t i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] != nums[i + 1])
            {
                if(nums[i] == nums[i+1] - 1)
                {
                    currentLongest++;
                    continue;
                }

                longest = std::max(longest, currentLongest);
                currentLongest = 1;
            }
        }

        return (currentLongest > longest ? currentLongest : longest);
    }
};