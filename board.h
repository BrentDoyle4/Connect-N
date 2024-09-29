#ifndef BOARD_H
#define BOARD_H

    char** make_board(const int num_rows, const int num_cols, const char blank_space);
    void display_board(char** board, const int num_rows, const int num_cols);
    void clean_up_board(char*** board, const int num_rows);

#endif