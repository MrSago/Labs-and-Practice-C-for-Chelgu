
#include "Header.h"

errno_t FileCheck(FILE** file, const char filename[], const char mode[]) {
    if (((*file) = fopen(filename, mode)) == NULL) {
        return EFOPEN;
    } else {
        return SUCCESS;
    }
}

