
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int main(int argc, char** argv, char** envp) {
    FILE* file;
    char str[11];
    char bin[31];
    int num = 0;
    int sum = 0;
    int i, p, tmp;

    file = fopen(INPUT_FILE, "r");
    if (file == (FILE*)NULL) {
        printf("Can't open file to read: %s\n", INPUT_FILE);
        return 1;
    }

    for (i = 0; (str[i] = fgetc(file)) != EOF; ++i) {
        if (i + 1 > 10) {
            printf("Overflow type int!\n");
            return 2;
        }

        if (str[i] < '0' || str[i] > '9') {
            printf("It's not a number!\n");
            return 3;
        }
    }
    str[i--] = 0;
    fclose(file);

    for (p = 1; i >= 0; --i, p *= 10) {
        if ((str[i] - '0') > INT_MAX / p) {
            printf("Overflow type int!\n");
            return 2;
        }

        tmp = (str[i] - '0') * p;

        if (num <= INT_MAX - tmp) {
            num += tmp;
        } else {
            printf("Overflow type int!\n");
            return 2;
        }
    }

    for (tmp = num; tmp != 0; tmp /= 10) {
        sum += tmp % 10;
    }

    for (tmp = num, i = 0; tmp != 0; tmp /= 2) {
        bin[i++] = (char)(tmp % 2) + '0';
    }

    printf("Number from file %s: %d\n", INPUT_FILE, num);
    printf("Sum of digits: %d\n", sum);
    printf("Binary: ");
    for (tmp = 0, p = i; p > 0; --p) {
        if (tmp == 1) {
            if (p % 4 == 0) {
                putchar(' ');
            }
        } else {
            if (p % 4 != 0) {
                for (tmp = 4 - (p % 4); tmp != 0; --tmp) {
                    putchar('0');
                }
            }

            tmp = 1;
        }

        putchar(bin[p - 1]);
    }

    file = fopen(OUTPUT_FILE, "w");
    if (file == (FILE*)NULL) {
        printf("\nCan't open file to write: %s\n", OUTPUT_FILE);
        return 1;
    }

    for (tmp = 0; i > 0; --i) {
        if (tmp == 1) {
            if (i % 4 == 0) {
                fputc(' ', file);
            }
        } else {
            if (i % 4 != 0) {
                for (tmp = 4 - (i % 4); tmp != 0; --tmp) {
                    fputc('0', file);
                }
            }

            tmp = 1;
        }

        fputc(bin[i - 1], file);
    }

    fclose(file);
    printf("\nResult has written to file: %s\n", OUTPUT_FILE);

    return 0;
}

