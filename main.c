#include <stdio.h>

int main() {
    int sumOfOutDegree = 0;
    int sumOfInDegree = 0;
    // Part II Presentation: Slide page 96, Definition 4, Example:
    int directed_graph_array[7][7] = {
            {1, 1, 1, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 0, 0},
            {0, 1, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0},
            {1, 0, 0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
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
        printf("deg+(%d) = %d\n", i, sumOfOutDegree);
        sumOfOutDegree = 0;
        sumOfInDegree = 0;
    }
    return 0;
}
