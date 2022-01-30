
#include "main.h"

int FileCheck(FILE** file, const char filename[], const char mode[]) {
    if (((*file) = fopen(filename, mode)) == (FILE*)NULL) {
        return EFOPEN;
    } else {
        return SUCCESS;
    }
}

