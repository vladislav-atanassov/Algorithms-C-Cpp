/*
NOT a LeetCode question(I have not looked this up)

I got this problem in an interview:
Suppose that you have a comment section that you want to go through 
and find if there is a particular word in it.

Make a function that does that.
Given an array of the comments and the word you are looking for:

The count does not increase if the given word is found more than once in one comment.
The words in the comments are separated with underscore "_".
It should count the words no matter lower ot upper case.

Example:
Input: ["Bad_bad_BAD", "bad", "good"], "bad"
Output: 2
*/

#include <iostream>
#include <vector>
#include <string>

std::string toLowerString(std::string word)
{
    for(size_t i = 0; i < word.size(); i++)
    {
        word[i] = tolower(word[i]);
    }

    return word;
}

int countKeyWords(std::vector<std::string> comments, std::string keyWord)
{
    int counter = 0;
    size_t keyWordSize = keyWord.size();

    keyWord = toLowerString(keyWord);

    for(size_t i = 0; i < comments.size(); i++)
    {
        for(size_t j = 0; j < comments[i].size() - keyWordSize + 1; j++)
        {
            if(comments[i][j] != '_')
            {
                if(keyWord == toLowerString(comments[i].substr(j, j + keyWordSize)))
                {
                    counter++;
                    break;
                }
            }
        }
    }

    return counter;
}

/*
int main()
{
    std::vector<std::string> comments = {"apple", "banana", "apple pie", "Orange", "APPLE tree"};
    std::string keyWord = "apple";

    int result = countKeyWords(comments, keyWord); // Expected output: 3

    std::cout << "The keyword '" << keyWord << "' appears " << result << " times." << std::endl; 

    return 0;
}
*/