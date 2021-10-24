#include <stdlib.h>
#include <stdio.h>

#define N   10          // Higher N, further delayed the signal
                        // Smaller N, more variant the signal

long sum=0;             // AUX to save the sum of N values
int vals[N];            // Array to alocate old and new values.


// We are using float because the sum of values might be a fraction
float moving_average_filter(int new_value);
 