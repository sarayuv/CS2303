#include <stdio.h>

void total_sales(int rows, int cols, int data[][cols]) {
    FILE* resultsFile = fopen("results.txt", "w");

    fprintf(resultsFile, "Item\tSales\n");

    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum = 0;
        for (int j = 0; j < cols; j++) {
            sum = sum + data[i][j];
        }

        /* if (i + 1 < 10) {
            fprintf(resultsFile, "0%d\t%d\n", i + 1, sum);
        } else {
            fprintf(resultsFile, "%d\t%d\n", i + 1, sum);
        } */

        fprintf(resultsFile, "%02d\t%4d\n", i + 1, sum);

    }

    fclose(resultsFile);
}

int top_month(int rows, int cols, int data[][cols], int month, int i) {
    int max = 0;
    int topItem = 0;
    
    for (int r = 1; r <= 50; r++) {
        if (data[r-1][i-1] >= max) {
            max = data[r-1][i-1];
            topItem = r;
        }
    }
    
    return topItem;
}

int top_overall(int rows, int cols, int data[][cols]) {
    int topItem2 = 0;

    // calculate total sales of each item and store it in a new array
    int topArray[50] = {0};
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum = 0;
        for (int j = 0; j < cols; j++) {
            sum = sum + data[i][j];
        }
        topArray[i] = sum;
    }

    // identify the highest number in the array
    int max = 0;
    for (int r = 1; r <= 50; r++) {
        if (topArray[r-1] >= max) {
            max = topArray[r-1];
            topItem2 = r;
        }
    }

    return topItem2;
}
