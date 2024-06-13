/*
Given a binary string s and a positive integer n, return true 
if the binary representation of all the integers in the range [1, n] 
are substrings of s, or false otherwise.
A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "0110", n = 3
Output: true
Example 2:

Input: s = "0110", n = 4
Output: false
*/

#include <iostream>

class Solution {
public:
    std::string bitsInNumber(int number)
    {
        std::string result = "";

        for(int i = 7, n = 0; i >= 0; i--, n++)
        {
            if(((number >> i) & 1))
            {
                result.append("1");
            } 
            else
            {
                result.append("0");
            }
        }  

        if(result != "0") 
        {  
            while(result[0] == (const char&)("0"))
            {
                result.erase(result.begin());
            }
        }

        return result;
    }

    bool isSubstring(const std::string& s1, const std::string& s2)
    {
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1.substr(i, s2.size()) == s2)
            {
                return true;
            }
        }

        return false;
    }

    bool queryString(std::string s, int n) 
    {
        for(int i = 0; i <= n; i++)
        {
            std::string tempString = bitsInNumber(i);

            for(int j = 0; j < s.size(); j++)
            {
                if(!isSubstring(s, tempString))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{   
    Solution sol;

    sol.queryString("0110", 4);

    return 0;
}