
#include "main.h"

int MenuSelection() {
    int err;
    int select;
    char tmp;

    err = scanf("%d", &select);

    if (err == 0) {
        select = -1;
    }

    for (tmp = 0; tmp != 10; /*empty*/) {
        scanf("%c", &tmp);
    }

    return select;
}

