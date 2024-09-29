#ifndef WIN_H
#define WIN_H

    bool is_game_over(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row);
    bool win(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row);
    bool horz_win(char** board, const int num_rows, const int num_cols, const int blank_space, const int num_pieces_in_row);
    bool vert_win(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row);
    bool diag_win(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row);
    bool left_diag_win(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row);
    bool right_diag_win(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row);
    bool tie(char** board, const int num_rows, const int num_cols, const int blank_space, const int num_pieces_in_row);
    bool is_board_full(char** board, const int num_rows, const int num_cols, const int blank_space);
    void declare_winner_or_tie(const int player_turn, char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row);
    bool all_same(char* array, const int len, const int blank_space, const int num_pieces_in_row);

#endif