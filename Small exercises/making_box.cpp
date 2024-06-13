#include <iostream>
#include <string>

void making_box(int size)
{   
    for(int i = 0; i < size; i++)
    {
        if(i == 0 || i == size - 1)
        {
            // Using std::string to be able to multiply chars

            std::cout << std::string(size, '#') << std::string(2, ' ') << std::endl;
            continue;
        }

        std::cout << '#' << std::string((size - 2), ' ') << '#' << std::endl;
    }
}

/*
Example input

int main()
{
    int size_box;

    do
    {   
        // User input
        std::cout << "Enter size for the box: "; 
        std::cin >> size_box;

        if(size_box <= 0)
        {
            std::cout << "Enter a positive non-zero number!" << std::endl;
            continue;
        }

        break;
    
    } while(true);

    making_box(size_box);
}
*/