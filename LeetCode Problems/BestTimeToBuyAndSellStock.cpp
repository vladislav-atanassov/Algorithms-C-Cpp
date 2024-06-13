/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day 
to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

#include <iostream>
#include <vector>

class Solution 
{
public:
    int maxProfit(const std::vector<int>& prices) 
    {
        if(prices.size() == 2)
        {
            return (prices[1] - prices[0]) >= 0 ? (prices[1] - prices[0]) : 0;
        }
        else if(prices.size() == 1)
        {
            return 0;
        }

        int low = prices[0], high = prices[1], tempMax = 0;

        tempMax = high - low;

        for(size_t i = 1; i < prices.size(); i++)
        {   
            if(low > prices[i] && (i != prices.size() - 1))
            {
                low = prices[i];
                high = prices[i + 1];
                continue;
            }
            
            if(high < prices[i])
            {
                high = prices[i];
            }

            if(tempMax < (high - low))
            {
                tempMax = high - low;
            }
        }

        if(tempMax > (high - low))
        {
            return tempMax >= 0 ? tempMax : 0;
        }

        return (high - low) >= 0 ? (high - low) : 0;
    }
};
