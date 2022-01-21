
#include "../Header.h"

int my_pow(int a, const unsigned n);

int my_atoi(char* str, int p) {
    if (p == 0) {
        int cur_pow = 0, str_size = 0, max = 0, sign = 0, result = 0, i;

        if (str[0] == '-') sign = -1;

        for (i = 0 - sign; str[i] != 0; ++i) {
            int tmp;
            if ((str[i] < '0' || str[i] > '9') &&
                (str[i] < 'a' || str[i] > 'z')) {
                printf("Недопустимое число!\n");
                return 0;
            } else if (str[i] >= 'a') {
                tmp = (str[i] - 'a' + 10) + 1;
            } else if (str[i] == ' ') {
                continue;
            } else {
                tmp = (str[i] - '0') + 1;
            }

            if (tmp > max) {
                max = tmp;
                if (max < 2 || max > 36) {
                    printf("Недопустимое число!\n");
                    return 0;
                }
            }

            ++str_size;
        }

        printf("Возможная система счистления: %d\n", max);

        for (i = str_size - sign; i > 0 - sign; --i) {
            int index = i - 1;

            if (str[index] >= 'a') {
                if ((str[index] - 'a' + 10) <= INT_MAX / my_pow(max, cur_pow)) {
                    result += (str[index] - 'a' + 10) * my_pow(max, cur_pow);
                } else {
                    result = INT_MAX;
                    break;
                }
            } else if (str[i] == ' ') {
                ++cur_pow;
                --i;
                continue;
            } else {
                if ((str[index] - '0') <= INT_MAX / my_pow(max, cur_pow)) {
                    result += (str[index] - '0') * my_pow(max, cur_pow);
                } else {
                    result = INT_MAX;
                    break;
                }
            }

            ++cur_pow;
        }

        if (sign == 0)
            return result;
        else
            return result * sign;
    } else if (p >= 2 && p <= 36) {
        int cur_pow = 0, str_size = 0, max = 0, sign = 0, result = 0, i;

        if (str[0] == '-') sign = -1;

        for (i = 0 - sign; str[i] != 0; ++i) {
            int tmp;

            if ((str[i] < '0' || str[i] > '9') &&
                (str[i] < 'a' || str[i] > 'z')) {
                printf("Недопустимое число!\n");
                return 0;
            } else if (str[i] >= 'a') {
                tmp = (str[i] - 'a' + 10) + 1;
            } else if (str[i] == ' ') {
                continue;
            } else {
                tmp = (str[i] - '0') + 1;
            }

            if (tmp > max) {
                max = tmp;

                if (max < 2 || max > 36) {
                    printf("Недопустимое число!\n");
                    return 0;
                }
            }

            ++str_size;
        }

        if (max > p) {
            printf("Недопустимое значние системы счистления!\n");
            return 0;
        }

        for (i = str_size - sign; i > 0 - sign; --i) {
            int index = i - 1;

            if (str[index] >= 'a') {
                if ((str[index] - 'a' + 10) <= INT_MAX / my_pow(p, cur_pow)) {
                    result += (str[index] - 'a' + 10) * my_pow(p, cur_pow);
                } else {
                    result = INT_MAX;
                    break;
                }
            } else if (str[index] == ' ') {
                ++cur_pow;
                --i;
                continue;
            } else {
                int power = my_pow(p, cur_pow);

                if (power == 0) {
                    result = INT_MAX;
                    break;
                }

                if ((str[index] - '0') <= INT_MAX / power) {
                    result += (str[index] - '0') * my_pow(p, cur_pow);
                } else {
                    result = INT_MAX;
                    break;
                }
            }

            ++cur_pow;
        }

        if (sign == 0)
            return result;
        else
            return result * sign;
    } else {
        printf("Недопустимое значние системы счистления!\n");
        return 0;
    }
}

