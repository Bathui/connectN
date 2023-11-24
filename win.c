/*The following program checks if the chessboard has consecutive same pieces 
that need to win in any rows, any columns, any diagonals sloping to the right
or left, and announce the winer or tie game. And free all allocated memory when
the game comes to end*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "win.h"

/**
 * Free all alocated memory when the game comes to end
 * @board: a pointer point to the memory of the 2D board allocated, in order to dereference
 * @rows: the rows of the chessboard
*/
void cleanUp(char *** board, int rows){
    for (int i = 0; i < rows; i++) {
        free((*board)[i]);
    }
    free(*board);
    *board = NULL;
}

/**
 * Check if the chessboard has consecutive same pieces that need to win in any rows
 * @board: the 2D chessboard that the user created to play the game
 * @rows: the number of rows in the chessboard
 * @columns: the number of columns in the chessboard
 * @win: the number of consecutive same pieces needed to win the game
 * @return: return true if has a win, otherwise no winner for this case
*/
bool all_same_horizontal(int rows, int columns, int win, char** board){
    //check if win > columns, if so, then tie game for this case(unfinished)
    if (win > columns){
        return false;
    }
    else{
        for (int i = rows - 1; i >= 0; --i){
            for (int j = 0; j <= columns - win; ++j) {
                //Check if the current win-size pieces in the row is the same
                bool consecutive_pieces = true;
                for (int k = 1; k < win; ++k){
                    if (board[i][j + k] != board[i][j] || board[i][j] == '*') {
                        consecutive_pieces = false;
                        break;
                    }
                }
                if (consecutive_pieces){
                    return true;
                }
            }
        }
        return false; //if not same 
    } 
}

/**
 * Check if the chessboard has consecutive same pieces that need to win in any columns
 * @board: the 2D chessboard that the user created to play the game
 * @rows: the number of rows in the chessboard
 * @columns: the number of columns in the chessboard
 * @win: the number of consecutive same pieces needed to win the game
 * @return: return true if has a win, otherwise no winner for this case
*/
bool all_same_vertical(int rows, int columns, int win, char** board){
    //check if win > rows, if so, then tie game for this case(unfinished)
    if (win > rows){
        return false;
    }
    else{
        for (int i = rows - 1; i >= win - 1; --i){
            for (int j = 0; j < columns; ++j) {
                //Check if the current win-size pieces in the column is the same
                bool consecutive_pieces = true;
                for (int k = 1; k < win; ++k){
                    if (board[i - k][j] != board[i][j] || board[i][j] == '*') {
                        consecutive_pieces = false;
                        break;
                    }
                }
                if (consecutive_pieces){
                    return true;
                }
            }
        }
        return false; //if not same 
    }
}


/**
 *  Check for a win on the main diagonal that looks like this
        X
          X
            X
 * @board: the 2D chessboard that the user created to play the game
 * @rows: the number of rows in the chessboard
 * @columns: the number of columns in the chessboard
 * @win: the number of consecutive same pieces needed to win the game
 * @return: return true if has a win, otherwise no winner for this case
*/
bool all_same_right_diagonal(int rows, int columns, int win, char** board){
    //check if win > the smaller value of rows and columns, if so, then tie game for this case(unfinished)
    if (win > rows || win > columns){
        return false;
    }
    else{
        for (int i = 0; i <= rows - win; ++i){
            for (int j = 0; j <= columns - win; ++j){
                //Check if the current win-size pieces in the left diagonal is the same
                bool consecutive_pieces = true;
                for (int k = 1; k < win; ++k){
                    if (board[i + k][j + k] != board[i][j] || board[i][j] == '*') {
                        consecutive_pieces = false;
                        break;
                    }
                }
                if (consecutive_pieces){
                    return true;
                }
            }
        }
        return false; //if not same 
    }
}

/**
 *  Check for a win on the main diagonal that looks like this
            X
          X
        X
 * @board: the 2D chessboard that the user created to play the game
 * @rows: the number of rows in the chessboard
 * @columns: the number of columns in the chessboard
 * @win: the number of consecutive same pieces needed to win the game
 * @return: return true if has a win, otherwise no winner for this case
*/
bool all_same_left_diagonal(int rows, int columns, int win, char** board){
    //check if win > the smaller value of rows and columns, if so, then tie game for this case(unfinished)
    if (win > rows || win > columns){
        return false;
    }
    else{
        for (int i = rows - 1; i >= win - 1; --i){
            for (int j = 0; j <= columns - win; ++j) {
                //Check if the current win-size pieces in the left diagonal is the same
                bool consecutive_pieces = true;
                for (int k = 1; k < win; ++k){
                    if (board[i - k][j + k] != board[i][j] || board[i][j] == '*') {
                        consecutive_pieces = false;
                        break;
                    }
                }
                if (consecutive_pieces){
                    return true;
                }
            }
        }
        return false; //if not same 
    }
}

/**
 * Check if all chessborad entries are filled up
 * @board: the 2D chessboard that the user created to play the game
 * @rows: the number of rows in the chessboard
 * @columns: the number of columns in the chessboard
 * @return: return true if the game is over, otherwise not over
*/
bool game_is_over(char** board, int rows, int columns){
	for(int i = 0 ; i < rows; i++){
    	for (int j = 0; j< columns; j++) {
        	if (board[i][j] == '*'){
				return false;
			}
		}
	}
    cleanUp(&board, rows);
	return true;
}

/**
 * @board: the 2D chessboard that the user created to play the game
 * @rows: the number of rows in the chessboard
 * @columns: the number of columns in the chessboard
 * @win: the number of consecutive same pieces needed to win the game
 * @round: count the round of player 1 or player 2
*/
void winCase_announce(char** board, int rows, int columns, int win, int* round){
    //Check whether there is a consecutive win-size ‘X’ or 'O' in any case of 4 starting at arbitrary location within the chessboard
    bool win_horizangtal = all_same_horizontal(rows, columns, win, board);
    bool win_vertical = all_same_vertical(rows, columns, win, board);
    bool win_right_diagonal = all_same_right_diagonal( rows, columns, win, board);
    bool win_left_diagonal = all_same_left_diagonal(rows, columns, win, board);

    if (win_horizangtal || win_vertical || win_right_diagonal || win_left_diagonal){
        //check who won
        if (*round % 2 == 1){
            printf("Player 1 Won!\n");
            cleanUp(&board, rows);
            exit(0);
        }
        else{
            printf("Player 2 Won!\n");
            cleanUp(&board, rows);
            exit(0);
        }
    }
}

