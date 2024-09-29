#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "play.h"
#include "win.h"
#include "board.h"
#include "input_val.h"

/*
Connect-n game (kinda like Connect-4) with the size of the board and the number of pieces in a row needed to win are user parameters.
*/
int main (int argc, char *argv[]){
    if (argc < 4) {
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    else if (argc > 4) {
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    int num_rows;
    sscanf(argv[1], "%d", &num_rows);
    if (num_rows <= 0) {
        printf("Invalid value entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    int num_columns;
    sscanf(argv[2], "%d", &num_columns);
    if (num_columns <= 0) {
        printf("Invalid value entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    int number_of_pieces_in_a_row_needed_to_win;
    sscanf(argv[3], "%d", &number_of_pieces_in_a_row_needed_to_win);
    if (number_of_pieces_in_a_row_needed_to_win <= 0) {
        printf("Invalid value entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }

    char blank_space = '*';
    int col_played;
    int player_turn = 1;
    const char pieces[] = "XO";
    char** board = make_board(num_rows, num_columns, blank_space);


    while (!is_game_over(board, num_rows, num_columns, blank_space, number_of_pieces_in_a_row_needed_to_win)) {
        display_board(board, num_rows, num_columns);
        get_move(board, num_rows, num_columns, blank_space, &col_played);
        make_move(board, num_rows, col_played, pieces[player_turn-1], blank_space);
        player_turn = change_turn(player_turn);
    }

    display_board(board, num_rows, num_columns);
    declare_winner_or_tie(player_turn, board, num_rows, num_columns, blank_space, number_of_pieces_in_a_row_needed_to_win);
    clean_up_board(&board, num_rows);

    return 0;
}