#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#include "queens_problem.h"
#include "constants.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    // user can either or not define the starting column
    int startingColumn = argc > 2 ? atoi(argv[1]) : 0;

    // user can either or not define the starting line
    int startingLine = argc == 3 ? atoi(argv[2]) : argc == 2 ? atoi(argv[1]) : 0;

    FILE *f = fopen(OUTPUT_FILE, "w");

    if (!f)
        printf("%s\n", UNABLE_TO_LOG_SOLUTIONS);

    if (!isValidEntryPoint(startingColumn, startingLine)) {
        printf("\n%s", INVALID_ENTRY_POINT);
        return 1;
    }

    printf("%s: %d", NUMBER_OF_POSSIBLE_SOLUTIONS, placeQueens(startingLine, startingColumn, f));
    if (f) {
        printf("\n%s %s", SOLUTION_GENERATED_IN, OUTPUT_FILE);
        fclose(f);
    }

    return 0;
}