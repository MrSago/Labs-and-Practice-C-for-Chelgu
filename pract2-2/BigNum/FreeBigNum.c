
#include <malloc.h>

#include "../Header.h"

void FreeBigNum(IN BigNum *bigNum) {
    if (bigNum->buf != NULL) {
        free(bigNum->buf);
        bigNum->buf = NULL;
    }

    bigNum->size = 0;
    bigNum->sign = 0;
}

