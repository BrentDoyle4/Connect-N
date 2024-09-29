#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "win.h"

/*
Checks if the game is over either through a win or through a tie
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@blank_space: the character that is in the blank spaces of the game board
@num_pieces_in_row: the number of pieces in a row needed to win the game
@returns: true if a player has won or there has been a tie, and false otherwise
*/
bool is_game_over(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row) {
  return win(board, num_rows, num_cols, blank_space, num_pieces_in_row) || 
        tie(board, num_rows, num_cols, blank_space, num_pieces_in_row);
}

/*
Checks if a player has won either by getting a certain number of pieces in a row horizontally, vertically, or diagonally
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@blank_space: the character that is in the blank spaces of the game board
@num_pieces_in_row: the number of pieces in a row needed to win the game
@returns: true if a player has won or false otherwise
*/
bool win(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row) {
  return horz_win(board, num_rows, num_cols, blank_space, num_pieces_in_row) || 
        vert_win(board, num_rows, num_cols, blank_space, num_pieces_in_row) || 
        diag_win(board, num_rows, num_cols, blank_space, num_pieces_in_row);
}

/*
Checks if a player has won by getting a certain number of pieces in a row horizontally
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@blank_space: the character that is in the blank spaces of the game board
@num_pieces_in_row: the number of pieces in a row needed to win the game
@returns true if a player won horizontally or false otherwise
*/
bool horz_win(char** board, const int num_rows, const int num_cols, const int blank_space, const int num_pieces_in_row) {
    for(int row = 0; row < num_rows; ++row){
        if(all_same(board[row], num_cols, blank_space, num_pieces_in_row)){
            return true;
        }
    }
    return false;
}

/*
Checks if a player has won by getting a certain number of pieces in a row vertically
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@blank_space: the character that is in the blank spaces of the game board
@num_pieces_in_row: the number of pieces in a row needed to win the game
@returns: true if a player won vertically or false otherwise
*/
bool vert_win(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row) {
    char* col_to_check = (char*)malloc(num_rows* sizeof(char));
    for(int col = 0; col < num_cols; ++col){
        for(int row = 0; row < num_rows; ++row){
            col_to_check[row] = board[row][col];
        }
        if(all_same(col_to_check, num_rows, blank_space, num_pieces_in_row)){
            return true;
        }
    }
    free(col_to_check);
    return false;
}

/*
Checks if a player has won by getting a certain number of pieces in a row left or right diagonally 
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@blank_space: the character that is in the blank spaces of the game board
@num_pieces_in_row: the number of pieces in a row needed to win the game
@returns: true if a player won diagonally or false otherwise
*/
bool diag_win(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row) {
    if ((num_pieces_in_row <= num_cols) && (num_pieces_in_row <= num_rows)) {
        return left_diag_win(board, num_rows, num_cols, blank_space, num_pieces_in_row) || 
            right_diag_win(board, num_rows, num_cols, blank_space, num_pieces_in_row);
    }
    else{
        return false;
    }
}

/*
Checks if a player has won by getting a certain number of pieces in a row left diagonally 
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@blank_space: the character that is in the blank spaces of the game board
@num_pieces_in_row: the number of pieces in a row needed to win the game
@returns: true if a player won left diagonally or false otherwise
*/
bool left_diag_win(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row) {
    int small_dim = 0;
    if (num_cols < num_rows) {
        small_dim = num_cols;
    }
    else {
        small_dim = num_rows;
    }

    for (int i = 0; i <= num_rows - num_pieces_in_row; ++i){
        char* diag = (char*)malloc(small_dim * sizeof(char));
        for(int pos = 0; pos < small_dim - i; ++pos){
            diag[pos] = board[pos + i][pos];
        }
        bool did_win = all_same(diag, small_dim, blank_space, num_pieces_in_row);
        free(diag);
        if (did_win == true){
            return true;
        }
    }

    for (int i = 0; i <= num_cols - num_pieces_in_row; ++i){
        char* diag = (char*)malloc(small_dim * sizeof(char));
        for(int pos = 0; pos < small_dim; ++pos){
            diag[pos] = board[pos][pos + i];
        }
        bool did_win = all_same(diag, small_dim, blank_space, num_pieces_in_row);
        free(diag);
        if (did_win == true){
            return true;
        }
    }

    return false;
}

