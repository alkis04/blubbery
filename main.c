#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printB.h"
#include "moves.h"

int main(void){ int i,j;
    // int *board_64 = malloc(64 * sizeof(int));
    // int **board = malloc(8 * sizeof(int*));
    // for (i = 0; i < 8; ++i){
    //     board[i] = board_64 + i * 8;
    // }
    // memset(board_64, '~', 64 * sizeof(int));
    int **board = malloc(8 * sizeof(int*));
    for(i = 0; i < 8; ++i){
        board[i] = malloc(8 * sizeof(int));
    }
    for(i = 0; i < 8; ++i){
        for(j = 0; j < 8; ++j){
            board[i][j] = '~';
        }
    }
    int x = 1, y = 3;
    board[x][y] = 'k';

    // board[x - 1][y - 1] = 'n';
    //board[x-1][y-1] = 'P';
    printBoard(board);
    genKing(board, x, y);

    // free(board_64); free(board);
    return 0;
}
/*
Space ~
King K 
Pawn P
Knight N 
Bishop B 
Rook R
Queen Q
*/