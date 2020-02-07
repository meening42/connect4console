#ifndef FOURINROW_H
#define FOURINROW_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define BOARD_WIDTH 7
#define BOARD_HEIGHT 6

class FourInRow
{
public:
    FourInRow();
    void showBoard();
    void insertCoinInRow(int row);
    void switchPlayerOnMove();
    void makeMove();
    char checkWinner();
    void initialize();
    char playerOnMove = char(178);

private:


    char board[BOARD_WIDTH][BOARD_HEIGHT];

};

#endif // FOURINROW_H
