
#include "main.h"

char* RandomString(size_t str_size) {
    size_t i;

    char* string = (char*)malloc(str_size * sizeof(char));
    if (string == (char*)NULL) {
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < str_size - 1; ++i) {
        string[i] = (char)(-128 + (rand() % 256));
        if (string[i] == '\0' || string[i] == '	' || string[i] == '\n' ||
            string[i] == '\a' || string[i] == '\r' || string[i] == '\t') {
            --i;
            continue;
        }
    }
    string[str_size - 1] = '\0';

    return string;
}

