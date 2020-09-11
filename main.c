#include <stdio.h>

#include "SolutionBasedOnUserDefinedPosition.h"


//int main(int argc, char *argv[]) {
//    setlocale(LC_ALL, "Portuguese");
//
//    char errorMessage[300];
//
//    // user can either or not define the starting column
//    int startingColumn = argc > 2 ? atoi(argv[1]) : 0;
//
//    // user can either or not define the starting line
//    int startingLine = argc == 3 ? atoi(argv[2]) : argc == 2 ? atoi(argv[1]) : 0;
//
//    FILE *f = fopen(OUTPUT_FILE, "w");
//
//    if (!f)
//        printf("%s\n", UNABLE_TO_LOG_SOLUTIONS);
//
//    if (isValidParameters(startingLine, startingColumn, errorMessage) == 0) {
//        printf("\n%s", errorMessage);
//        return 1;
//    }
//
//    printf("%s: %d", NUMBER_OF_POSSIBLE_SOLUTIONS, solveProblem(startingLine, startingColumn, f));
//    if (f)
//        printf("\n%s %s", SOLUTION_GENERATED_IN, OUTPUT_FILE);
//
//    fclose(f);
//
//    return 0;
//}

int main() {
    int a[] = {1, 2, 3, 4, 5};

//    int current = 2;
//    int i = current -1;
//
//    for (; current % 5 != i; current++) {
//        printf("\n%d", a[current % 5]);
//    }


//
    Position p = createPosition(2, 0);
    printf("Solutions %d", findSolution(p));
    return 0;


}