/*
Checks if a player has won by getting a certain number of pieces in a row right diagonally 
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@blank_space: the character that is in the blank spaces of the game board
@num_pieces_in_row: the number of pieces in a row needed to win the game
@returns: true if a player won right diagonally or false otherwise
*/
bool right_diag_win(char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row) {
    int small_dim = 0;
    if (num_cols < num_rows) {
        small_dim = num_cols;
    }
    else {
        small_dim = num_rows;
    }

    for (int i = 0; i <= num_rows - num_pieces_in_row; ++i){
        char* diag = (char*)malloc(small_dim * sizeof(char));
        for(int pos = 0; pos < small_dim - i; ++pos){
            diag[pos] = board[num_rows - pos - 1 - i][pos];
        }
        bool did_win = all_same(diag, small_dim, blank_space, num_pieces_in_row);
        free(diag);
        if (did_win == true){
            return true;
        }
    }

    for (int i = 0; i <= num_cols - num_pieces_in_row; ++i){
        char* diag = (char*)malloc(small_dim * sizeof(char));
        for(int pos = 0; pos < small_dim; ++pos){
            diag[pos] = board[num_rows - pos - 1][pos + i];
        }
        bool did_win = all_same(diag, small_dim, blank_space, num_pieces_in_row);
        free(diag);
        if (did_win == true){
            return true;
        }
    }
    
    return false;
}

/*
Checks if there is a tie by checking if a player has not won and the board is full
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@blank_space: the character that is in the blank spaces of the game board
@num_pieces_in_row: the number of pieces in a row needed to win the game
@returns: true if there is a tie or false otherwise
*/
bool tie(char** board, const int num_rows, const int num_cols, const int blank_space, const int num_pieces_in_row) {
    return !win(board, num_rows, num_cols, blank_space, num_pieces_in_row) &&
            is_board_full(board, num_rows, num_cols, blank_space);
}

/*
Checks if the board is full by checking if each space does not have the character used for the blank space
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@blank_space: the character that is in the blank spaces of the game board
@returns: true if the board is full or false otherwise
*/
bool is_board_full(char** board, const int num_rows, const int num_cols, const int blank_space) {
    for(int row = 0; row < num_rows; ++row){
        for(int col = 0; col < num_cols; ++col){
            if(board[row][col] == blank_space){
                return false;
            }
        }
    }
    return true;
}

/*
If a player has won prints the player that won, if there is a tie prints tie game
@player_turn: which players turn it currently is
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@blank_space: the character that is in the blank spaces of the game board
@num_pieces_in_row: the number of pieces in a row needed to win the game
@returns: nothing
*/
void declare_winner_or_tie(const int player_turn, char** board, const int num_rows, const int num_cols, const char blank_space, const int num_pieces_in_row) {
    if(win(board, num_rows, num_cols, blank_space, num_pieces_in_row)){
        if(player_turn == 1){
            printf("Player 2 Won!\n");
        }else{
            printf("Player 1 Won!\n");
        }
    }else{
        printf("Tie game!\n");
    }
}

/*
Checks for a certain number of pieces in a row are the same
@array: a array that is given to check
@len: the length of the array
@blank_space: the character that is in the blank spaces of the game board
@num_pieces_in_row: the number of pieces in a row needed to win the game
@returns: true if a certain number of pieces in a row are the same and false otherwise
*/
bool all_same(char* array, const int len, const int blank_space, const int num_pieces_in_row) {
    int temp = 0;
    for(int i = 0; i < len; ++i){
        if (array[i] != blank_space && array[i] == array[i+1]) {
            int j = i;
            while(array[j] == array[j+1]) {
                temp += 1;
                j++;
            }
            if(temp == num_pieces_in_row - 1) {
                return true;
            }
            else{
                temp = 0;
            }
            j = 0;
        }
    }
return false;
}