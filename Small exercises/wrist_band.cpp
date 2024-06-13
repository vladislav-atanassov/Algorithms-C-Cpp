/*
Edabit expert level challenge C++

A wristband can have 4 patterns:

horizontal: each item in a row is identical.
vertical: each item in a column is identical.
diagonal left: each item is identical to the one on its upper left or bottom right.
diagonal right: each item is identical to the one on its upper right or bottom left.
You are shown an incomplete section of a wristband.

Write a function that returns true if the section can be correctly classified into one of the 4 types, and false otherwise.
*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

#define TEST
#ifdef TEST
void print_validation(std::string message){}
#else
void print_validation(std::string message)
{
    cout << message << endl;
}
#endif

bool is_horizontal(const vector<vector<char>>& arr, const int horizontal, const int vertical)
{
    int row = 0;
    int column = 0;

    for(row = 0; row < vertical - 1; row++)
    {
        for(column = 1; column < horizontal; column++)
        {
            if(arr[row][0] != arr[row][column])
            {
                return false;
            }
        }
    }

    print_validation("This a horizontal wrist band!");

    return true;
}

bool is_vertical(const vector<vector<char>>& arr, const int horizontal, const int vertical)
{
    int row = 0;
    int column = 0;

    for(row = 0; row < horizontal; row++)
    {
        for(column = 0; column < vertical - 1; column++)
        {
            if(arr[0][column] != arr[row][column])
            {
                return false;
            }
        }
    } 

    print_validation("This a vertical wrist band!");

    return true;
}

bool is_left_diagonal(const vector<vector<char>>& arr, const int horizontal, const int vertical)
{
    int row = 0;
    int column = 0;

    for(row = 0; row < horizontal - 1; row++)
    {
        for(column = 0; column < vertical - 2; column++)
        {
            if(arr[row][column] != arr[row + 1][column + 1])
            {
                return false;
            }
        }
    }

    print_validation("This a left diagonal wrist band!");

    return true;
}

bool is_right_diagonal(const vector<vector<char>>& arr, const int horizontal, const int vertical)
{
    int row = 0;
    int column = 0;

    for(row = 0; row < vertical - 1; row++)
    {
        for(column = horizontal - 1; column > 1; column--)
        {
            if(arr[row][column] != arr[row + 1][column - 1])
            {
                return false;
            }
        }
    }

    print_validation("This is a right diagonal wrist band!");

    return true;
}

bool is_wrist_band(const vector<vector<char>>& arr)
{
    const int horizontal = arr[0].size();
    const int vertical = arr.size();

    if(arr.empty() || arr[0].empty())
    {
        print_validation("THE ARRAY IS EMPTY!!!");
        return false;
    }

    if (is_vertical(arr, horizontal, vertical) || 
        is_right_diagonal(arr, horizontal, vertical) ||
        is_left_diagonal(arr, horizontal, vertical) ||
        is_horizontal(arr, horizontal, vertical))
    {
        return true;
    }

    print_validation("There is no such pattern!");
    return false;
}

bool assertion_is_wrist_band()
{
    const vector<vector<char>> horizontal_arr = {{'A', 'A', 'A'},{'B', 'B', 'B'},{'C', 'C', 'C'}};
    const vector<vector<char>> vertical_arr = {{'A', 'B', 'C'},{'A', 'B', 'C'},{'A', 'B', 'C'}};
    const vector<vector<char>> left_diagonal_arr = {{'A', 'B', 'C'},{'C', 'A', 'B'},{'B', 'C', 'A'},{'A', 'B', 'C'}};
    const vector<vector<char>> right_diagonal_arr = {{'A', 'B', 'C'},{'B', 'C', 'A'},{'C', 'A', 'B'},{'A', 'B', 'A'}};
    const vector<vector<char>> false_right_diagonal_arr = {{'A', 'B', 'C'},{'B', 'C', 'A'},{'C', 'D', 'B'},{'A', 'B', 'A'}};
    const vector<vector<char>> empty_arr = {{}, {}, {}};

    const vector<vector<char>> arr2 {{'A', 'B', 'C'}, {'C', 'A', 'B'}, {'D', 'C', 'A'}, {'E', 'D', 'C'}};
    const vector<vector<char>> arr3 {{'A', 'B', 'C'}, {'B', 'C', 'A'}, {'C', 'A', 'B'}, {'A', 'B', 'A'}};
    const vector<vector<char>> arr4 {{'A', 'B', 'C'}, {'B', 'C', 'D'}, {'C', 'D', 'E'}, {'D', 'E', 'F'}};
    const vector<vector<char>> arr5 {{'A', 'B', 'C'}, {'B', 'C', 'D'}, {'C', 'D', 'E'}, {'D', 'E', 'E'}};
    const vector<vector<char>> arr6 {{'A', 'B', 'C'}, {'B', 'C', 'D'}, {'C', 'D', 'E'}, {'D', 'F', 'E'}};
    const vector<vector<char>> arr7 {{'A', 'B', 'C'}, {'B', 'D', 'A'}, {'C', 'A', 'B'}, {'A', 'B', 'A'}};
    const vector<vector<char>> arr8 {{'A', 'B', 'C'}, {'C', 'A', 'B'}, {'D', 'C', 'A'}, {'E', 'D', 'C'}};
                            
    assert(is_wrist_band(arr2) == true);
    assert(is_wrist_band(arr3) == true);
    assert(is_wrist_band(arr4) == true);
    assert(is_wrist_band(arr5) == true);
    assert(is_wrist_band(arr6) == false);
    assert(is_wrist_band(arr7) == false);
    assert(is_wrist_band(arr8) == true);

    assert(is_wrist_band(empty_arr) == false);
    assert(is_wrist_band(horizontal_arr) == true);
    assert(is_wrist_band(vertical_arr) == true);
    assert(is_wrist_band(left_diagonal_arr) == true);
    assert(is_wrist_band(right_diagonal_arr) == true);
    assert(is_wrist_band(false_right_diagonal_arr) == false);

    cout << "ALL TESTS PASSED!!!" << endl;

    return true;
}

/*
Example 

int main()
{
    assertion_is_wrist_band();
}

*/
