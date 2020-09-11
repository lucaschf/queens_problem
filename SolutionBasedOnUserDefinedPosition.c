//
// Created by lucas on 9/11/2020.
//

#include <stdio.h>

#define QUEEN_COUNT 8

int solutionsCount = 0;
int queens[QUEEN_COUNT];

typedef struct {
    int x;
    int y;
} Position;

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

    for (i = 0; i < k; i++) {
        if (isAttacked(createPosition(i, queens[i]), createPosition(k, queens[k])) == 1)
            return 0;
    }

    return 1;
}

void solve(int k) {
    if (queens[0] > 7) // already ran through all possible positions and found the solution.
        return;

    if (queens[k] > 7) // found all solutions based on this position.
    {
        k--;
        queens[k]++; // steps into next queen's position

        solve(k);
    }

    if (k == 7 &&( isSafePlace(k)) == 1) {
        solutionsCount++;
        printSolution();
        queens[k]++;
        solve(k);
    }

    if (isSafePlace(k) == 1) {
        k++;
        queens[k] = 0;
    } else {
        queens[k]++;
    }

    solve(k);
}

int findSolution(int k) {
    solutionsCount = 0;

    queens[0] = 0;
    for (int i = 1; i < QUEEN_COUNT; i++) {
        queens[i] = QUEEN_COUNT;
    }

    solve(k);

    return solutionsCount;
}
