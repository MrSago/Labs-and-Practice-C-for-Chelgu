
#include <limits.h>
#include <malloc.h>

#include "../Header.h"

OUT BigNum AddBigNum(IN BigNum bigNum1, IN BigNum bigNum2) {
    const Word WORD_MAX = UINT_MAX;
    const Word WORD_MIN = 0;
    BigNum bigResult;
    BigNum bigMax, bigMin;
    unsigned char digit = FALSE;
    size_t i;

    if (CompareBigNum(bigNum1, bigNum2) == BOLSHE) {
        bigMax = bigNum1;
        bigMin = bigNum2;
    } else {
        bigMax = bigNum2;
        bigMin = bigNum1;
    }

    if (bigMax.sign == MINUS) {
        bigResult.sign = MINUS;
        bigMax.sign = PLUS;

        if (bigMin.sign == MINUS) {
            bigMin.sign = PLUS;
        } else {
            bigMin.sign = MINUS;
        }
    } else {
        bigResult.sign = PLUS;
    }

    bigResult.size = bigMax.size;

    bigResult.buf = (Word*)malloc(bigResult.size * sizeof(Word));
    if (bigResult.buf == (Word*)NULL) {
        exit(ERMALLOC);
    }

    if (bigMin.sign == MINUS) {
        for (i = 0; i < bigMax.size; ++i) {
            if (i < bigMin.size) {
                if (digit) {
                    if (bigMax.buf[i] > WORD_MIN) {
                        Word MaxTmp = bigMax.buf[i];

                        if (MaxTmp > WORD_MIN + bigMin.buf[i]) {
                            bigResult.buf[i] = MaxTmp - bigMin.buf[i];
                            digit = FALSE;
                        } else {
                            bigResult.buf[i] =
                                (WORD_MAX - bigMin.buf[i]) + 1 + MaxTmp;
                        }
                    } else {
                        bigResult.buf[i] = WORD_MAX - bigMin.buf[i];
                    }
                } else {
                    if (bigMax.buf[i] > WORD_MIN + bigMin.buf[i]) {
                        bigResult.buf[i] = bigMax.buf[i] - bigMin.buf[i];
                    } else {
                        bigResult.buf[i] =
                            (WORD_MAX - bigMin.buf[i]) + 1 + bigMax.buf[i];
                        digit = TRUE;
                    }
                }
            } else {
                if (digit) {
                    if (bigMax.buf[i] > WORD_MIN) {
                        bigResult.buf[i] = bigMax.buf[i];
                        digit = FALSE;
                    } else {
                        bigResult.buf[i] = WORD_MAX;
                    }
                } else {
                    bigResult.buf[i] = bigMax.buf[i];
                }
            }
        }
    } else {
        for (i = 0; i < bigMax.size; ++i) {
            if (i < bigMin.size) {
                if (digit) {
                    if (bigMax.buf[i] < WORD_MAX - digit) {
                        Word MaxTmp = bigMax.buf[i] + digit;
                        digit = FALSE;

                        if (MaxTmp < WORD_MAX - bigMin.buf[i]) {
                            bigResult.buf[i] = MaxTmp + bigMin.buf[i];
                        } else {
                            Word tmpMax = WORD_MAX - MaxTmp;
                            Word tmpMin = WORD_MAX - bigMin.buf[i];

                            bigResult.buf[i] =
                                WORD_MAX - (tmpMax + tmpMin + 1) + digit;
                            digit = TRUE;
                        }
                    } else {
                        bigResult.buf[i] = bigMin.buf[i];
                    }
                } else {
                    if (bigMax.buf[i] < WORD_MAX - bigMin.buf[i]) {
                        bigResult.buf[i] = bigMax.buf[i] + bigMin.buf[i];
                    } else {
                        Word tmpMax = WORD_MAX - bigMax.buf[i];
                        Word tmpMin = WORD_MAX - bigMin.buf[i];

                        bigResult.buf[i] = WORD_MAX - (tmpMax + tmpMin + 1);
                        digit = TRUE;
                    }
                }
            } else {
                if (digit) {
                    if (bigMax.buf[i] < WORD_MAX - digit) {
                        bigResult.buf[i] = bigMax.buf[i] + digit;
                        digit = FALSE;
                    } else {
                        bigResult.buf[i] = 0;
                    }
                } else {
                    bigResult.buf[i] = bigMax.buf[i];
                }
            }
        }

        if (digit) {
            Word *bigTmp = (Word*)realloc(bigResult.buf,
                                           (++bigResult.size) * sizeof(Word));
            if (bigTmp == (Word*)NULL) {
                exit(ERMALLOC);
            }

            bigResult.buf = bigTmp;
            bigResult.buf[bigResult.size - 1] = digit;
        }
    }

    if (bigResult.size == 1 && bigResult.buf[0] == 0) {
        bigResult.sign = PLUS;
    }

    return bigResult;
}

