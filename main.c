#include <stdio.h>
#include <locale.h>
#include "queens_problem.h"


int main() {
    setlocale(LC_ALL, "Portuguese");

    int solutions = 0;

    FILE *f = fopen("output.txt", "w");

    solveProblem(0, &solutions, f);

    printf("\nNumero de solucoes %d", solutions);

    return 0;
}
