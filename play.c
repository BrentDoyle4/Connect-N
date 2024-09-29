#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "play.h"
#include "input_val.h"

/*
Ask the user which column they wish to play their piece in and get the column number
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@blank_space: the character that is in the blank spaces of the game board
@col: the column the user wished to place their piece in
returns: nothing
*/
void get_move(char** board, const int num_rows, const int num_columns, const char blank_space, int* col) {
    char temp[5];
    sprintf(temp, "%d", (num_columns-1));
    char prompt[100] = "Enter a column between 0 and ";
    strcat(prompt, temp);
    strcat(prompt, " to play in: ");
    do {
        *col = getValidIntInRange(0, num_columns, prompt);
    }while(!is_valid_move(board, num_rows, num_columns, *col, blank_space));
}

/*
Checks if the move the user wished to do is a valid move
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@num_cols: the number of columns in the game board
@col: the column the user wished to place their piece in
@blank_space: the character that is in the blank spaces of the game board
@returns: true if the move the user wished to do is valid and false otherwise
*/
bool is_valid_move(char** board, const int num_rows, const int num_cols, const int col, const char blank_space) {
    if(!inbetween(col, 0, num_cols-1)){
        return false;
    }
    else {
        for(int i = 0; i < num_rows; ++i){
            if (board[i][col] == blank_space){
                return true;
            }
        return false;
        }
    }
    return true;
}

/*
Puts the player's piece in the lowest blank space in the column they wish to play in
@board: a two-dimensional array containing a game board
@num_rows: the number of rows in the game board
@col_played: the column the user wished to place their piece in
@piece_player: the players assigned piece
@blank_space: the character that is in the blank spaces of the game board
@returns: nothing
*/
void make_move(char** board, const int num_rows, const int col_played, const char piece_played, const char blank_space) {
    for(int i = num_rows; i > 0; --i){
        if (board[i-1][col_played] == blank_space){
            board[i-1][col_played] = piece_played;
            return;
        }
    }
}

/*
Changes which players turn it is
@player_turn: which players turn it currently is
@returns: 2 if it was player 1 turn and 1 if it was player 2 turn
*/
int change_turn(const int player_turn) {
    if(player_turn == 1){
        return 2;
    } else{
        return 1;
    }
}