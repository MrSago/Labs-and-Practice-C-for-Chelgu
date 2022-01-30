
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Header.h"

Word my_pow(Word a, const Word n) {
    Word i;
    switch (n) {
        case 0:
            return 1;

        case 1:
            return a;

        default:
            const Word tmp = a;
            for (i = 0; i < n - 1; ++i) a *= tmp;
            return a;
    }
}

Word StringInWord(const char* str) {
    Word cur_pow = 0, result = 0, i;

    for (i = (Word)strlen(str); i > 0; --i) {
        Word index = i - 1;

        if (str[index] >= 'a') {
            result += ((Word)str[index] - 'a' + 10) * my_pow(16, cur_pow);
        } else {
            result += ((Word)str[index] - '0') * my_pow(16, cur_pow);
        }

        ++cur_pow;
    }

    return result;
}

OUT BigNum GetBigNumByStr(IN const char* str) {
    BigNum bigNum;
    bigNum.buf = (Word*)NULL;
    bigNum.size = 0;
    bigNum.sign = 0;

    size_t strSize = 0;
    char tmp[8 + 1];
    tmp[8] = 0;

    int tmpIndex = 7;
    size_t numIndex = 0;
    sign_t sign = PLUS;
    size_t i;

    if (str == (char*)NULL) {
        return bigNum;
    }

    if (sign = (str[0] == '-')) {
        if (str[1] == '0') {
            exit(ERARG);
        }
        bigNum.sign = MINUS;
    } else {
        if (str[0] == '0') {
            exit(ERARG);
        }
        bigNum.sign = PLUS;
    }

    for (i = 0 + sign; str[i] != '\0'; ++i) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'f')) {
            return bigNum;
        }

        ++strSize;

        if ((strSize % 8) == 1) {
            ++bigNum.size;
        }
    }

    bigNum.buf = (Word *)malloc(bigNum.size * sizeof(Word));
    if (bigNum.buf == (Word*)NULL) {
        exit(ERMALLOC);
    }

    for (i = strSize + sign; i > 0 + sign; --i) {
        size_t index = i - 1;
        tmp[tmpIndex--] = str[index];
        if (tmpIndex < 0) {
            bigNum.buf[numIndex++] = StringInWord(tmp);
            tmpIndex = 7;
        }
    }

    if (tmpIndex >= 0 && numIndex < bigNum.size) {
        while (tmpIndex >= 0) {
            tmp[tmpIndex--] = '0';
        }
        bigNum.buf[numIndex++] = StringInWord(tmp);
    }

    return bigNum;
}

void PrintBigNum(IN const BigNum bigNum) {
    size_t i, k;

    if (bigNum.sign == MINUS) {
        putchar('-');
    }

    for (i = bigNum.size; i > 0; --i) {
        char tmp[8 + 1];
        size_t len;
        size_t index = i - 1;

        _i64toa_s(bigNum.buf[index], tmp, 9, 16);

        if ((index + 1) < bigNum.size && (len = strlen(tmp)) < 8) {
            for (k = 8 - len; k > 0; --k) {
                putchar('0');
            }
        }

        printf("%s", tmp);
    }
}

