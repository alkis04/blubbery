#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printB.h"

char *board_to_fen(char **board){
    char *fen = malloc(100);
    char *fen_start = fen;
    int i, j, k, l;
    for(i = 0; i < 8; ++i){
        for(j = 0; j < 8; ++j){
            if(board[i][j] == 0){
                for(k = j; k < 8; ++k){
                    if(board[i][k] != 0){
                        break;
                    }
                }
                l = k - j;
                *fen = l + '0';
                ++fen;
                j = k;
            }
            if(j == 8){
                continue;
            }
            switch(board[i][j]){
                case 1:
                    *fen = 'P';
                    break;
                case 2:
                    *fen = 'N';
                    break;
                case 3:
                    *fen = 'B';
                    break;
                case 4:
                    *fen = 'R';
                    break;
                case 5:
                    *fen = 'Q';
                    break;
                case 6:
                    *fen = 'K';
                    break;
                case -1:
                    *fen = 'p';
                    break;
                case -2:
                    *fen = 'n';
                    break;
                case -3:
                    *fen = 'b';
                    break;
                case -4:
                    *fen = 'r';
                    break;
                case -5:
                    *fen = 'q';
                    break;
                case -6:
                    *fen = 'k';
                    break;
            }
            ++fen;
        }
        if(i != 7){
            *fen = '/';
            ++fen;
        }
    }
    *fen = ' ';
    ++fen;
    *fen = 'w';
    ++fen;
    *fen = ' ';
    ++fen;
    *fen = 'K';
    ++fen;
    *fen = 'Q';
    ++fen;
    *fen = 'k';
    ++fen;
    *fen = 'q';
    ++fen;
    *fen = ' ';
    ++fen;
    *fen = '-';
    ++fen;
    *fen = ' ';
    ++fen;
    *fen = '0';
    ++fen;
    *fen = ' ';
    ++fen;
    *fen = '1';
    ++fen;
    *fen = '\0';
    return fen_start;
}

char **fen_to_board(char *fen){
    int i, j;
    char **board = malloc(8 * sizeof(char*)); if(!board) exit(1);
    board[0] = calloc(64, 1); if(!board[0]) exit(1);
    for (i = 1; i < 8; ++i) board[i] = board[0] + i * 8;

    i = 0;
    j = 0;
    while(*fen != ' '){
        if(*fen == '/'){
            ++i;
            j = 0;
        }else if(*fen >= '1' && *fen <= '8'){
            j += *fen - '0';
        }else{
            switch(*fen){
                case 'P':
                    board[i][j] = 1;
                    break;
                case 'N':
                    board[i][j] = 2;
                    break;
                case 'B':
                    board[i][j] = 3;
                    break;
                case 'R':
                    board[i][j] = 4;
                    break;
                case 'Q':
                    board[i][j] = 5;
                    break;
                case 'K':
                    board[i][j] = 6;
                    break;
                case 'p':
                    board[i][j] = -1;
                    break;
                case 'n':
                    board[i][j] = -2;
                    break;
                case 'b':
                    board[i][j] = -3;
                    break;
                case 'r':
                    board[i][j] = -4;
                    break;
                case 'q':
                    board[i][j] = -5;
                    break;
                case 'k':
                    board[i][j] = -6;
                    break;
            }
            ++j;
        }
        ++fen;
    }
    return board;
}