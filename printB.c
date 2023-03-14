#include <stdio.h>
// Pawn 1 -1
// Knight 2 -2
// Bishop 3 -3 
// Rook 4 -4
// Queen 5 -5
// King 6 -6

//function that pints the board in a nice way
void printBoard(char **pos){
    int i, j;
    for(i = 0; i < 8; ++i){
        printf("  +---+---+---+---+---+---+---+---+\n");
        printf("%d |", 8 - i);
        for(j = 0; j < 8; ++j){
            if(pos[i][j] == 0){
                printf("   |");
            }else{
                printf(" ");
                switch(pos[i][j]){
                    case 1:
                        printf("P");
                        break;
                    case 2:  
                        printf("N");
                        break;
                    case 3:
                        printf("B");
                        break;
                    case 4:
                        printf("R");
                        break;
                    case 5:
                        printf("Q");
                        break;
                    case 6:
                        printf("K");
                        break;
                    case -1:
                        printf("p");
                        break;
                    case -2:
                        printf("n");
                        break;
                    case -3:
                        printf("b");
                        break;
                    case -4:
                        printf("r");
                        break;
                    case -5:
                        printf("q");
                        break;
                    case -6:
                        printf("k");
                        break;
                    default:
                        printf("*");
                        break;
                }
                printf(" |");
            }
        }
        printf("\n");
    }
    printf("  +---+---+---+---+---+---+---+---+\n");
    printf("    a   b   c   d   e   f   g   h  \n");
}
