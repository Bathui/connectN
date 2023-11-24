#ifndef WIN_H
    #define WIN_H
    #include <stdbool.h>
    void cleanUp(char *** board, int rows);
    bool all_same_horizontal(int rows, int columns, int win, char** board);
    bool all_same_vertical(int rows, int columns, int win, char** board);
    bool all_same_right_diagonal(int rows, int columns, int win, char** board);
    bool all_same_left_diagonal(int rows, int columns, int win, char** board);
    bool game_is_over(char** board, int rows, int columns);
    void winCase_announce(char ** board, int rows, int columns, int win, int* round);
#endif