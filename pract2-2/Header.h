
#ifndef HEADER_H
#define HEADER_H

#include "stdint.h"

typedef unsigned int Word;
typedef unsigned char sign_t;

typedef struct __bignum {
    Word* buf;
    size_t size;
    sign_t sign;
} BigNum;

#define IN
#define OUT

#define ERMALLOC (-1)
#define ERARG (-2)
#define SUCCESS (0)

#define HEX (16)
#define DEC (10)

#define BOLSHE (1)
#define RAVNO (0)
#define MENSHE (-1)

#define PLUS (0)
#define MINUS (1)

#define TRUE (1)
#define FALSE (0)

OUT BigNum GetBigNumByStr(IN const char* str);
void PrintBigNum(IN const BigNum bigNum);
void FreeBigNum(IN BigNum* bigNum);
char CompareBigNum(IN const BigNum bigNum1, IN const BigNum bigNum2);

OUT BigNum AddBigNum(IN BigNum bigNum1, IN BigNum bigNum2);
OUT BigNum SubBigNum(IN BigNum bigNum1, IN BigNum bigNum2);
OUT BigNum MulBigNum(IN BigNum bigNum1, IN BigNum bigNum2);
OUT BigNum DivBigNum(IN BigNum bigNum1, IN BigNum bigNum2);

#endif

