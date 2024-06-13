#include <stdio.h>

int factorial(int number)
{
    if(number == 1)
    {
        return number;
    }

    return number * factorial(number - 1);

    // Also the if you want one line solution
    // return number == 1 ? number : number * factorial(number - 1);
}

/*
Example input

int main()
{
    printf("%d\n", factorial(4));   // Expected 24
    printf("%d\n", factorial(5));   // Expected 120
    printf("%d\n", factorial(9));   // Expected 362880
    return 0;
}
*/