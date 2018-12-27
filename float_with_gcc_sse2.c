/* Float Multiply with gcc compile option "-O3"
   and enable optimization with SSE2 */

#include <stdio.h>
#include <stdlib.h>
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

    float input [array_size] __attribute__ ((aligned (16)));

    for (unsigned long i = 0; i < array_size; i ++) {
        unsigned int result;
        fscanf(fpin, "%u\n", &result);
        input[i] = *(float *)&result;
    }

    fclose(fpin);

    struct timespec start, end;
    unsigned long elipse = 0;
    for (unsigned long i = 0; i < array_size; i ++) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        input[i] *= MULTIPLIER;
        clock_gettime(CLOCK_MONOTONIC, &end);
        elipse = (unsigned long)(end.tv_nsec - start.tv_nsec);
        printf("%lu\n", elipse);
    }

    return 0;
}