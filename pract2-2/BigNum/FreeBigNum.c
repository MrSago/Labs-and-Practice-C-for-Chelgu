
#include <malloc.h>

#include "../Header.h"

void FreeBigNum(IN BigNum *bigNum) {
    if (bigNum->buf != (Word*)NULL) {
        free(bigNum->buf);
        bigNum->buf = (Word*)NULL;
    }

    bigNum->size = 0;
    bigNum->sign = 0;
}

