#include <stdio.h>
#include <stdlib.h>

#define FLOAT_IN "float_plot_data.txt"
#define FIXED_IN "fixed_plot_data.txt"
#define ARR_SIZE 100000

int main() {
    FILE *fpfloat = fopen(FLOAT_IN, "r");
    if (!fpfloat) {
        fprintf(stderr, "failed to read float input.\n");
        exit(1);
    }

    FILE *fpfixed = fopen(FIXED_IN, "r");
    if (!fpfixed) {
        fprintf(stderr, "failed to read fixed input.\n");
        fclose(fpfloat);
        exit(1);
    }

    unsigned int float_percent = 0;
    unsigned int fixed_percent = 0;

    double float_avg = 0;
    double fixed_avg = 0;

    unsigned long float_temp = 0;
    unsigned long fixed_temp = 0;

    unsigned int float_err = 0;
    unsigned int fixed_err = 0;

    for (unsigned long i = 0; i < ARR_SIZE; i++) {
        long float_t, fixed_t;
        fscanf(fpfloat, "%ld\n", &float_t);
        fscanf(fpfixed, "%ld\n", &fixed_t);

        if (float_t < 0) {
            float_t = 0;
            float_err ++;
        }

        if (fixed_t < 0) {
            fixed_t = 0;
            fixed_err ++;
        }

        float_temp += float_t;
        fixed_temp += fixed_t;
        if (i % 1000 == 0) {
/*
printf("i = %lu, float_avg = %lf, fixed_avg = %lf\n", i, float_avg, fixed_avg);
printf("float_temp = %lu, fixed_temp = %lu\n", float_temp, fixed_temp);
*/
            float_avg += (float_temp / 1000.0);
            fixed_avg += (fixed_temp / 1000.0);
            float_temp = 0;
            fixed_temp = 0;
        }
        float_percent += (float_t > fixed_t);
        fixed_percent += (fixed_t > float_t);
    }

    fclose(fpfloat);
    fclose(fpfixed);
  
    printf("float_avg = %lf, fixed_avg = %lf\n", float_avg, fixed_avg);
    printf("float_err = %d, fixed_err = %d\n", float_err, fixed_err);
    printf("float_percent = %d, fixed_percent = %d\n", float_percent, fixed_percent);

    return 0;
}

