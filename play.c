// This part is responsible for the playing process like the user enters the column he or she chose, and also integrates all the winning conditions.  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "play.h"
#include "chessboard.h"
#include "win.h"
/**
 * this function gets the column chosen by the two players
 * @board: this is the gameboard we use in the game
 * @rows: the number of the row of the gameboard
 * @columns: the number of the column of the gameboard
 * @round: it records the number of round which the game goes
 * @return: the number of the column players chosse during the game
*/
int getColumn(char **board, int rows, int columns, int * round){
	int columnChoose = 0;
	while(1){
         printf("Enter a column between 0 and %d to play in:", columns - 1);
     if (scanf(" %d", &columnChoose) == 1) {
        for(int i = 0; i < rows; ++i){
                if (columnChoose < 0 || columnChoose >= columns){
                    break;
		    }	
				if(board[i][columnChoose] == '*'){
                    *round += 1;
                    return columnChoose;
				}
			}
		}
		else{
			char absorb[100];
			scanf(" %s", absorb);
			
		}
	}
}

/**
 * This function helps us record the players choices and records them to the gameboard
 * @board: this is the gameboard we use in the game
 * @columnChoose: the column the user chooses
 * @rows: the number of the row of the gameboard
 * @columns: the number of the column of the gameboard
 * @round: it records the number of round which the game goes
*/
void playGame(char ** board,int columnChoose, int rows, int columns, int* round){
	for (int i = rows - 1 ; i >= 0; --i ) {
		if (board[i][columnChoose] == '*') {
			if (*round % 2 == 1) {
               board[i][columnChoose] = 'X';
			   break;
			}
            if (*round % 2 == 0 ) {
               board[i][columnChoose] = 'O';
			   break;
			}
		}
	}
    printBoard(board, rows, columns);
}

/**
 * This function helps integrate whole playing process, like the step of choosing column, the winning conditions and records of the users' choices 
 * @board: this is the gameboard we use in the game
 * @rows: the number of the row of the gameboard
 * @columns: the number of the column of the gameboard
 * @round: it records the number of round which the game goes
 * @win: the number of chess which should be connected to win the game
*/
void check_game_over(char ** board, int rows, int columns, int* round, int win){
    int columnchoose;
	bool over = game_is_over(board, rows, columns);
    while(!over){
        columnchoose = getColumn(board, rows, columns, round);
        playGame(board, columnchoose, rows, columns, round);
		winCase_announce(board, rows, columns, win, round);
		over = game_is_over(board, rows, columns);
    }
	printf("Tie game!\n");
	exit(0);
}