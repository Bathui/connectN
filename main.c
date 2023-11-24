// This part integrates overall files used in this project, and present the whole gaming process.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input_val.h"
#include "chessboard.h"
#include "play.h"
#include "win.h"
/**
 * The fucntion integrates the whole gaming process and helps store the important information like the dimension of the chessboard and chessboard itself.
 * @argc: the number of arguments entered by the user
 * @argv: the user's input, which contains all the dimension used in building the gameboard
*/
int main(int argc, char** argv){
    //Check valid input
	read_args(argc);
    int rows, columns, win;
	int round = 0;
	getInfo(&rows, &columns, &win, argv);
    //Generate chessboard 
	char ** board = genBoard(rows, columns, win);
	printBoard(board, rows, columns);
    //Begin to play until someone won or tie game, and announce the result
	check_game_over(board, rows, columns, &round, win);
    cleanUp(&board, rows);
	return 0;
}