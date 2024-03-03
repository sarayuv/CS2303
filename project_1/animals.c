#include <stdio.h>
#include <stdlib.h>

int update_hare(int current_position) {
    // generate a random number between 0 and 1
    float val = ((float) rand() / (float)(RAND_MAX));

    // determine the move type
    int x;
    if ((0.0 <= val) && (val < 0.2)) {
        x = 0;
    } else if ((0.2 <= val) && (val < 0.4)) {
        x = 9;
    } else if ((0.4 <= val) && (val < 0.5)) {
        x = -12;
    } else if ((0.5 <= val) && (val < 0.8)) {
        x = 1;
    } else if ((0.8 <= val) && (val < 1)) {
        x = -2;
    } else {
        x = 0;
    }

    // modify the position according to the move type 
    int new_position = current_position + x;

    // if a slip moves the hare behind the starting line, set the position to 0
    new_position = new_position < 0 ? 0 : new_position;

    return new_position;

}


int update_tortoise(int current_position) {
    // generate a random number between 0 and 1
    float val = ((float) rand() / (float)(RAND_MAX));

    // determine the move type
    int x;
    if ((0.0 <= val) && (val < 0.5)) {
        x = 3;
    } else if ((0.5 <= val) && (val < 0.7)) {
        x = -6;
    } else if ((0.7 <= val) && (val < 1)) {
        x = 1;
    } else {
        x = 0;
    }

    // modify the position according to the move type 
    int new_position = current_position + x;
    
    // if a slip moves the tortoise behind the starting line, set the position to 0
    new_position = new_position < 0 ? 0 : new_position;

    return new_position;
    
}
