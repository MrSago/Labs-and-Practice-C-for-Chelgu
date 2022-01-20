
#include "./../main.h"

retcode_t FileMatrix() {
    retcode_t code;
    Matrix matrix;
    long long det;
    clock_t start, stop;
    char* filename;

    printf("������� ��� �����: ");
    filename = ReadLine();

    code = GetMatrixFromFile(&matrix, filename);
    if (code != SUCCESS) {
        free(filename);
        return code;
    }

    if (matrix->strings != matrix->columns) {
        printf("������� �� ����������!\n");
        FreeMatrix(&matrix);
        free(filename);
        return EINCORMATR;
    }
    printf("��������� ������������...");

    start = clock();
    det = DetMatrix(matrix->buf, matrix->strings);
    stop = clock();

    printf("\ndet[%c] = %lli\n����� ����������: %.3f ���.\n", filename[0], det,
           (stop - start) / (float)CLOCKS_PER_SEC);

    FreeMatrix(&matrix);
    free(filename);

    return SUCCESS;
}

