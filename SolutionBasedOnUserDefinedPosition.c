//
// Created by lucas on 9/11/2020.
//

#include <stdio.h>
#include "SolutionBasedOnUserDefinedPosition.h"

#define QUEEN_COUNT 8

int solutionsCount = 0;
int queens[QUEEN_COUNT];

Position entryPoint;

Position createPosition(int x, int y) {
    Position p;

    p.x = x;
    p.y = y;

    return p;
}

void printSolution() {
    int i;
    int j;

    printf("\nSolucao: %d\n", solutionsCount);

    for (i = 0; i < QUEEN_COUNT; i++) {
        for (j = 0; j < QUEEN_COUNT; j++) {
            if (j == queens[i]) {
                printf("[Q] ");
            } else {
                printf("[ ] ");
            }
        }

        printf("\n");
    }

    printf("\n");
}

int isAttacked(Position from, Position target) {
    if ((from.x == target.x) || (from.y == target.y)) // same line or same column
        return 1;

    if (from.x > target.x)
        if ((from.x - target.x == from.y - target.y) || (from.x - target.x == target.y - from.y))
            return 1;

    if (target.x > from.x)
        if ((target.x - from.x == target.y - from.y) || (target.x - from.x == from.y - target.y))
            return 1;

    return 0;
}

int isSafePlace(int k) {
    int i;
    Position target = createPosition(k, queens[k]);

    for (i = 0; i < k; i++) {
        if (isAttacked(createPosition(i, queens[i]), target))
            return 0;
    }

    return 1;
}

void solve(int index) {

    if (queens[0] >= QUEEN_COUNT) // already ran through all possible positions and found the solution.
        return;

    if (queens[index] >= QUEEN_COUNT) // found all solutions based on this position.
    {
        index--; // step backward to the previous queen
        if (index != entryPoint.y) { // we do not move the queen from the entry point
            queens[index]++; // steps into next queen's position
        } else
            index--; // moves bac

        solve(index);
    }

    if (index == QUEEN_COUNT - 1 && (isSafePlace(index))) {
        solutionsCount++;
        printSolution();
        queens[index]++;

        solve(index);
    }

    if (isSafePlace(index)) {
        index++;
        queens[index] = 0;
    } else {
        queens[index]++;
    }

    solve(index);
}

int findSolution(Position from) {
    solutionsCount = 0;

    entryPoint = from;

    queens[0] = 0;
    for (int i = 1; i < QUEEN_COUNT; i++) {
        queens[i] = 0;
    }
    solve(from.y);

    return solutionsCount;
}
