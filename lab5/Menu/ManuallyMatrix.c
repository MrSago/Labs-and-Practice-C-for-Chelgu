#include "./../main.h"

retcode_t ManuallyMatrix() {
    retcode_t code;
    Matrix matrix;
    long long det;
    clock_t start, stop;

    code = ScanMatrix(&matrix);
    if (code != SUCCESS) {
        return code;
    }

    printf("������� M(%llu x %llu):\n", matrix->strings, matrix->columns);
    PrintMatrix(matrix);

    printf("��������� ������������...");

    start = clock();
    det = DetMatrix(matrix->buf, matrix->strings);
    stop = clock();

    printf("\ndet[M] = %lli\n����� ����������: %.3f ���.\n", det,
           (stop - start) / (float)CLOCKS_PER_SEC);

    FreeMatrix(&matrix);
    return SUCCESS;
}

