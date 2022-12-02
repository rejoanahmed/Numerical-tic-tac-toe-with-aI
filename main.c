/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : Md Rejoan Ahmed
 * Student ID    : 1155187511
 * Class/Section : B
 * Date          : 2022/11/13
 */

#include <stdio.h>
/* NO other header files are allowed */
/* NO global variables are allowed */

/* Display the game board and the unused numbers list on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output formats will result in mark deduction. */
void printInfo(int gameBoard[3][3], int numbers[9]) {

    // TODO: Complete this part
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == 0) {
                printf(" |");
            } else {
                printf("%d|", gameBoard[i][j]);
            }
        }
        printf("\n");
    }

    printf("Unused numbers:\n");
    for (int i = 0; i < 9; i++) {
        if (numbers[i] == 0) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

/* Return 1 if the game board is full, otherwise return 0. */
int isFull(int gameBoard[3][3]) {

    // TODO: Complete this part
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

/* Return 1 if there is a winner in the game, otherwise return 0.
   Note: the winner is the current player indicated in main(). */
int hasWinner(int gameBoard[3][3]) {

    // TODO: Complete this part
    int row1, row2, row3, col1, col2, col3, dia1, dia2;
    if (gameBoard[0][0] && gameBoard[0][1] && gameBoard[0][2]) {
        row1 = gameBoard[0][0] + gameBoard[0][1] + gameBoard[0][2];
    } else {
        row1 = 0;
    }
    if (gameBoard[1][0] && gameBoard[1][1] && gameBoard[1][2]) {
        row2 = gameBoard[1][0] + gameBoard[1][1] + gameBoard[1][2];
    } else {
        row2 = 0;
    }
    if (gameBoard[2][0] && gameBoard[2][1] && gameBoard[2][2]) {
        row3 = gameBoard[2][0] + gameBoard[2][1] + gameBoard[2][2];
    } else {
        row3 = 0;
    }
    if (gameBoard[0][0] && gameBoard[1][0] && gameBoard[2][0]) {
        col1 = gameBoard[0][0] + gameBoard[1][0] + gameBoard[2][0];
    } else {
        col1 = 0;
    }
    if (gameBoard[0][1] && gameBoard[1][1] && gameBoard[2][1]) {
        col2 = gameBoard[0][1] + gameBoard[1][1] + gameBoard[2][1];
    } else {
        col2 = 0;
    }
    if (gameBoard[0][2] && gameBoard[1][2] && gameBoard[2][2]) {
        col3 = gameBoard[0][2] + gameBoard[1][2] + gameBoard[2][2];
    } else {
        col3 = 0;
    }
    if (gameBoard[0][0] && gameBoard[1][1] && gameBoard[2][2]) {
        dia1 = gameBoard[0][0] + gameBoard[1][1] + gameBoard[2][2];
    } else {
        dia1 = 0;
    }
    if (gameBoard[0][2] && gameBoard[1][1] && gameBoard[2][0]) {
        dia2 = gameBoard[0][2] + gameBoard[1][1] + gameBoard[2][0];
    } else {
        dia2 = 0;
    }

    if (row1 == 15 || row2 == 15 || row3 == 15 || col1 == 15 || col2 == 15 || col3 == 15 || dia1 == 15 || dia2 == 15) {
        return 1;
    } else {
        return 0;
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

/* minimax algorithm to find the best move for the computer */
int minimax(int gameBoard[3][3], int depth, int isMax, int numbers[9], int alpha, int beta) {
    int score = hasWinner(gameBoard);
    if (score) {
        if (isMax) {
            return -10 + depth;
        } else {
            return 10 - depth;
        }
    } else if (isFull(gameBoard)) {
        return 0;
    }

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard[i][j] == 0) {
                    for (int k = 0; k < 9; k++) {
                        if (numbers[k] == 0 && k % 2 == 1) {
                            gameBoard[i][j] = k + 1;
                            numbers[k] = 1;
                            best = max(best, minimax(gameBoard, depth + 1, 0, numbers, alpha, beta));
                            gameBoard[i][j] = 0;
                            numbers[k] = 0;
                            alpha = max(alpha, best);
                            if (beta <= alpha) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard[i][j] == 0) {
                    for (int k = 0; k < 9; k++) {
                        if (numbers[k] == 0 && k % 2 == 0) {
                            gameBoard[i][j] = k + 1;
                            numbers[k] = 1;
                            best = min(best, minimax(gameBoard, depth + 1, 1, numbers, alpha, beta));
                            gameBoard[i][j] = 0;
                            numbers[k] = 0;
                            beta = min(beta, best);
                            if (beta <= alpha) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        return best;
    }
}


/* Read the user inputs to place a number on the game board.
   In Project Part 1, you can assume that the user inputs must be valid. */
void placeNumber(int gameBoard[3][3], int numbers[9], int currentPlayer) {

    // TODO: Complete this part
    int row, col;
    char position[100], num[100];
    if (currentPlayer == 1) {
        printf("### Player %d's turn ###\n", currentPlayer);
        while (1) {
            printf("Input the position:");
            scanf("%s", position);

            printf("Input the number:");
            scanf("%s", num);

            int posCount = 0;
            for (int i = 0; i < 100; i++) {
                if (position[i] == '\0') {
                    break;
                }
                posCount++;
            }

            int numCount = 0;
            for (int i = 0; i < 100; i++) {
                if (num[i] == '\0') {
                    break;
                }
                numCount++;
            }

            if (posCount > 1 || numCount > 1) {
                printf("Invalid input!\n");
                continue;
            }
            if (position[0] < '1' || position[0] > '9') {
                printf("Invalid position!\n");
                continue;
            }
            if (num[0] < '1' || num[0] > '9') {
                printf("Invalid number!\n");
                continue;
            }
            if (numbers[num[0] - '1'] != 0) {
                printf("number used!\n");
                continue;
            }
            if (num[0] % 2 == 0) {
                printf("only odd accepted!\n");
                continue;
            }
            row = 2 - (position[0] - '1') / 3;
            col = (position[0] - '1') % 3;

            if (gameBoard[row][col] != 0) {
                printf("position %d has been occupied.\n", position[0] - '0');
            } else {
                gameBoard[row][col] = num[0] - '0';
                numbers[num[0] - '1'] = 1;
                break;
            }
        }
    } else {
        int bestVal = -1000;
        int bestRow, bestCol, bestNum;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard[i][j] == 0) {
                    for (int k = 0; k < 9; k++) {
                        if (numbers[k] == 0 && k % 2 == 1) {
                            gameBoard[i][j] = k + 1;
                            numbers[k] = 1;
                            int moveVal = minimax(gameBoard, 0, 0, numbers, -1000, 1000);
                            gameBoard[i][j] = 0;
                            numbers[k] = 0;
                            if (moveVal > bestVal) {
                                bestRow = i;
                                bestCol = j;
                                bestNum = k + 1;
                                bestVal = moveVal;
                            }
                        }
                    }
                }
            }
        }
        gameBoard[bestRow][bestCol] = bestNum;
        numbers[bestNum - 1] = 1;
        int pos = 3 * (2 - bestRow) + bestCol + 1;
        printf("Computer places %d at %d\n", bestNum, pos);

    }
}


/* The main function */
int main() {
    /* Local variables, you can declare more if necessary */
    int gameBoard[3][3] = {0}; /* A 2D array presenting the game board.
                              Each element stores a number between 0 and 9 inclusively, where 0 represents an empty cell. */
    int numbers[9] = {0};      /* An array to record which numbers are used by the players.
                              Example: if numbers[0] is 1, the number 1 is used
                                       if numbers[1] is 0, the number 2 is not used
                                       if numbers[8] is 1, the number 9 is used */
    int currentPlayer;         // 1: Player 1             2: Player 2
    int gameContinue;          // 1: The game continues   0: The game ends

    /* Initialize the local variables */
    currentPlayer = 1;
    gameContinue = 1;


    // TODO: Complete this part
    while (gameContinue) {
        printInfo(gameBoard, numbers);
        placeNumber(gameBoard, numbers, currentPlayer);
        if (hasWinner(gameBoard)) {
            printInfo(gameBoard, numbers);
            currentPlayer == 2 ? printf("Computer wins!\n") : printf("Congratulations! Player 1 wins!\n");
            gameContinue = 0;
        } else if (isFull(gameBoard)) {
            printInfo(gameBoard, numbers);
            printf("Draw game.\n");
            gameContinue = 0;
        } else {
            if (currentPlayer == 1) {
                currentPlayer = 2;
            } else {
                currentPlayer = 1;
            }
        }
    }

    return 0;
}