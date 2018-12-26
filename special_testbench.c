#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "const.h"
#define POS_INF (0x7F800000)
#define NEG_INF (0xFF800000)

int main() {

    struct timespec nan_nstart, nan_nstop;
    struct timespec nan_dstart, nan_dstop;
    struct timespec inf_nstart, inf_nstop;
    struct timespec inf_dstart, inf_dstop;

    unsigned long nan_ntime = 0, nan_dtime = 0, inf_ntime = 0, inf_dtime = 0;

int trigger = 0;

    srand(time(NULL));
    for (unsigned long i = 0; i < array_size; i++) {
        unsigned int seed = 1 + rand() % 100000;
        float rand_normal_float = seed * 1.0;
        float rand_denormal_float = *(float *)&seed;
        unsigned nan_temp = POS_INF & seed;
        float rand_nan_float = *(float *)&nan_temp;

        clock_gettime(CLOCK_MONOTONIC, &nan_nstart);
        float nan_nresult = rand_normal_float * rand_nan_float;
        clock_gettime(CLOCK_MONOTONIC, &nan_nstop);
        // if (nan_nstop.tv_nsec < nan_dstart.tv_nsec) printf("i = %d, start - stop = %d", i, (int)(nan_nstart.tv_nsec - nan_nstop.tv_nsec)); 
        nan_ntime += (unsigned long)(nan_nstop.tv_nsec - nan_nstart.tv_nsec);
        if(nan_nstop.tv_nsec - nan_nstart.tv_nsec > 100) {
            printf("i = %ld, stop - start = %d\n", i, (int)(nan_nstop.tv_nsec - nan_nstart.tv_nsec)); 
        }

        if (!trigger && nan_ntime > 10000000) {
            printf("i = %ld, nan_ntime = %lu\n", i, nan_ntime);
            trigger = 1;
        }

        clock_gettime(CLOCK_MONOTONIC, &nan_dstart);
        float nan_dresult = rand_denormal_float * rand_nan_float;
        clock_gettime(CLOCK_MONOTONIC, &nan_dstop);
        nan_dtime = (unsigned long)(nan_dstop.tv_nsec - nan_dstart.tv_nsec);

        clock_gettime(CLOCK_MONOTONIC, &inf_nstart);
        float inf_nresult = rand_normal_float * POS_INF;
        clock_gettime(CLOCK_MONOTONIC, &inf_nstop);
        inf_ntime = (unsigned long)(inf_nstop.tv_nsec - inf_nstart.tv_nsec);

        clock_gettime(CLOCK_MONOTONIC, &inf_dstart);
        float inf_dresult = rand_denormal_float * POS_INF;
        clock_gettime(CLOCK_MONOTONIC, &inf_dstop);
        inf_dtime = (unsigned long)(inf_dstop.tv_nsec - inf_dstart.tv_nsec);

        printf("%lu, %lu, %lu, %lu\n", nan_ntime, nan_dtime ,inf_ntime , inf_dtime );
    }

    return 0;
}
