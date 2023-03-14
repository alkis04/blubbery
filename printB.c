#include <stdio.h>

void printBoard(int **pos){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            printf("%c ", pos[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}