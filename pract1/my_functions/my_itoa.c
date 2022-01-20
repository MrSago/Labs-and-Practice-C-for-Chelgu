
#include "../Header.h"

void my_itoa(char** buf, int a, int p) {
    if (p < 2 || p > 36) {
        printf("Недопустимая система счисления!\n");
        return;
    } else {
        int tmp_print = a;
        int str_size = 0;
        int sign, tmp, i;

        if (a > 0) {
            sign = 0;
        } else {
            sign = -1;
            a *= -1;
            ++str_size;
        }

        for (tmp = a; tmp != 0; tmp /= p) {
            ++str_size;
        }

        *buf = (char*)malloc((str_size + 1) * sizeof(char));
        if (*buf == (char*)NULL) {
            exit(EXIT_FAILURE);
        }

        (*buf)[str_size] = 0;

        if (sign < 0) (*buf)[0] = '-';

        for (i = str_size; i > 0 - sign; --i) {
            int index = i - 1;
            int tmp = a % p;

            if (tmp < p && tmp < 0) {
                tmp *= (-1);
            }

            if (tmp >= 0 && tmp <= 9) {
                (*buf)[index] = tmp + '0';
            } else {
                (*buf)[index] = tmp - 10 + 'a';
            }

            a /= p;
        }

        printf("%d -> \"%s\"", tmp_print, (*buf));
    }
}

