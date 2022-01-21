
#include "Header.h"

void HexFile() {
    FILE* file;
    char* filename;
    unsigned char tmp[1];

    printf("Введите имя файла: ");
    filename = ScanString();

    file = fopen(filename, "rb");
    if (file == (FILE*)NULL) {
        exit(EXIT_FAILURE);
    }

    free(filename);

    printf("Содержимое файла в шестнадцатиричной виде:\n");
    for (; !feof(file); /*empty*/) {
        fread(tmp, sizeof(unsigned char), 1, file);
        printf("%02X ", tmp[0]);
    }
}

