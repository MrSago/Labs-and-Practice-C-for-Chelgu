
#include <stdio.h>

int my_exception(int code) {
    printf("Program call exception with code: %d\n", code);
    return code;
}

