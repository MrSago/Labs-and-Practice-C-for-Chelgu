
#include "./../main.h"

#define RANDOM ((rand() % 19) - 9)
#define RANGE "[-9, 9]"

retcode_t RandomMatrix(Matrix* ptrMatrix) {
    Matrix matrix;
    int err;
    size_t i, j, k;
    char tmp;
    *ptrMatrix = (Matrix)NULL;
    srand((unsigned)time(NULL));

    matrix = (Matrix)malloc(sizeof(struct __matrix));
    if (matrix == (Matrix)NULL) {
        return (EMALLOC);
    }

    while (1) {
        printf("Введите размерность квадратной матрицы: ");
        if ((err = scanf("%llu", &matrix->strings)) != 0 &&
            matrix->strings > 0) {
            for (tmp = 0;
                 (err = scanf("%c", &tmp)) == EOF || tmp != '\n';
                 /*empty*/)
                ;
            break;
        } else {
            for (tmp = 0; tmp != '\n'; scanf("%c", &tmp))
                ;
            printf("Некорректный размер матрицы!\n\n");
            continue;
        }
    }

    matrix->columns = matrix->strings;

    printf("Диапазон значений %s\nМатрица R(%llu x %llu):\n", RANGE,
           matrix->strings, matrix->columns);

    matrix->buf = (int**)malloc(matrix->strings * sizeof(int*));
    if (matrix->buf == (int**)NULL) {
        free(matrix);
        return (EMALLOC);
    }

    for (i = 0; i < matrix->strings; ++i) {
        printf("|");
        matrix->buf[i] = (int*)malloc(matrix->columns * sizeof(int));
        if (matrix->buf[i] == (int*)NULL) {
            for (k = 0; k < i; ++k) {
                free(matrix->buf[k]);
            }
            free(matrix->buf);
            free(matrix);
            return (EMALLOC);
        }
        for (j = 0; j < matrix->columns; ++j) {
            matrix->buf[i][j] = RANDOM;
            printf("%3d ", matrix->buf[i][j]);
        }
        printf("|\n");
    }

    *ptrMatrix = matrix;
    return (SUCCESS);
}

