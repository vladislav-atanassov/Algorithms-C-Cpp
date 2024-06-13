#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#define MAX_SIZE_ARRAY_1D 10
#define SIZE_OF_ROW 3

#define LAST_LINE_ELEMENT_POS 3
#define MIDDLE_ELEMENT_POS 2
#define EMPTY_SPACE "   "

//#define TEST
#ifdef TEST
void print_validation(std::string message){}
#else
void print_validation(std::string message)
{
    std::cout << message;
}
#endif

struct BoardPlayerInfo
{
    std::array<std::string, MAX_SIZE_ARRAY_1D> plaing_board;
    bool is_player_1_won = false;
    bool is_player_2_won = false;
} board_player_info;

enum TestCounter
{
    FIRST_TEST = 1,
    SECOND_TEST
};

enum GameResult
{
    PLAYER_1_WON = 1,
    PLAYER_2_WON,
    TIE
};

struct BoardPlayerInfo* board_mem_allocation(struct BoardPlayerInfo*);

void free_board_mem(struct BoardPlayerInfo *board_player_info_ptr);

void initial_dispay(void);

void board_display(const std::array<std::string, MAX_SIZE_ARRAY_1D>& arr);

void print_line(void);

void ending_line(void);

void starting_board(void);

void starting_game(void);

bool is_game_over(std::array<std::string, MAX_SIZE_ARRAY_1D> arr);

bool is_horizontal_win(std::array<std::array<std::string, SIZE_OF_ROW + 1>, SIZE_OF_ROW + 1> arr);

bool is_vertical_win(std::array<std::array<std::string, SIZE_OF_ROW + 1>, SIZE_OF_ROW + 1> arr);

bool is_left_diagonal_win(std::array<std::array<std::string, SIZE_OF_ROW + 1>, SIZE_OF_ROW + 1> arr);

bool is_right_diagonal_win(std::array<std::array<std::string, SIZE_OF_ROW + 1>, SIZE_OF_ROW + 1> arr);

bool test_cmd_line_input(struct BoardPlayerInfo *board_player_info, const char file[], int desired_result, int number_test);

#endif