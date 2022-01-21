
#include "Header.h"

char* ScanString() {
    size_t size_str = 0;
    char* str = (char*)malloc(sizeof(char));
    int c;

    while ((c = getchar()) != '\n') {
        ++size_str;
        str = (char*)realloc(str, sizeof(char) * (size_str + 1));
        *(str + size_str - 1) = c;
    }

    str[size_str] = '\0';

    return str;
}

