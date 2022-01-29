
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* FNAME = "ASCII.txt";
    FILE* file;
    int i;

    printf("Full ASCII table:\n");

    file = fopen(FNAME, "w");
    if (file != (FILE*)NULL) {
        fprintf(file, "Full ASCII table:\n");

        for (i = CHAR_MIN; i <= CHAR_MAX; ++i) {
            printf("Symbol with num:	%d = '%c'\n", i, (char)i);
            fprintf(file, "Symbol with num:	%d = '%c'\n", i, (char)i);
        }

        printf("Result has written to file: ASCII.txt\n");
        fclose(file);
    } else {
        for (i = CHAR_MIN; i <= CHAR_MAX; ++i) {
            printf("Symbol with num : %d = '%c'\n", i, (char)i);
        }

        printf("Can't write result in file!\n");
    }

    return 0;
}

