/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. 
You can only hold at most one share of the stock at any time. 
However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/

#include <iostream>
#include <vector>

class Solution 
{
public:
    int maxProfit(const std::vector<int>& prices) 
    {
        int low = prices[0], high = prices[1];
        int tempProfit = 0, currentProfit = 0;
        size_t lastIndexOfLow = 0;

        for(size_t i = 1; i < prices.size(); i++)
        {   
            if(((low > prices[i]) || (high > prices[i])) && (i != prices.size() - 1))
            {
                low  = prices[i];
                high = prices[i + 1];
                lastIndexOfLow = i;
                currentProfit += tempProfit;
                tempProfit = 0;
                continue;
            }
            
            if(high < prices[i])
            {
                high = prices[i];
            }

            tempProfit = high - prices[lastIndexOfLow];
        }

        return tempProfit > 0 ? (currentProfit += tempProfit) : currentProfit;
    }
};

int main()
{
    Solution solution;
    std::vector<int> vec = {1,7,4,2};

    std::cout << solution.maxProfit(vec) << std::endl;

    return 0;
}