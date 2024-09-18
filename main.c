#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber() {
    srand(time(0));
    int random_number = rand() % 2;
    return random_number;
}

int main() {

    int sumOfOutDegree = 0;
    int sumOfInDegree = 0;
    int totalSumOfInDegrees = 0;
    int totalSumOfOutDegrees = 0;

    printf("%d\n", getRandomNumber());

    // Part II Presentation: Slide page 96, Definition 4, Example:
    int directed_graph_array[7][7] = {
            {1, 1, 1, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 0, 0},
            {0, 1, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0},
            {1, 1, 0, 1, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
    };

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if(directed_graph_array[i][j] == 1) {
                sumOfOutDegree += 1;
            }
            if(directed_graph_array[j][i] == 1) {
                sumOfInDegree += 1;
            }
        }
        printf("deg-(%d) = %d\n", i, sumOfInDegree);
        totalSumOfInDegrees += sumOfInDegree;
        printf("deg+(%d) = %d\n", i, sumOfOutDegree);
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
    return 0;
}
