/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.
*/

#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(const std::string& s, short begin, short end)
    {
        while(end >= begin)
        {
            if(s[begin] != s[end])
            {
                return false;
            }
            
            begin++;
            end--;
        }

        return true;
    }

    int countSubstrings(const std::string& s) 
    {
        int count = 0;

        for(short curIndex = 0; curIndex < s.size(); curIndex++)
        {
            std::string tempSubstring = s.substr(0, curIndex + 1);

            while(tempSubstring.size() != 0)
            {
                if(isPalindrome(tempSubstring, 0, tempSubstring.size() - 1))
                {
                    count++;
                }

                tempSubstring.erase(tempSubstring.begin());
            }
        }

        return count;
    }
};