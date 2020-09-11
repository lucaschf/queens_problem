#include <stdio.h>
#include <locale.h>
#include "queens_problem.h"

#define UNABLE_TO_LOG_SOLUTIONS "Incapaz de realizar log das soluções."
#define NUMBER_OF_POSSIBLE_SOLUTIONS "Numero de solucoes possiveis"

int main() {
    setlocale(LC_ALL, "Portuguese");

    FILE *f = fopen("output.txt", "w");

    printf("\n%s: %d", NUMBER_OF_POSSIBLE_SOLUTIONS, solveProblem(f));

    return 0;
}