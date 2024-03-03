#include <stdio.h>
#include <string.h>

void total_sales(int rows, int cols, int data[][cols]);
int top_month(int rows, int cols, int data[][cols], int month, int i);
int top_overall(int rows, int cols, int data[][cols]);


int main(int argc, char *argv[]) {
    // creating an array for results.txt
    int allData[50][argc - 1];

    // creating a variable to use for the number of an item sold in the loop
    int numSold;

    // this loop is for looping over how many files are inputted
    for (int w = 1; w < argc; w++) {
        FILE* f = fopen(argv[w], "r");
        if (f == NULL) {
            printf("File not found.");
            return 0;
        }

        // this loop is to loop through the 50 items in each file
        for (int r = 0; r < 50; r++) {
            if (fscanf(f, "%*d %*s %d", &numSold) == 1) {
                allData[r][w-1] = numSold;
            }
        }

        fclose(f);
    
    }

    total_sales(50, argc - 1, allData);

    for (int i = 1; i < argc; i++) {
        const char* monthStr = argv[i];
        int month;

        if (strcmp(monthStr, "Jan_2023_data.txt") == 0) {
            month = 1;
        } else if (strcmp(monthStr, "Feb_2023_data.txt") == 0) {
            month = 2;
        } else if (strcmp(monthStr, "March_2023_data.txt") == 0) {
            month = 3;
        } else if (strcmp(monthStr, "April_2023_data.txt") == 0) {
            month = 4;
        } else if (strcmp(monthStr, "May_2023_data.txt") == 0) {
            month = 5;
        } else if (strcmp(monthStr, "June_2023_data.txt") == 0) {
            month = 6;
        } else if (strcmp(monthStr, "July_2023_data.txt") == 0) {
            month = 7;
        } else if (strcmp(monthStr, "Aug_2023_data.txt") == 0) {
            month = 8;
        } else {
            month = 0;
        }
        
        int top1 = top_month(50, argc - 1, allData, month, i);
        printf("The top item in %s is item %d.\n", argv[i], top1);

    }

    int top2 = top_overall(50, argc - 1, allData);
    printf("The top item across all months is item %d.\n", top2);

    return 0;
}
