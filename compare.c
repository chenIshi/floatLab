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

    int float_percent = 0;
    int fixed_percent = 0;


    for (int i = 0; i < ARR_SIZE; i++) {
        float float_t, fixed_t;
        fscanf(fpfloat, "%f\n", &float_t);
        fscanf(fpfixed, "%f\n", &fixed_t);
        float_percent += (int)(float_t > fixed_t);
        fixed_percent += (int)(fixed_t > float_t);
    }

    fclose(fpfloat);
    fclose(fpfixed);

    printf("float_percent = %d, fixed_percent = %d\n", float_percent, fixed_percent);

    return 0;
}

