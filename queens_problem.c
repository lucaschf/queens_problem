//
// Created by lucas on 9/11/2020.
//

#include <stdio.h>
#include <string.h>

#include "queens_problem.h"
#include "constants.h"

#define BOARD_DIMENSION 8

int initialRow; // used to block the entry point.

int solutionsCount = 0;
int board[BOARD_DIMENSION][BOARD_DIMENSION];

FILE *output;

/**
 * Logs the solution and its number to a file. The positions occupied by queen are marked with the character 'Q'
 * while the empty positions are marked with a white space
 *
 * @param solution
 * @param output
 */
void logSolution() {
    int i;
    int j;

    if (!output)
        return;

    if (solutionsCount != 1)
        fprintf(output, "\n\n");

    fprintf(output, "%s %d\n\n ", SOLUTION, solutionsCount);

    for (i = 0; i < BOARD_DIMENSION; i++) { // the board columns
        fprintf(output, "  %d ", i);
    }

    for (i = 0; i < BOARD_DIMENSION; i++) {
        fprintf(output, "\n%d ", i); // the current row
        for (j = 0; j < BOARD_DIMENSION; j++) {
            int itemOnPosition = board[i][j];
            fprintf(output, "[%c] ", itemOnPosition == 1 ? 'Q' : ' ');
        }
    }
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
 * Checks if the queen can occupy the position without being attacked through the main diagonal
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
 * Checks if the queen can occupy the position without being attacked through the secondary diagonal
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

/**
 * Checks whether a position is safe for occupation. A position is safe if there are no queens on the diagonals,
 * row or column.
 *
 * @param row
 * @param column
 * @return 1 if safe, 0 otherwise
 */
int isSafe(int row, int col) {
    return isRowFree(row)
           && isColumnFree(col)
           && isDiagonalFree(row, col)
           && isSecondaryDiagonalFree(row, col);
}

void searchPositions(int row) {
    if (row == initialRow) {
        // Reached some solution.
        // Logs the board matrix and stops.
        solutionsCount++;
        logSolution();
        return;
    }

    int column;

    // Place at all possible positions and move to smaller problem
    for (column = 0; column < BOARD_DIMENSION; column++) {
        if (isSafe(row, column)) {  // if no attack, proceed
            board[row][column] = 1;

            if (row != initialRow)
                searchPositions((row + 1) % BOARD_DIMENSION);  // call function to continue further accessing in circular manner.
        }

        board[row][column] = 0; // unmark to backtrack
    }
}

/**
 * Initializes the board and performs the search.
 *
 * @param column the column of the first queen on the board.
 * @param row the first line on the board.
 * @param logFile the output file of the solutions. if null, no logs will be generated.
 * @return the number of possible solutions found.
 */
int placeQueens(int column, int row, FILE *logFile) {
    solutionsCount = 0;

    initialRow = row;
    output = logFile;

    memset(board, 0, sizeof(board));
    board[row][column] = 1; // positions the first queen on board

    searchPositions(row + 1 % BOARD_DIMENSION); // call the backtracking function and log solutions

    return solutionsCount;
}

int isValidEntryPoint(int column, int row) {
    return (row > BOARD_DIMENSION - 1 || row < 0) || (column > BOARD_DIMENSION - 1 || column < 0) ? 0 : 1;
}