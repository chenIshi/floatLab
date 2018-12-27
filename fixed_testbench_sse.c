#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <xmmintrin.h> //SSE
#include <emmintrin.h> //SSE2
/* Intel SIMD Documentation: https://software.intel.com/sites/landingpage/IntrinsicsGuide/#expand=9 */

#include "const.h"

int main()
{
    FILE *fpin = fopen(UNSIGNED_OUT_FILE_LOCAT, "r");
    enum Error err;
    if (!fpin)
    {
        fprintf(stderr, "Failed to read random unsigned array.\n");
        err = FILE_CANT_OPEN;
        return err;
    }

    unsigned int input[array_size];

    for (unsigned long i = 0; i < array_size; i++)
    {
        unsigned int result;
        fscanf(fpin, "%u\n", &result);
        input[i] = result;
    }

    fclose(fpin);

    struct timespec start, end;
    unsigned long elipse = 0;
    unsigned m[4] = {MULTIPLIER}; //Multiplier for SIMD
    __m128i x, y = _mm_loadu_si128((__m128i *)m);
    for (unsigned long i = 0; i < array_size; i += 4)
    {
        clock_gettime(CLOCK_MONOTONIC, &start);
        x = _mm_loadu_si128((__m128i *)&input[i]);
        x = _mm_mul_epu32(x, y);
        clock_gettime(CLOCK_MONOTONIC, &end);
        elipse = (unsigned long)(end.tv_nsec - start.tv_nsec);
        printf("%lu\n", elipse);
    }

    return 0;
}