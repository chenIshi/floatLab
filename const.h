#define FLOAT_OUT_FILE_LOCAT "rand_floatArr.txt"
#define UNSIGNED_OUT_FILE_LOCAT "rand_unsignedArr.txt"
#define array_size 10000
#define float_mode 2


enum Error {
    EXEC_SUCCESS = 0,
    FILE_CANT_OPEN,
    MEM_NOT_ALLOC,
    INSUFFICIENT_ARGC,
    WRONG_ARR_SIZE,
    WRONG_FLOAT_MODE
};

enum Mode {
    SPECIAL = 0,
    NORMALIZE,
    DENORMALIZE
};