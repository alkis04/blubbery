#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printB.h"
#include "moves.h"
#include "fen.h"

int main(void){ //int i;
    /*          Allocating board's memory       */
    // char **board = malloc(8 * sizeof(char*)); if(!board) exit(1);
    // board[0] = calloc(64, 1); if(!board[0]) exit(1);
    // for (i = 1; i < 8; ++i) board[i] = board[0] + i * 8;
    /*          Creating starting Position*/
    char *starpos = malloc(64); if(!starpos) exit(1);
    strcpy(starpos, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    char **board = fen_to_board(starpos); // fen_to_board allocates memory for board the same way as above

    printBoard(board);

    /*          Testing                    */
    // char *fen = board_to_fen(board);
    // printf("FEN: %s\n", fen);
    // char **new_board = fen_to_board(fen);
    // printBoard(new_board);
    // free(new_board[0]); free(new_board);

    // memset(fen, 0, 100);
    // fen = strcpy(fen, "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2");
    // new_board = fen_to_board(fen);
    // printBoard(new_board);
    // free(new_board[0]); free(new_board);
    // free(fen); 
    /*          OK            */
    free(board[0]); free(board);
    free(starpos);
    return 0;
}
/*
Space 0
Pawn 1 -1
Knight 2 -2
Bishop 3 -3 
Rook 4 -4
Queen 5 -5
King 6 -6
*/