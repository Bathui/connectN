#ifndef PLAY_H
    #define PLAY_H
    int getColumn(char ** board, int rows, int columns, int * round);
    void playGame(char ** board,int columnChoose, int rows, int columns, int* round);
    void check_game_over(char ** board, int rows, int columns, int* round, int win);
#endif