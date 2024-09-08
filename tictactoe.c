#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

//STEP 1: DEFINE VARIABLES
char player1[26];
char player2[26];
int board[3][3] = {
                    {-1,-1,-1},
                    {-1,-1,-1},
                    {-1,-1,-1}
                };
int turn;

//STEP 2: DEFINE MAIN FUNCTIONS
char getValue(int i, int j){
    char val;
    if(board[i][j] == -1) val = ' ';
    else if(board[i][j] == 0) val = 'X';
    else if(board[i][j] == 1) val = 'O';
    return val;
}

void printBoard(int turn){
    printf("\n-------TURN No.: %d ------\n",turn );
    if(turn%2 == 0){
        printf("------%s THE BALL IS IN YOUR COURT!------\n", player1);
    } 
    else printf("------%s THE BALL IS IN YOUR COURT!------\n", player2);

    int hr=196, vr=179; // These are ascii character which display the lines
    int crossbr=197;
    int count=0;
    while(count<3){
        for(int i=0; i<3; i++){
            char val = getValue(count, i);
            if(i<2) printf(" %c %c", val, vr);
            else printf(" %c ", val);
        }
        printf("\n");
        printf("%c%c%c%c",hr,hr,hr, crossbr, hr);
        printf("%c%c%c%c",hr,hr,hr, crossbr, hr);
        printf("%c%c%c\n",hr,hr,hr, hr);
        count++;
    }
}

bool testConditions(int r, int c){
    if(r < 0 || r > 2) return false;
    if(c < 0 || c > 2) return false;
    if(board[r][c]!=-1) return false;
    return true;
}

bool verifyWin(int turn){
    int currentPlayer = turn % 2; // 0 for player1 ('X'), 1 for player2 ('O')

    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true; // Row victory
        }
    }

    // Check columns
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer) {
            return true; // Column victory
        }
    }

    // Check diagonals
    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true; // Diagonal from top-left to bottom-right
    }
    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true; // Diagonal from top-right to bottom-left
    }

    // Check for tie: if the board is fully filled and no winner
    bool boardFull = true;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == -1) {
                boardFull = false;
                break;
            }
        }
    }
    
    if(boardFull) {
        printf("It's a tie!\n");
        return true; // Game ends in a tie
    }
    return false; // No win or tie yet
}

//STEP 3: DEFINE GAME LOGIC
int main(){
    printf("Please enter name of player no 1: ");
    scanf("%s", player1);

    printf("Please enter name of player no 2: ");
    scanf("%s", player2);

    bool end = false;
    int turn = 0;

    while(!end){
        int row, column;
        printBoard(turn);
        printf("Choose the row (0-2): ");
        scanf("%d", &row);

        printf("Choose the column (0-2): ");
        scanf("%d", &column);

        if(testConditions(row, column)){
            if(turn % 2 == 0) {
                board[row][column] = 0; // Player 1 uses 'X'
            } else {
                board[row][column] = 1; // Player 2 uses 'O'
            }
        } else {
            printf("INVALID INPUT! Please try again.\n");
            continue;
        }

        if(verifyWin(turn)){
            printBoard(turn); // Show final board state
            if(turn % 2 == 0) {
                printf("Congratulations %s! You have won the game.\n", player1);
            } else {
                printf("Congratulations %s! You have won the game.\n", player2);
            }
            end = true;
        }

        turn++;
    }
    
    
}