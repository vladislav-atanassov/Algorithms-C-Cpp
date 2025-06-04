#include <iostream>

class A
{
    static int a;
};

int main()
{
    std::cout << sizeof(A);
}

//* Output: 1
// Explanation: empty base optimization