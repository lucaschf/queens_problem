//
// Created by lucas on 9/11/2020.
//

#include <stdio.h>
#include <string.h>

#include "SolutionBasedOnUserDefinedPosition.h"
#include "constants.h"

#define BOARD_DIMENSION 8

int initialRow;

int solutionsCount = 0;
int board[BOARD_DIMENSION][BOARD_DIMENSION];

FILE *f;

/**
 * Saves the solution and its number to a file
 *
 * @param solution
 * @param output
 */
void logSolution(FILE *output) {
    int i;
    int j;

    if (!output)
        return;

    fprintf(output, "%s %d\n\n ", SOLUTION, solutionsCount);

    for (i = 0; i < BOARD_DIMENSION; i++) {
        fprintf(output, "  %d ", i);
    }
    fprintf(output, "\n");

    for (i = 0; i < BOARD_DIMENSION; i++) {
        fprintf(output, "%d ", i);
        for (j = 0; j < BOARD_DIMENSION; j++) {
            int itemOnPosition = board[i][j];
            fprintf(output, "[%c] ", itemOnPosition == 1 ? 'Q' : ' ');
        }

        fprintf(output, "\n\n");
    }

    fprintf(output, "\n");
}


/**
 * Checks whether the queen can occupy that row without being attacked
 *
 * @param row
 * @return 1 if true, 0 otherwise
 */
int isRowFree(int row) {
    int i;

    for (i = 0; i < BOARD_DIMENSION; i++) {
        if (board[row][i] == 1)
            return 0;
    }

    return 1;
}

/**
 * Checks whether the queen can occupy that column without being attacked
 *
 * @param column
 * @return 1 if true, 0 otherwise
 */
int isColumnFree(int column) {
    int i;

    for (i = 0; i < BOARD_DIMENSION; i++) {
        if (board[i][column] == 1)
            return 0;
    }

    return 1;
}

/**
 * Check if the queen can occupy the position without being attacked through the main diagonal
 *
 * @param row
 * @param column
 * @return 1 if true, 0 otherwise
 */
int isDiagonalFree(int row, int column) {
    int i;
    int j;

    for (i = row, j = column; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    for (i = row, j = column; i < BOARD_DIMENSION && j < BOARD_DIMENSION; i++, j++) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

/**
 * Check if the queen can occupy the position without being attacked through the secondary diagonal
 * @param row
 * @param column
 * @return 1 if true, 0 otherwise
 */
int isSecondaryDiagonalFree(int row, int column) {
    int i;
    int j;

    for (i = row, j = column; i >= 0 && j < BOARD_DIMENSION; i--, j++) {
        if (board[i][j] == 1)
            return 0;
    }

    for (i = row, j = column; i < BOARD_DIMENSION && j >= 0; i++, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

int isSafe(int row, int col) {
    return isRowFree(row)
           && isColumnFree(col)
           && isDiagonalFree(row, col)
           && isSecondaryDiagonalFree(row, col);
}

void nQueenHelper(int row) {
    if (row == initialRow) {
        // We have reached some solution.
        // Print the board matrix
        // return
        solutionsCount++;
        logSolution(f);
        return;
    }

    // Place at all possible positions and move to smaller problem
    for (int column = 0; column < BOARD_DIMENSION; column++) {
        if (isSafe(row, column)) {  // if no attack, proceed
            board[row][column] = 1;

            if (row != initialRow)
                nQueenHelper((row + 1) % BOARD_DIMENSION);  // call function to continue further
        }

        board[row][column] = 0; // unmark to backtrack
    }
}

void placeQueens(int column, int row) {
    solutionsCount = 0;

    initialRow = row;

    memset(board, 0, sizeof(board));
    board[row][column] = 1;

    nQueenHelper(row + 1 % BOARD_DIMENSION); // call the backtracking function and print solutions
}

int main() {
    int column = 5;
    int row = 5;

    f = fopen("output2.txt", "w");

    placeQueens(column, row);
    printf("%s: %d", NUMBER_OF_POSSIBLE_SOLUTIONS, solutionsCount);
    return 0;
}