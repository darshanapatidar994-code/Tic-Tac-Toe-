#include <stdio.h>

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

void showBoard() {
    printf("\n");
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            printf(" %c ", board[i][j]);
            if(j<2) printf("|");
        }
        if(i<2) printf("\n---+---+---\n");
    }
    printf("\n");
}

int checkWin() {
    for(int i=0;i<3;i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return 1;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return 1;
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return 1;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return 1;
    return 0;
}

int main() {
    int move, player=1, filled=0;
    char mark;
    while(1) {
        showBoard();
        mark = (player==1)?'X':'O';
        printf("Player %d, enter your move (1-9): ", player);
        scanf("%d",&move);
        if(move<1 || move>9) {
            printf("Invalid move\n");
            continue;
        }
        int r=(move-1)/3, c=(move-1)%3;
        if(board[r][c]=='X' || board[r][c]=='O') {
            printf("Cell already taken\n");
            continue;
        }
        board[r][c]=mark;
        filled++;
        if(checkWin()) {
            showBoard();
            printf("Player %d wins!\n", player);
            break;
        }
        if(filled==9) {
            showBoard();
            printf("It's a draw!\n");
            break;
        }
        player = (player==1)?2:1;
    }
    return 0;
}
