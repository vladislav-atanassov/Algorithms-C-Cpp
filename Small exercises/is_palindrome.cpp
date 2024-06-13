#include <iostream>
#include <string>
#include <cassert>
#include <functional>

bool is_palindrome(std::string word)
{
    int i = 0;
    int size = word.size();
    
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    if(word.empty())
    {   
        std::cout <<"The string is empty!" << std::endl;
        return false;
    }
    
    for(i = 0; i < size / 2; i++)
    {
        if(word[i] != word[size - i - 1])
        {
            std::cout <<"Not a palindrome!" << std::endl;
            return false;
        }
    }
    
    std::cout <<"The word is a palidrome!" << std::endl;

    return true;
}

bool assertion_is_palidrome(bool should_print = true)
{
    assert(is_palindrome("LLoll") == true);
    assert(is_palindrome("WordroW") == true);
    assert(is_palindrome("1234321") == true);
    assert(is_palindrome("") == false);
    assert(is_palindrome("etqr") == false); 

    std::cout << "ALL TESTS PASSED!!!";

    return true;
}

/*
Example

int main()
{
    assertion_is_palidrome();
}
*/
