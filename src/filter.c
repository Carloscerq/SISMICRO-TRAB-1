#ifdef MOVING_AVERAGE_FILTER
#define MOVING_AVERAGE_FILTER

#include <stdio.h>
#include <stdlib.h>

#include "FILTER.h"


float moving_average_filter(int new_value) {

    // Most Recent Value    =   0
    // Oldest Value         =   N - 1
    for(int i = N - 1; i > 0; i--){
        vals[i] = vals[i - 1];          // Shift old values
    }
    vals[0] = new_value;                // Save new value


    sum = 0;
    for(int i = 0; i < N; i++){
        sum += vals[i];                 // Sum all N values
    }

    return sum / N;                     // Return the average
}

#endif