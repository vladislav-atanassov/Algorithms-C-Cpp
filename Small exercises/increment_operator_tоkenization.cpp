#include <iostream>
int x = 4, y = 1;
int main()
{
    x+++++y;    //* It is tokenazied like this -> (x++)++)+y -> (5)++ invalid
    std::cout << x << y;
}

//* Output: !error: lvalue required as increment operand
