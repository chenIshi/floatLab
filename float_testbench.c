#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "const.h"

int main() {
    FILE *fpin = fopen(FLOAT_OUT_FILE_LOCAT, "r");
    enum Error err;
    if (!fpin) {
        fprintf(stderr, "Failed to read random float array.\n");
        err = FILE_CANT_OPEN;
        return err;
    }

    float input [array_size];

    for (int i = 0; i < array_size; i ++) {
        unsigned int result;
        fscanf(fpin, "%u\n", &result);
        input[i] = *(float *)&result;
    }

    fclose(fpin);

    struct timespec start, end, elipse;
    for (int i = 0; i < array_size; i ++) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        input[i] *= MULTIPLIER;
        clock_gettime(CLOCK_MONOTONIC, &end);
        elipse.tv_nsec += end.tv_nsec - start.tv_nsec;
    }

    printf("%d\n", (unsigned int)(elipse.tv_nsec / array_size));
   
    return 0; 
}