#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateSamples (int lowerLimit, int upperLimit) {

    srand(time(0));
    return (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit;
    
}
