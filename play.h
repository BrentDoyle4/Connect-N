#ifndef PLAY_H
#define PLAY_H

    void get_move(char** board, const int num_rows, const int num_columns, const char blank_space, int* col);
    bool is_valid_move(char** board, const int num_rows, const int num_cols, const int col, const char blank_space);
    void make_move(char** board, const int num_rows, const int col_played, const char piece_played, const char blank_space);
    int change_turn(const int player_turn);

#endif