#include <iostream>

int main()
{
    std::cout << -!!"";
}

//* Output: -1 
// Explanation: minus (false * false) = minus true -> -1