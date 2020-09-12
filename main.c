#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#include "queens_problem.h"
#include "constants.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    // user can either or not define the starting column
    int row = argc >= 2 ? atoi(argv[1]) : 0;

    // user can either or not define the starting line
    int column = argc == 3 ? atoi(argv[2]) : argc == 2 ? atoi(argv[1]) : 0;

    FILE *f = fopen(OUTPUT_FILE, "w");

    if (!f)
        printf("%s\n", UNABLE_TO_LOG_SOLUTIONS);

    if (!isValidEntryPoint(column, row)) {
        printf("\n%s", INVALID_ENTRY_POINT);
        return 1;
    }

    printf("%s: %d", NUMBER_OF_POSSIBLE_SOLUTIONS, placeQueens(column, row, f));
    if (f) {
        printf("\n%s %s", SOLUTION_GENERATED_IN, OUTPUT_FILE);
        fclose(f);
    }

    return 0;
}