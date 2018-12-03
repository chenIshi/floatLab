#define FLOAT_OUT_FILE_LOCAT "rand_floatArr.txt"
#define FLOAT_CHECK_FILE_LOCAT "float_check.txt"
#define UNSIGNED_OUT_FILE_LOCAT "rand_unsignedArr.txt"
#define UNSIGNED_CHECK_FILE_LOCAT "unsigned_check.txt"

#define array_size 10000
#define float_mode 1

#define MULTIPLIER 2


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