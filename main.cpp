#include <stdio.h>


int kMovesX[] = {-2, 2, -1, 1, -2, 2, -1, 1};
int kMovesY[] = {1, 1, 2, 2, -1, -1, -2, -2};

using namespace std;

void printBoard(int **pos){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            printf("%c ", pos[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void genBishop(int **pos, int row, int col){
    int x = row + 1, y = col + 1;
    while(x <= 7 && y <= 7){
        // printf("%d %d\n", pos[x][y] - 'a', pos[row][col] - 'a');
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
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
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
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
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
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
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
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

void genKnight(int **pos, int row, int col){
    int x,y;
    for(int i = 0; i < 8; ++i){
        x = row + kMovesX[i];
        y = col + kMovesY[i];
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) continue; 
        pos[x][y] = '*';
    }
    printBoard(pos);
}

void genRook(int **pos, int row, int col){
    int x = row + 1, y = col;
    while(x <= 7 && y <= 7){
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        ++x;
    }

    x = row - 1;
    while(x >= 0 && y <= 7){
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        --x;
    }

    x = row, y = col + 1;
    while(x <= 7 && y >= 0){
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        ++y;
    }

    y = col - 1;
    while(x >= 0 && y >= 0){
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        --y;
    }

    printBoard(pos);
}

void genQueen(char ** pos, int x, int y){
    int x = row + 1, y = col + 1;
    while(x <= 7 && y <= 7){
        // printf("%d %d\n", pos[x][y] - 'a', pos[row][col] - 'a');
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
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
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
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
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
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
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        --x; --y;
    }
    x = row + 1, y = col;
    while(x <= 7 && y <= 7){
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        ++x;
    }

    x = row - 1;
    while(x >= 0 && y <= 7){
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        --x;
    }

    x = row, y = col + 1;
    while(x <= 7 && y >= 0){
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        ++y;
    }

    y = col - 1;
    while(x >= 0 && y >= 0){
        if(pos[x][y] != '~' && (pos[x][y] - 'a')*(pos[row][col] - 'a') > 0) break;
        if((pos[x][y] - 'a')*(pos[row][col] - 'a') < 0 && pos[x][y] != '~'){ 
            pos[x][y] = '*';
            break;
        }else{
            pos[x][y] = '*';
        }
        --y;
    }
}

int main(void){
    int** board = new int*[8];
    for (int i = 0; i < 8; ++i) {
        board[i] = new int[8];
        for(int j = 0; j < 8.; ++j){
            board[i][j] = '~';
        }
    }
    int x = 3, y = 3;
    board[x][y] = 'R';
    board[x+2][y] = 'k';
    printBoard(board);
    genRook(board, x, y);



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