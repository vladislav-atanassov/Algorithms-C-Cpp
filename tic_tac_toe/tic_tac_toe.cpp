#include <iostream>
#include <array>
#include <string>

#include "tic_tac_toe.h"

struct BoardPlayerInfo* board_mem_allocation(struct BoardPlayerInfo*)
{
    return new struct BoardPlayerInfo;
}

void free_board_mem(struct BoardPlayerInfo *board_player_info_ptr)
{
    delete board_player_info_ptr;
}

bool is_horizontal_win(std::array<std::array<std::string, SIZE_OF_ROW + 1>, SIZE_OF_ROW + 1> arr)
{
    unsigned int row = 0;

    for(row = 0 ; row < SIZE_OF_ROW ; row++)  
    {  
        if (arr[row][0] != EMPTY_SPACE &&
            arr[row][0] == arr[row][1] &&  
            arr[row][1] == arr[row][2])  
        {
            return true;
        }
    }  

    return false;
}

bool is_vertical_win(std::array<std::array<std::string, SIZE_OF_ROW + 1>, SIZE_OF_ROW + 1> arr)
{
    unsigned int column = 0;

    for(column = 0 ; column < SIZE_OF_ROW ; column++)  
    {  
        if (arr[0][column] != EMPTY_SPACE &&
            arr[0][column] == arr[1][column] &&  
            arr[1][column] == arr[2][column])  
        {
            return true;
        }
    }  

    return false;
}

bool is_left_diagonal_win(std::array<std::array<std::string, SIZE_OF_ROW + 1>, SIZE_OF_ROW + 1> arr)
{
    if (arr[0][0] != EMPTY_SPACE &&
        arr[0][0] == arr[1][1] &&  
        arr[1][1] == arr[2][2])  
    {
        return true;
    }

    return false;
}

bool is_right_diagonal_win(std::array<std::array<std::string, SIZE_OF_ROW + 1>, SIZE_OF_ROW + 1> arr)
{
    if (arr[0][2] != EMPTY_SPACE &&
        arr[0][2] == arr[1][1] &&  
        arr[1][1] == arr[2][0])  
    {
        return true;
    }  

    return false; 
}

bool is_game_over(std::array<std::string, MAX_SIZE_ARRAY_1D> arr)
{
    unsigned int counter = 0, i = 0, j = 0;
    std::array<std::array<std::string, SIZE_OF_ROW + 1>, SIZE_OF_ROW + 1> array_2D;

    // Converting 1D array to 2D array
    for(i = 0; i < SIZE_OF_ROW; i++)
    {
        for(j = 0; j < SIZE_OF_ROW; j++)
        {
            array_2D[i][j] = arr[counter];
            counter++;
        }
    }

    if (is_vertical_win(array_2D) || is_horizontal_win(array_2D) ||
        is_left_diagonal_win(array_2D) || is_right_diagonal_win(array_2D))
    {
        return true;
    }

    return false;
}

void print_line(void)
{
    print_validation("\n___|___|___\n");
}

void ending_line(void)
{
    print_validation("\n   |   |   \n");
}

void board_display(const std::array<std::string, MAX_SIZE_ARRAY_1D>& arr)
{
    unsigned int arr_index = 0, board_pos = 0;

    for(arr_index = 0, board_pos = 1; arr_index < SIZE_OF_ROW * 3; arr_index++, board_pos++)
    {
        if(board_pos == LAST_LINE_ELEMENT_POS)
        {
            print_validation("|");
            board_pos = 0;
        }
        if(board_pos == MIDDLE_ELEMENT_POS)
        {
            print_validation("|");
            print_validation(std::string(arr[arr_index]));
        }
        else
            print_validation(std::string(arr[arr_index]));

        // arr_index needs to not be printed the last time
        if((arr_index + 1) % 3 == 0 && arr_index < 7)
            print_line();
        
        else if(arr_index == (SIZE_OF_ROW * 3) - 1)
            ending_line();
    }

    print_validation("\n--------------------------\n\n");
}

void initial_dispay(void)
{
    std::array<std::string, MAX_SIZE_ARRAY_1D> initial_dispay = 
    {
        " 1 ", " 2 ", " 3 ",
        " 4 ", " 5 ", " 6 ",
        " 7 ", " 8 ", " 9 ",
    };

    board_display(initial_dispay);
}

void starting_board(void)
{
    unsigned int i = 0;

    for(i = 0; i < SIZE_OF_ROW * 3; i++)
    {
        board_player_info.plaing_board[i] = EMPTY_SPACE;
    }

    board_display(board_player_info.plaing_board);
}

void starting_game(void)
{   
    int current_turn = 1;
    unsigned int input_position;

    // The condition is SIZE_OF_ROW * 3 + 2 after the last input 
    // the game can be evaluated as a tie or if there`s a winner
    while(current_turn < SIZE_OF_ROW * 3 + 2) 
    {
        // There is not possibility to have a winner less than 5 turns
        if(current_turn > 5) 
        {
            if(is_game_over(board_player_info.plaing_board))
            {
                if(current_turn % 2 == 0)
                {
                    print_validation("PLAYER 1 WON!\n");
                    board_player_info.is_player_1_won = true;
                    break;
                }
                else
                {
                    print_validation("PLAYER 2 WON!\n");
                    board_player_info.is_player_2_won = true;
                    break;
                }    
            }
        }

        // If there`s no winner and no remaining turns evavuate the game as a tie
        if ((board_player_info.is_player_1_won == false) &&
            (board_player_info.is_player_2_won  == false) && 
            current_turn == (SIZE_OF_ROW * 3 + 1))
        {
            print_validation("IT'S A TIE\n");
            break;
        }

        print_validation("Enter position: ");
        std::cin >> input_position;
        print_validation("\n");

        if(input_position < 1 || input_position > 9)
        {
            print_validation("Invalid position!\n");
            continue;
        }
        
        if(board_player_info.plaing_board[input_position - 1] != EMPTY_SPACE)
        {
            print_validation("This position has already been taken!\n");  
            continue; 
        }

        if(current_turn % 2 == 0)
            board_player_info.plaing_board[input_position - 1] = " O ";
        else
            board_player_info.plaing_board[input_position - 1] = " X ";

        board_display(board_player_info.plaing_board);
        
        current_turn++;
    }
}

int main()
{
    board_mem_allocation(&board_player_info);
    initial_dispay();
    starting_board();
    starting_game();
    free_board_mem(&board_player_info);

    return 0;
}