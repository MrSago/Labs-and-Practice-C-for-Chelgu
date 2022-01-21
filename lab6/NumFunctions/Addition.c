
#include "../main.h"

char* Addition(char* number_min, char* number_max, size_t size_min,
               size_t size_max, size_t* size_res) {
    int k = 0;
    char* number_res = CopyNumbers(number_max, size_max);
    size_t i;

    for (i = 0; i < size_max - 1; ++i) {
        if (i < size_min - 1) {
            number_res[i] = ((number_max[i] + number_min[i]) - 48) + k;

            if (number_res[i] > 57) {
                k = 1;
                number_res[i] = ((number_res[i] - 48) % 10) + 48;
            } else {
                k = 0;
            }
        } else {
            if (number_res[i] < 48) {
                number_res[i] = 48;
            }

            number_res[i] = number_max[i] + k;

            if (number_res[i] > 57) {
                k = 1;
                number_res[i] = ((number_res[i] - 48) % 10) + 48;
            } else {
                if ((number_res[i] > 47) && (number_res[i] < 58)) {
                    k = 0;
                }
            }
        }
    }

    if (k == 1) {
        ++size_max;

        number_res = (char*)realloc(number_res, size_max * sizeof(char));
        if (number_res == NULL) {
            exit(EXIT_FAILURE);
        }

        number_res[size_max - 2] = 49;
        number_res[size_max - 1] = 0;

        *size_res = size_max;
    } else {
        *size_res = size_max;
    }

    return number_res;
}

