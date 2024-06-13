/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

class Solution 
{
public:
    double returnResult(const short& sizeOfMergedArr, const std::vector<int>& nums)
    {
        if(sizeOfMergedArr % 2 == 1)
        {
            return static_cast<double>(nums[sizeOfMergedArr / 2]);
        }

        return static_cast<double>(nums[sizeOfMergedArr / 2] + nums[sizeOfMergedArr / 2 - 1]) / 2;
    }

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        short n1 = nums1.size();
        short n2 = nums2.size();
        
        if(n1 < n2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        nums1.insert(nums1.end(), nums2.begin(), nums2.end()); // Merge vectors

        std::sort(nums1.begin(), nums1.end()); // Sort the merged vector using std::sort

        return returnResult((n1 + n2), nums1);
    }
};
