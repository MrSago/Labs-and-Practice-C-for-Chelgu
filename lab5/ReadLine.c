
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ReadLine() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* tmp;
    char* data = (char*)malloc(alloc_length * sizeof(char));
    if (!data) {
        return ((char*)NULL);
    }

    while (1) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, (int)(alloc_length - data_length), stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        size_t new_length = alloc_length << 1;
        tmp = (char*)realloc(data, new_length);

        if (!tmp) {
            break;
        } else {
            data = tmp;
        }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    tmp = (char*)realloc(data, data_length);
    if (!tmp) {
        data = (char*)NULL;
    } else {
        data = tmp;
    }

    return (data);
}

