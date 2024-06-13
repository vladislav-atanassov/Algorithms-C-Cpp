#include <iostream>
#include <vector>

struct Vertex
{
    int x, y, z;

    Vertex(int x, int y, int z)
        : x(x), y(y), z(z)
    {
    }

    Vertex(const Vertex& vertex)
        :x(vertex.x), y(vertex.y), z(vertex.z)
    {   
        std::cout << "Copied!" << std::endl;
    }
};

/*
Example

int main()
{   
    // Gets copied 6 times (1 + 2 + 3) due to reallocation
    std::vector<Vertex> vertices;

    vertices.push_back(Vertex(1, 2, 3));    
    vertices.push_back(Vertex(4, 5, 6));
    vertices.push_back(Vertex(7, 8, 9));

    std::cout << "----------------------" << std::endl;

    // When knowing that we will push_back 3 times 
    // we allocate the memory needed from the first time
    // so reducing the copies to 3
    std::vector<Vertex> vertices2;
    
    vertices2.reserve(3);

    vertices2.push_back(Vertex(1, 2, 3));    
    vertices2.push_back(Vertex(4, 5, 6));
    vertices2.push_back(Vertex(7, 8, 9));

    std::cout << "----------------------" << std::endl;

    // emplase_back() adds the arguments directly to the already
    // existing object therefore reducing the copies to 0 
    std::vector<Vertex> vertices3;
    
    vertices3.reserve(3);

    vertices3.emplace_back(1, 2, 3);    
    vertices3.emplace_back(4, 5, 6);
    vertices3.emplace_back(7, 8, 9);

    std::cout << "----------------------" << std::endl;

    return 0;
}
*/