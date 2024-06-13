#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) 
    {
        if(s.size() <= 1)
        {
            return true;
        }

        size_t begin = 0, end = s.size() - 1;

        while(end > begin)
        {
            if(!isalnum(s[begin]))
            {
                begin++;
                continue;
            }

            if(!isalnum(s[end]))
            {
                end--;
                continue;
            }

            if(tolower(s[begin]) != tolower(s[end]))
            {
                return false;
            }
            else
            {
                begin++;
                end--;
            }
        }

        return true;
    }
};