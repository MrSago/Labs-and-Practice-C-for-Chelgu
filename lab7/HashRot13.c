
#include "main.h"

unsigned int HashRot13(char* str) {
    unsigned int hash = 0;
    for (; *str; str++) {
        hash += (unsigned char)(*str);
        hash -= (hash << 13) | (hash >> 19);
    }
    return hash;
}

