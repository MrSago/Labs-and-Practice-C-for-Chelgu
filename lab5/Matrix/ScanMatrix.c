
#include "./../main.h"

retcode_t ScanMatrix(Matrix* ptrMatrix) {
    Matrix matrix;
    int err;
    size_t i, j, k;
    char tmp;
    *ptrMatrix = (Matrix)NULL;

    matrix = (Matrix)malloc(sizeof(struct __matrix));
    if (matrix == (Matrix)NULL) {
        return EMALLOC;
    }

    while (1) {
        printf("������� ����������� ���������� �������: ");
        err = scanf("%llu", &matrix->strings);
        if (err != 0 && matrix->strings > 0) {
            for (tmp = 0; (err = scanf("%c", &tmp)) == EOF || tmp != '\n';
                 /*empty*/)
                ;
            break;
        } else {
            for (tmp = 0; tmp != '\n'; scanf("%c", &tmp))
                ;
            printf("������������ ������ �������!\n\n");
            continue;
        }
    }
    matrix->columns = matrix->strings;

    printf("������� �������� ������� M(%llu x %llu):\n", matrix->strings,
           matrix->columns);

    matrix->buf = (int**)malloc(matrix->strings * sizeof(int*));
    if (matrix->buf == (int**)NULL) {
        free(matrix);
        return EMALLOC;
    }

    for (i = 0; i < matrix->strings; ++i) {
        matrix->buf[i] = (int*)malloc(matrix->columns * sizeof(int));
        if (matrix->buf[i] == (int*)NULL) {
            for (k = 0; k < i; ++k) {
                free(matrix->buf[i]);
            }
            free(matrix->buf);
            free(matrix);
            return EMALLOC;
        }

        for (j = 0; j < matrix->columns; ++j) {
            printf("m[%llu][%llu] = ", (i + 1), (j + 1));
            scanf("%d", &matrix->buf[i][j]);
        }
    }

    *ptrMatrix = matrix;
    return SUCCESS;
}

