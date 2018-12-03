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

    float input [array_size];
    /*to do : eliminate transform cost */
    unsigned float2unsigned [array_size];    

    for (int i = 0; i < array_size; i ++) {
        fscanf(fpin, "%f\n", input[i]);
        float2unsigned[i] = *(unsigned *)&(input[i]);
    }

    fclose(fpin);


    
    
}