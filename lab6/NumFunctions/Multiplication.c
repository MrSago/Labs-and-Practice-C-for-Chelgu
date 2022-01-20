
#include "../main.h"

char* Multiplication(char* number_min, char* number_max, size_t size_min,
                     size_t size_max, size_t* size_res) {
    long long k = 0;
    char* number_res, * number_tmp;
    size_t i;
    long long j;
    *size_res = size_max;

    number_res = CopyNumbers(number_max, size_max);
    number_tmp = number_res;

    for (i = 0; i < size_min - 1; ++i) {
        static long long r = 1;
        r *= 10;

        k = (number_min[i] - 48) * r;
        if (k == 0) {
            continue;
        }

        static int s = 1;
        for (j = 0 + s; j < k; ++j) {
            number_tmp = number_res;
            number_res = Addition(number_max, number_res, size_max, *size_res,
                                  &*size_res);
            free(number_tmp);
        }
        s = 0;
    }

    return number_res;
}

