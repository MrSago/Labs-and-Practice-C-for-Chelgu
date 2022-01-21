
#include "../main.h"

char* CopyNumbers(char* number, size_t size) {
    char* number_new = malloc(size * sizeof(char));
    size_t i;

    for (i = 0; i < size; ++i) {
        number_new[i] = number[i];
    }

    return number_new;
}

