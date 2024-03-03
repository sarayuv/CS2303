/*
void total_sales(int rows, int cols, int data[][cols])
calculates the total sales across all inputted files for each item

Parameters:
    rows: the number of rows
    cols: the number of columns
    data[][cols]: the array that data will be found in
Returns:
    N/A
*/
extern void total_sales(int rows, int cols, int data[]);

/*
int top_month(int rows, int cols, int data[], int month, int i)
calculates the item with the most sales for each month of the inputted files

Parameters:
    rows: the number of rows
    cols: the number of columns
    data[][cols]: the array that data will be found in
    i: the number of inputted files
Returns:
    int: the item number with the most sales
*/
extern int top_month(int rows, int cols, int data[], int month, int i);

/*
int top_overall(int rows, int cols, int data[][cols])
calculates the item with the most sales out of all the months of the inputted files

Parameters:
    rows: the number of rows
    cols: the number of columns
    data[][cols]: the array that data will be found in
Returns:
    int: the item number with the most sales out of all the months
*/

extern int top_overall(int rows, int cols, int data[]);
