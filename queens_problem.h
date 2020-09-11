//
// Created by lucas on 9/10/2020.
//

#ifndef QUEENS_PROBLEM_QUEENS_BOARD_H
#define QUEENS_PROBLEM_QUEENS_BOARD_H

#include <stdio.h>

/**
 * Tries to solve the queen's problem.
 *
 * @param output target output file
 * @return the number of possible resolutions
 */
int solveProblem(int startingLine, int startingColumn, FILE *output);

/**
 * Checks if the informed parameters are acceptable for the problem resolution.
 *
 * @param line the starting line.
 * @param column the start column defined.
 * @param errorMessage pointer to returning error message.
 * @return 1 if accepted, 0 otherwise.
 */
int isValidParameters(int line, int column, char *errorMessage);

#endif //QUEENS_PROBLEM_QUEENS_BOARD_H