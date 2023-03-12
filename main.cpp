#include <stdio.h>


int kMovesX[] = {-2, 2, -1, 1, -2, 2, -1, 1};
int kMovesY[] = {1, 1, 2, 2, -1, -1, -2, -2};

using namespace std;

void printBoard(char **pos){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            printf("%c ", pos[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void genBishop(char **pos, int row, int col){
    int add = 1;
    int x = row + 1, y = col + 1;
    while(x <= 7 && y <= 7){
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        ++x, ++y;
    }

    x = row - 1, y = col + 1;
    while(x >= 0 && y <= 7){
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        --x, ++y;
    }

    x = row + 1, y = col - 1;
    while(x <= 7 && y >= 0){
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        ++x, --y;
    }

    x = row - 1, y = col - 1;
    while(x >= 0 && y >= 0){
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        --x; --y;
    }

    printBoard(pos);
}

void genKnight(char **pos, int row, int col){
    int x,y;
    for(int i = 0; i < 8; ++i){
        x = row + kMovesX[i];
        y = col + kMovesY[i];
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) continue; 
        pos[x][y] = '*';
    }
    printBoard(pos);
}

int main(void){
    char** board = new char*[8];
    for (int i = 0; i < 8; ++i) {
        board[i] = new char[8];
        for(int j = 0; j < 8.; ++j){
            board[i][j] = '~';
        }
    }
    int x = 4, y = 3;
    board[x][y] = 'K';
    board[x-2][y+1] = 'B';
    genKnight(board, x, y);
    // genBishop(board, x, y);


    for (int i = 0; i < 8; ++i) {
        delete[] board[i];
    }
    delete[] board;
    return 0;
}
/*
Space ~
King K 
Pawn P
Knight K 
Bishop B 
Rook R
Queen Q
*/