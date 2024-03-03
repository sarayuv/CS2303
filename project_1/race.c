#include <stdio.h>
#include <stdlib.h>
#include "animals.h"

int main() {
    // prompt user for a random number seed
    printf("Please enter a random number seed.\n");

    // get the value from the user and set the seed
    int user_seed;
    scanf("%d", &user_seed);
    srand(user_seed);
    int rand(void);

    // store the current positions of the tortoise and the hare
    int hare_current = 0;
    int tortoise_current = 0;
    int latest_lead = -1;
    
    int y = 0;
    int t = 1;
    while(y == 0){
        // run the race, updating the positions at each time step (hare before tortoise)
        hare_current = update_hare(hare_current);
        tortoise_current = update_tortoise(tortoise_current);
        
        // use an integer variable to keep track of who is winning (0 = tortoise, 1 = hare)
        int winning;
        if (hare_current > tortoise_current) {
            winning = 1;
        } else if (hare_current < tortoise_current) {
            winning = 0;
        }
    
        // each time one animal passes the other animal, print the current race status to the terminal
        if (winning != latest_lead) { 
            if (winning == 1){
                printf("At t = %d, the hare (square %d) has passed the tortoise (square %d).\n", t, hare_current, tortoise_current);
            } else {
                printf("At t = %d, the tortoise (square %d) has passed the hare (square %d).\n", t, tortoise_current, hare_current);
            }
        }

        // if either animal passes the finish line (square 70), print the winner of the race
        if (hare_current >= 70) {
            printf("After %d seconds, the hare wins!!", t);
            y = 1;
        } else if (tortoise_current >= 70) {
            printf("After %d seconds, the tortoise wins!!", t);
            y = 1;
        }

        latest_lead = winning;
        t++;
    }

    return 0;
}
