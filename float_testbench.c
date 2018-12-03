#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        fscanf(fpin, "%f\n", input[i]);
    }

    fclose(fpin);

    for (int i = 0; i < array_size; i ++) {
        input[i] *= 2;
    }

    return 0;
    
}