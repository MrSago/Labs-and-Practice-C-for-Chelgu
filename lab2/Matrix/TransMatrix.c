
#include "./../main.h"

retcode_t TransMatrix(Matrix* ptrDst, Matrix src) {
    retcode_t code;
    Matrix trans;
    size_t i, j, k;
    *ptrDst = (Matrix)NULL;

    if (src == (Matrix)NULL) {
        code = EINCORMATR;
        return code;
    }

    trans = (Matrix)malloc(sizeof(struct __matrix));
    if (trans == (Matrix)NULL) {
        code = EMALLOC;
        return code;
    }

    trans->strings = src->columns;
    trans->columns = src->strings;

    printf("Matrix %c%c(%llu x %llu):\n", -38, FILENAME_B[0], src->columns,
           src->strings);

    trans->buf = (int**)malloc(trans->strings * sizeof(int*));
    if (trans->buf == (int**)NULL) {
        free(trans);
        return EMALLOC;
    }

    for (i = 0; i < trans->strings; ++i) {
        printf("|");
        trans->buf[i] = (int*)malloc(trans->columns * sizeof(int));
        if (trans->buf[i] == (int*)NULL) {
            for (k = 0; k < i; ++k) {
                free(trans->buf[k]);
            }
            free(trans->buf);
            free(trans);
            return EMALLOC;
        }
        for (j = 0; j < trans->columns; ++j) {
            trans->buf[i][j] = src->buf[j][i];
            printf("%3d ", trans->buf[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

    *ptrDst = trans;
    return SUCCESS;
}

