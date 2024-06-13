/*
Check if the parantheses are closed correctly.

Input: s = "{}" 
Output: true

Input: s = "{[}]"
Output: false

Input: "()[]{}"
Output: true

*/

#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s) 
{
    int len = 0;

    while(s[len] != '\0') 
    {
        len++;
    }

    int stack[len];
    int top = -1;

    for(int currIndex = 0; s[currIndex] != '\0'; currIndex++) 
    {
        if(s[currIndex] == '(' || s[currIndex] == '[' || s[currIndex] == '{') 
        {
            stack[++top] = s[currIndex];
        } 
        else if(top == -1 ||
                   (s[currIndex] == ')' && stack[top] != '(') ||
                   (s[currIndex] == ']' && stack[top] != '[') ||
                   (s[currIndex] == '}' && stack[top] != '{')) 
        {
            return false;
        } 
        else 
        {
            top--;
        }
    }

    return top == -1;
}