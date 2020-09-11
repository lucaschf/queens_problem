//
// Created by lucas on 9/10/2020.
//

#include "queens_problem.h"
#include "constants.h"

#include <stdio.h>
#include <string.h>

#define BOARD_DIMENSION 8

int board[BOARD_DIMENSION][BOARD_DIMENSION];

int solutions = 0;

int isSafe(int line, int column);

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

    fprintf(output, "%s %d\n\n", SOLUTION, solutions);

    for (i = 0; i < BOARD_DIMENSION; i++) {
        for (j = 0; j < BOARD_DIMENSION; j++) {
            int itemOnPosition = board[i][j];
            fprintf(output, "[%c]\t", itemOnPosition == 1 ? 'Q' : ' ');
        }

        fprintf(output, "\n\n");
    }

    fprintf(output, "\n");
}

int execute(int column, FILE *output) {
    int line;

    if (column == BOARD_DIMENSION) {
        solutions++;
        logSolution(output);
        return solutions;
    }

    for (line = 0; line < BOARD_DIMENSION; line++) {
        if (isSafe(line, column)) {
            board[line][column] = 1;

            execute(column + 1, output);

            board[line][column] = 0; // reset for next try
        }
    }

    return solutions;
}

int isValidParameters(int line, int column, char *errorMessage) {
    if (line > BOARD_DIMENSION - 1 || line < 0) {
        strcpy(errorMessage, INVALID_STARTING_LINE);
        return 0;
    }

    if (column > BOARD_DIMENSION - 1 || column < 0) {
        strcpy(errorMessage, INVALID_STARTING_COLUMN);
        return 0;
    }

    return 1;
}

int solveProblem(int startingLine, int startingColumn, FILE *output) {
    solutions = 0;
    memset(board, 0, sizeof(board));

    return execute(0, output);
}

/**
 * Checks whether the queen can occupy that line without being attacked
 *
 * @param line
 * @return 1 if true, 0 otherwise
 */
int isLineFree(int line) {
    int i;

    for (i = 0; i < BOARD_DIMENSION; i++) {
        if (board[line][i] == 1)
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
 * @param line
 * @param column
 * @return 1 if true, 0 otherwise
 */
int isDiagonalFree(int line, int column) {
    int i;
    int j;

    for (i = line, j = column; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    for (i = line, j = column; i < BOARD_DIMENSION && j < BOARD_DIMENSION; i++, j++) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

/**
 * Check if the queen can occupy the position without being attacked through the secondary diagonal
 * @param line
 * @param column
 * @return 1 if true, 0 otherwise
 */
int isSecondaryDiagonalFree(int line, int column) {
    int i;
    int j;

    for (i = line, j = column; i >= 0 && j < BOARD_DIMENSION; i--, j++) {
        if (board[i][j] == 1)
            return 0;
    }

    for (i = line, j = column; i < BOARD_DIMENSION && j >= 0; i++, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

/**
 * Checks whether a position is safe for occupation
 * @param line
 * @param column
 * @return 1 if safe, 0 otherwise
 */
int isSafe(int line, int column) {
    return isLineFree(line) &&
           isColumnFree(column) &&
           isDiagonalFree(line, column) &&
           isSecondaryDiagonalFree(line, column);
}