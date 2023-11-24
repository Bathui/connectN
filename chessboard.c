// This part helps us generate the gameboard and print the gameboard to the user
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "chessboard.h"
/**
 * The program helps us generate the gameboard
 * @rows: the number of rows of a gameboard 
 * @columns: the number of columns of a gameboard
 * @win: the number of chess that should be connected to win the game
 * @return: a 2D array which contains the gameboard
*/
char** genBoard(int rows, int columns, int win){
   char** board = (char**)malloc(rows * sizeof(char*));
   for (int i = 0 ; i < rows; ++i) {
    board[i] = (char*)malloc(columns * sizeof(char));
    }
    for (int i = 0; i< rows; ++i) {
      for (int j = 0; j< columns; j++) {
        board[i][j] = '*';
      }
    }
    return board;
}
/**
 * The program helps us print the gameboard
 * @board: the gameboard we use in the game
 * @rows: the number of rows of a gameboard 
 * @columns: the number of columns of a gameboard
*/
void printBoard (char** board, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        printf("%d ", rows - 1 - i);
        for (int j = 0; j < columns; ++j) {
        printf(" %c", board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (int k = 0; k < columns; k++) {
        printf(" %d", k);
    }
    printf("\n");
}