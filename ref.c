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
 * Student Name  :
 * Student ID    :
 * Class/Section :
 * Date          :
 */

#include <stdio.h>
/* NO other header files are allowed */
/* NO global variables are allowed */



/* Display the game board and the unused numbers list on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output formats will result in mark deduction. */
void printInfo(int gameBoard[3][3], int numbers[9]) {

    // TODO: Complete this part

}



/* Read the user inputs to place a number on the game board.
   In Project Part 1, you can assume that the user inputs must be valid. */
void placeNumber(int gameBoard[3][3], int numbers[9], int currentPlayer) {

    // TODO: Complete this part

}



/* Return 1 if there is a winner in the game, otherwise return 0.
   Note: the winner is the current player indicated in main(). */
int hasWinner(int gameBoard[3][3]){

    // TODO: Complete this part

}



/* Return 1 if the game board is full, otherwise return 0. */
int isFull(int gameBoard[3][3]) {

    // TODO: Complete this part

}



/* The main function */
int main() {
    /* Local variables, you can declare more if necessary */
    int gameBoard[3][3] = {0};      /* A 2D array presenting the game board.
                                       Each element stores a number between 0 and 9 inclusively, where 0 represents an empty cell. */
    int numbers[9] = {0};           /* An array to record which numbers are used by the players.
                                       Example: if numbers[0] is 1, the number 1 is used
                                                if numbers[1] is 0, the number 2 is not used
                                                if numbers[8] is 1, the number 9 is used */
    int currentPlayer;              // 1: Player 1             2: Player 2
    int gameContinue;               // 1: The game continues   0: The game ends

    /* Initialize the local variables */
    currentPlayer = 1;
    gameContinue = 1;

    /* Uncomment the following statements to test whether the printInfo(...)
       and the placeNumber(...) functions are implemented correctly.
       You can add more if you wish.
       After testing, you can delete them. */
    //printInfo(gameBoard, numbers);
    //placeNumber(gameBoard, numbers, 1);
    //printInfo(gameBoard, numbers);
    //placeNumber(gameBoard, numbers, 2);
    //printInfo(gameBoard, numbers);

    /* Game start, Player 1 moves first */

    // TODO: Complete this part

    return 0;
}