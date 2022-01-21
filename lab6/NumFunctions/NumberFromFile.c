
#include "../main.h"

char* NumberFromFile(char filename[], size_t* size) {
    char* number;
    FILE* file;
    char tmp;
    size_t size_tmp;
    errno_t err;

    err = FileCheck(&file, filename, "r");
    if (err == EFOPEN) {
        number = NULL;
        *size = 0;
        return number;
    }

    while (!feof(file)) {
        fscanf(file, "%c", &tmp);
        ++*size;
    }
    rewind(file);

    number = (char*)malloc(*size * sizeof(char));
    if (number == (char*)NULL) {
        exit(EXIT_FAILURE);
    }

    size_tmp = *size;
    number[*size - 1] = 0;

    for (tmp; size_tmp - 1 > 0; --size_tmp) {
        fscanf(file, "%c", &tmp);
        number[size_tmp - 2] = tmp;
    }

    fclose(file);

    return number;
}