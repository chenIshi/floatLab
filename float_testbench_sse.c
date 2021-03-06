#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <xmmintrin.h>

#include "const.h"

int main()
{
    FILE *fpin = fopen(FLOAT_OUT_FILE_LOCAT, "r");
    enum Error err;
    if (!fpin)
    {
        fprintf(stderr, "Failed to read random float array.\n");
        err = FILE_CANT_OPEN;
        return err;
    }

    float input[array_size];

    for (unsigned long i = 0; i < array_size; i++)
    {
        unsigned int result;
        fscanf(fpin, "%u\n", &result);
        input[i] = *(float *)&result;
    }

    fclose(fpin);

    struct timespec start, end;
    unsigned long elipse = 0;

    float m[4] = {MULTIPLIER};

    __m128 x, y = _mm_load_ps(m);

    for (unsigned long i = 0; i < array_size; i += 4)
    {
        clock_gettime(CLOCK_MONOTONIC, &start);
        x = _mm_load_ps(input[i]);
        x = _mm_mul_ps(x, y);
        clock_gettime(CLOCK_MONOTONIC, &end);
        elipse = (unsigned long)(end.tv_nsec - start.tv_nsec);
        printf("%lu\n", elipse);
    }

    return 0;
}