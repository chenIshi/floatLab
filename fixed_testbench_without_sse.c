#include <stdio.h>
#include "const.h"

int main() {
    FILE *file = fopen(FIXED_PLOT_FILE, "r");
    enum Error e;
    if (!file) {
        printf("Read fixed plot file failed!");
        e = FILE_CANT_OPEN;
        return e;
    }

    unsigned input[array_size];
    unsigned in;

    for (unsigned i = 0;i < array_size; i++) {
        fscanf(file, "%u", &in);
        input[i] = in;
    }

    for (unsigned i = 0;i < array_size; i+=4) {
        printf("%u\n", input[i] + input[i + 1] + input[i + 2] + input[i + 3]);
    }

}