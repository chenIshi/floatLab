#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

int main() {
    FILE *fpin = fopen(UNSIGNED_OUT_FILE_LOCAT, "r");
    enum Error err;
    if (!fpin) {
        fprintf(stderr, "Failed to read random unsigned array.\n");
        err = FILE_CANT_OPEN;
        return err;
    }

    unsigned int input [array_size];   

    for (int i = 0; i < array_size; i ++) {
        unsigned int result;
        fscanf(fpin, "%u\n", &result);
        input [i] = result;
    }

    fclose(fpin);

    for (int i = 0; i < array_size; i ++) {
        input[i] *= 2;
    }

    /* chech for accuracy */
    /*
    FILE *fpout = fopen(UNSIGNED_CHECK_FILE_LOCAT, "w");
    if (!fpout) {
        fprintf(stderr, "Failed to check unsigned result.\n");
        err = FILE_CANT_OPEN;
        return err;
    }

    for (int i = 0; i < array_size; i++) {
        fprintf(fpout, "%u\n", input[i]);
    }

    fclose(fpout);
    */
    return 0;    
    
}