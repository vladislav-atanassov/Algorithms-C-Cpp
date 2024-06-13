/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

#include <iostream>
#include <vector>
#include <string>

class Solution 
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) 
    {
        int minLen = INT_MAX;

        // Find the minimum length of strings
        for(const std::string& str : strs) 
        {
            minLen = std::min(minLen, static_cast<int>(str.size()));
        }

        int low = 1;
        int high = minLen;
        bool commonPrefix;

        // Binary search for the common prefix length
        while(low <= high) 
        {
            int mid = (low + high) / 2;
            commonPrefix = true;

            // Check if the substrings of length 'mid' are equal for all strings
            for(int i = 1; i < strs.size(); i++) 
            {
                if(strs[i].compare(0, mid, strs[0], 0, mid) != 0) 
                {
                    commonPrefix = false;
                    break;
                }
            }

            if(commonPrefix)
            {
                low = mid + 1;  // If common prefix found, search in the right half
            } 
            else 
            {
                high = mid - 1;  // If no common prefix, search in the left half
            }
        }

        // Return the common prefix substring
        return strs[0].substr(0, (low + high) / 2);
    }
};