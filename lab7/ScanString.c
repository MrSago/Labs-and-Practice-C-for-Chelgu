
#include "main.h"

char* ScanString() {
    size_t index = 0;
    char tmp_char = 0;
    char* tmp_str;
    char* str;

    str = (char*)malloc(2 * sizeof(char));
    if (str == (char*)NULL) {
        exit(EXIT_FAILURE);
    }

    scanf("%c", &tmp_char);
    for (/*empty*/; tmp_char != 10; ++index) {
        str[index] = tmp_char;

        tmp_str = (char*)realloc(str, (index + 2) * sizeof(char));
        if (tmp_str == (char*)NULL) {
            exit(EXIT_FAILURE);
        }

        str = tmp_str;

        scanf("%c", &tmp_char);
    }
    str[index] = 0;

    return str;
}

