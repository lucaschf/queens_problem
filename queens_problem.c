//
// Created by lucas on 9/10/2020.
//

#include "queens_problem.h"

#include <stdio.h>
#include <string.h>

#define BOARD_DIMENSION 8
#define SOLUTION "Solucao"

int board[BOARD_DIMENSION][BOARD_DIMENSION];

int isSafe(int line, int column);

void logSolution(int solution, FILE *output) {
    int i;
    int j;

    fprintf(output, "%s %d\n\n", SOLUTION, solution);

    for (i = 0; i < BOARD_DIMENSION; i++) {
        for (j = 0; j < BOARD_DIMENSION; j++) {
            int itemOnPosition = board[i][j];
            fprintf(output, "[%c]\t", itemOnPosition == 1 ? 'Q' : ' ');
        }

        fprintf(output, "\n\n");
    }

    fprintf(output, "\n");
}

void execute(int column, int *solutions, FILE *output) {
    int i;

    if (column == BOARD_DIMENSION) {
        *solutions = *solutions + 1;
        logSolution(*solutions, output);
        return;
    }

    for (i = 0; i < BOARD_DIMENSION; i++) {
        if (isSafe(i, column)) {
            board[i][column] = 1;

            execute(column + 1, solutions, output);

            board[i][column] = 0; // reset for next try
        }
    }
}

void solveProblem(int column, int *solutions, FILE *output) {
    memset(board, 0, sizeof(board));

    execute(column, solutions, output);
}

int isLineFree(int line) {
    int i;

    for (i = 0; i < BOARD_DIMENSION; i++) {
        if (board[line][i] == 1)
            return 0;
    }

    return 1;
}

int isColumnFree(int column) {
    int i;

    for (i = 0; i < BOARD_DIMENSION; i++) {
        if (board[i][column] == 1)
            return 0;
    }

    return 1;
}

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

int isSafe(int line, int column) {
    return isLineFree(line) &&
           isColumnFree(column) &&
           isDiagonalFree(line, column) &&
           isSecondaryDiagonalFree(line, column);
}