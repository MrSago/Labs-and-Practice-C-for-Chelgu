
#include "../main.h"

void PrintNumber(char* number, size_t size) {
    --size;
    while (size != 0) {
        --size;
        printf("%c", number[size]);
    }
}

