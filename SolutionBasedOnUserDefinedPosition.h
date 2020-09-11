//
// Created by lucas on 9/11/2020.
//

#ifndef QUEENS_PROBLEM_SOLUTION_BASED_ON_USER_DEFINED_POSITION_H
#define QUEENS_PROBLEM_SOLUTION_BASED_ON_USER_DEFINED_POSITION_H

typedef struct {
    int x;
    int y;
} Position;

int findSolution(Position from);

Position createPosition(int x, int y);

#endif //QUEENS_PROBLEM_SOLUTION_BASED_ON_USER_DEFINED_POSITION_H
