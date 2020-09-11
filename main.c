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
    printf("Solutions %d", findSolution(0));
    return 0;
}


