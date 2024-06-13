/*
Given an m x n integer matrix matrix, if an element is 0, 
set its entire row and column to 0's.

You must do it in place.
*/

#include <iostream>
#include <vector>

class Solution 
{
public:
    void setRowsAndColumnsToZero(std::vector<std::vector<int>>& matrix, size_t x, size_t y)
    {   
        for(size_t col = 0; col < matrix[0].size(); col++)
        {
            matrix[x][col] = 0;
        }

        for(size_t row = 0; row < matrix.size(); row++)
        {
            matrix[row][y] = 0;
        }
    }

    void setZeroes(std::vector<std::vector<int>>& matrix) 
    {
        std::vector<std::pair<size_t, size_t>> coordinatesZeros; 

        for(size_t row = 0; row < matrix.size(); row++)
        {
            for(size_t col = 0; col < matrix[0].size(); col++)
            {
                if(matrix[row][col] == 0)
                {
                    std::pair<size_t, size_t> pair = {row, col};
                    coordinatesZeros.emplace_back(pair);
                }
            }
        }

        for(size_t i = 0; i < coordinatesZeros.size(); i++)
        {
            setRowsAndColumnsToZero(matrix, 
                coordinatesZeros[i].first, coordinatesZeros[i].second);
        }
    }

    void printVector(const std::vector<std::vector<int>>& matrix) const
    {
        for(size_t row = 0; row < matrix.size(); row++)
        {
            for(size_t col = 0; col < matrix[0].size(); col++)
            {
                std::cout << matrix[row][col] << " ";
            }
            std::cout << std::endl;
        } 
        std::cout << std::endl;
    }
};
