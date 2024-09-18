#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int sumOfOutDegree = 0;
    int sumOfInDegree = 0;
    int totalSumOfInDegrees = 0;
    int totalSumOfOutDegrees = 0;
    int nVertices = 5000;

    // Allocate memory dynamically for the 2D array
    int **directed_graph_array = malloc(nVertices * sizeof(int *));
    for (int i = 0; i < nVertices; i++) {
        directed_graph_array[i] = malloc(nVertices * sizeof(int));
    }

    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            directed_graph_array[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            if(directed_graph_array[i][j] == 1) {
                sumOfOutDegree += 1;
            }
            if(directed_graph_array[j][i] == 1) {
                sumOfInDegree += 1;
            }
        }
//        printf("deg-(%d) = %d\n", i, sumOfInDegree);
        totalSumOfInDegrees += sumOfInDegree;
//        printf("deg+(%d) = %d\n", i, sumOfOutDegree);
        totalSumOfOutDegrees += sumOfOutDegree;
        sumOfOutDegree = 0;
        sumOfInDegree = 0;
    }

    printf("Total Sum of In Degrees: %d\n", totalSumOfInDegrees);
    printf("Total Sum of Out Degrees: %d\n", totalSumOfOutDegrees);
    if (totalSumOfInDegrees == totalSumOfOutDegrees) {
        printf("Sum of in-degrees and Sum of out-degrees are equal.\n");
    } else {
        printf("Sum of in-degrees and Sum of out-degrees are not equal!");
    }

    // Free allocated memory
    for (int i = 0; i < nVertices; i++) {
        free(directed_graph_array[i]);
    }
    free(directed_graph_array);
    return 0;
}
