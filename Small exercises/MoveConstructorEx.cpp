#include <iostream>
#include <string.h>

class MyString 
{
public:
    char* data;
    size_t size;

    // Default constructor
    MyString() : data(nullptr), size(0) 
    {
        std::cout << "Default Constructor" << std::endl;
    }

    // Parameterized constructor
    MyString(const char* str) : size(strlen(str)) 
    {
        data = new char[size + 1]; // One more char for the '\0' terminator
        strcpy(data, str);
        std::cout << "Parameterized Constructor: " << data << std::endl;
    }

    // Move constructor
    MyString(MyString&& other) noexcept : data(other.data), size(other.size) 
    {
        // Steal the resources from 'other'
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move Constructor: " << data << std::endl;
    }

    // Destructor
    ~MyString() 
    {
        if(data != nullptr) 
        {
            delete[] data;
            std::cout << "Destructor: " << data << std::endl;
        }
    }
};

/*
Example input

int main() {
    // Create an object using the parameterized constructor
    MyString str1("Hello, World!");

    // Create another object using the move constructor
    MyString str2 = std::move(str1);

    // Output the contents of str1 (after move, it's in a valid but unspecified state)
    std::cout << "After Move, str1: " << (str1.data ? str1.data : "nullptr") << std::endl;
    std::cout << "After Move, str2: " << (str2.data ? str2.data : "nullptr") << std::endl;

    return 0;
}
*/