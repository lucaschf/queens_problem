//
// Created by lucas on 9/10/2020.
//

#ifndef QUEENS_PROBLEM_QUEENS_BOARD_H
#define QUEENS_PROBLEM_QUEENS_BOARD_H

#include <stdio.h>

/**
 * Tries to solve the queen's problem.
 *
 * @param column the starting column
 * @param solutions pointer to solution counting variable
 * @param output output file
 */
void solveProblem(int column, int *solutions, FILE *output);

#endif //QUEENS_PROBLEM_QUEENS_BOARD_H