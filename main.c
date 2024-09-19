#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int directed_graph_array[5001][5001];

int main() {
    srand(time(NULL));

    clock_t start, end;

    double computationTime = 0.0;

    start = clock();

    int sumOfOutDegree = 0;
    int sumOfInDegree = 0;
    int totalSumOfInDegrees = 0;
    int totalSumOfOutDegrees = 0;
    int nVertices = 5000;

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
        totalSumOfInDegrees += sumOfInDegree;
        totalSumOfOutDegrees += sumOfOutDegree;
        sumOfOutDegree = 0;
        sumOfInDegree = 0;
    }

    printf("Total Vertices/n : %d\n", nVertices);

    printf("Total Sum of In Degrees: %d\n", totalSumOfInDegrees);
    printf("Total Sum of Out Degrees: %d\n", totalSumOfOutDegrees);

    if (totalSumOfInDegrees == totalSumOfOutDegrees) {
        printf("Sum of In Degrees and Sum of Out Degrees are equal.\n");
    } else {
        printf("Sum of In Degrees and Sum of Out Degrees are not equal!");
    }

    end = clock();

    computationTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Computational Time: %.2f seconds", computationTime);
    return 0; // O(1)
}
