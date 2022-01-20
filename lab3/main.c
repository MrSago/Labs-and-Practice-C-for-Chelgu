
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define FNAME "book.txt"

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int main(int argc, char** argv, char** envp) {
    FILE* file;
    size_t str_count = 0, current_count = 0;
    size_t* chars_count;
    size_t* chars_count_s;
    size_t* pTmp;
    size_t i, j;
    char** strings;
    char tmp;

    setlocale(LC_ALL, "Rus");

    if ((file = fopen(FNAME, "r")) == (FILE*)NULL) {
        printf("Error open file to read: %s\n", FNAME);
        return -1;
    } else {
        printf("Open file success: %s\n", FNAME);
    }

    chars_count = (size_t*)malloc((str_count + 1) * sizeof(size_t));
    if (chars_count == (size_t*)NULL) {
        printf("Error allocate memory!\n");
        return -1;
    }

    while (fscanf(file, "%c", &tmp) != EOF) {
        ++current_count;

        if (tmp == '\n' || feof(file)) {
            ++current_count;
            chars_count[str_count] = current_count;
            current_count = 0;
            ++str_count;

            pTmp = (size_t*)realloc(chars_count, (str_count + 1) * sizeof(size_t));
            if (pTmp == (size_t*)NULL) {
                printf("Error allocate memory!\n");
                return -1;
            } else {
                chars_count = pTmp;
            }
        }
    }

    rewind(file);

    strings = (char**)malloc(str_count * sizeof(char*));
    if (strings == (char**)NULL) {
        printf("Error allocate memory!\n");
        return -1;
    }

    for (i = 0; i < str_count; ++i) {
        strings[i] = (char*)malloc(chars_count[i] * sizeof(char));
        if (strings[i] == (char*)NULL) {
            printf("Error allocate memory!\n");
            return -1;
        } else {
            for (j = 0; j < chars_count[i] - 1; ++j) {
                strings[i][j] = fgetc(file);
            }
            strings[i][chars_count[i] - 1] = 0;
        }
    }

    fclose(file);

    chars_count_s = (size_t*)malloc(str_count * sizeof(size_t));
    if (chars_count_s == (size_t*)NULL) {
        printf("Error allocate memory!\n");
        return -1;
    }

    for (i = 0; i < str_count; ++i) {
        chars_count_s[i] = chars_count[i];
    }

    qsort(chars_count, str_count, sizeof(size_t), compare);

    for (i = 0; i < str_count; ++i) {
        for (j = 0; j < str_count; ++j) {
            if (chars_count[i] == chars_count_s[j]) {
                printf("%s", strings[j]);
            }
        }
    }

    for (i = 0; i < str_count; ++i) {
        free(strings[i]);
    }
    free(strings);
    free(chars_count);
    free(chars_count_s);

    return 0;
}

