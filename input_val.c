// This function helps us check if the user types the correct number of arguments to start the game. 
// It will also collect the important arguments discribed the dimension of the gameboard
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "input_val.h"

/**
 * This function helps us read the number of arguments the user enters
 * @argc: the number of arguments entered by the user
*/
void read_args(int argc){
   if (argc < 4) {
    printf("Not enough arguments entered\n");
	printf("Usage connectn.out num_rows num_columns\n");
    printf("number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
   }
   if (argc > 4) {
    printf("Too many arguments entered\n");
    printf("Usage connectn.out num_rows num_columns\n");
    printf("number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
    }
}
/**
 * This function helps us gather the dimension of the gameboard from the userr
 * @rows: the number of row of the gameboard entered by the user
 * @columns: the number of column of the gameboard entered by the user
 * @win: the number of the chess which should be connected to win the game
 * @argv: the user's input, which contains all the dimension used in building the gameboard
*/
void getInfo(int * rows, int * columns, int * win, char ** argv){
	sscanf(argv[1], "%d", rows);
    sscanf(argv[2], "%d", columns);
    sscanf(argv[3], "%d", win);
}