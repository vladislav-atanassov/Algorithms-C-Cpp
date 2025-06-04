#include <iostream>

class A
{
public:
    virtual void foo(int a = 1) { std::cout << "A" << a; }
};

class B : public A
{
public:
    virtual void foo(int b = 2) { std::cout << "B" << b; }
};

int main()
{
    A* a = new B();
    a->foo();
}

//* Output: B1 
// Explanation: The function B::foo is called due to virtual dispatch, 
// but the default argument 1 is used from A::foo because default arguments are resolved based on the static type (A*) at compile time.
