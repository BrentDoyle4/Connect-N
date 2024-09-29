#include <stdlib.h>
#include <stdio.h>
#include "board.h"

/*
Makes a two-dimensional array with each row in each column filled with a certain blank space given by the user
@num_rows: the number of rows in the two-dimensional array
@num_cols: the number of columns in the two-dimensional array
@blank_space: a character given by user used to fill all the blank spaces in the array
@returns: a two-dimensional array filled with the blank space characters given by user
*/
char** make_board(const int num_rows, const int num_cols, const char blank_space){
    char** board = (char**) malloc(num_rows * sizeof(char*));
    for(int row = 0; row < num_rows; ++row){
        board[row] = (char*) malloc(num_cols * sizeof(char));
        for (int col = 0; col < num_cols; ++col) {
            board[row][col] = blank_space;
        }
    }
    return board;
}

/*
Displays a two-dimensional array given by user
@board: a two-dimensional array
@num_rows: the number of rows in the two-dimensional array
@num_cols: the number of columns in the two-dimensional array
@returns: nothing
*/
void display_board(char** board, const int num_rows, const int num_cols) {
    int row_num = num_rows -1;
    for (int row = 0; row < num_rows; ++row) {
        printf("%d ", row_num);
        row_num--;
        for (int col = 0; col < num_cols; ++col) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("  ");
    for (int col = 0; col < num_cols; ++col){
        printf("%d ", col);
    }
    printf("\n");
}

/*
Frees a two-dimensional array given by the user
@board: a two-dimensional array
@num_rows: the number of rows in the two-dimensional array
@returns: nothing
*/
void clean_up_board(char*** board, const int num_rows) {
    for(int row = 0; row < num_rows; ++row){
        free((*board)[row]);
    }
    free(*board);
    *board = NULL;
}