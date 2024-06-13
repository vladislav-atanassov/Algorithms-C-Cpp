#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <vector>

using vector_pair_size_t = std::vector<std::pair<size_t, size_t>>;

class Solution 
{
public:
    int sum(const std::vector<int>& numbers, size_t startIndex, const size_t endIndex) 
    {
        int sum = 0;

        for (size_t i = startIndex; i <= endIndex; i++) 
        {
            sum += numbers[i];
        }

        return sum;
    }

    int subarraysDivByK(std::vector<int>& nums, int k) 
    {
        size_t arrSize = nums.size();

        vector_pair_size_t::iterator it;
        vector_pair_size_t devArrs;

        for(size_t i = 0; i < arrSize; i++)
        {
            for(size_t j = i; j < arrSize; j++)
            {
                if(sum(nums, i, j) % k == 0)
                {
                    it = std::find(devArrs.begin(), devArrs.end(), std::make_pair(i, j));

                    if(it == devArrs.end())
                    {
                        devArrs.emplace_back(std::make_pair(i, j));
                    }
                }
            }
        }

        return devArrs.size();
    }
};