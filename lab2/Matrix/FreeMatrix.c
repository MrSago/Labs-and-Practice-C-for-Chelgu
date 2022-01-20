
#include "./../main.h"

void FreeMatrix(Matrix* ptrMatrix) {
    size_t i;

    if (ptrMatrix != (Matrix*)NULL) {
        if (*ptrMatrix != (Matrix)NULL) {
            if ((*ptrMatrix)->buf != (int**)NULL) {
                for (i = 0; i < (*ptrMatrix)->strings; ++i) {
                    if ((*ptrMatrix)->buf[i] != (int*)NULL) {
                        free((*ptrMatrix)->buf[i]);
                    }
                }
                free((*ptrMatrix)->buf);
            }
            free(*ptrMatrix);
        }
        *ptrMatrix = (Matrix)NULL;
    }
}

