#include <stdio.h>
#include <locale.h>
#include "queens_problem.h"

#define UNABLE_TO_LOG_SOLUTIONS "Incapaz de realizar log das soluções."
#define NUMBER_OF_POSSIBLE_SOLUTIONS "Numero de solucoes possiveis"
#define SOLUTION_GENERATED_IN "Solucoes geradas em"

#define OUTPUT_FILE "output.txt"

int main() {
    setlocale(LC_ALL, "Portuguese");

    FILE *f = fopen(OUTPUT_FILE, "w");

    if (!f)
        printf("%s\n", UNABLE_TO_LOG_SOLUTIONS);

    printf("%s: %d", NUMBER_OF_POSSIBLE_SOLUTIONS, solveProblem(f));
    if (f)
        printf("\n%s %s", SOLUTION_GENERATED_IN, OUTPUT_FILE);

    fclose(f);

    return 0;
}