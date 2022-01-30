
#ifndef _MAIN_H
#define _MAIN_H

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum __retcode { SUCCESS, EFOPEN, EMALLOC, EINCORMATR } retcode_t;

typedef struct __matrix {
    int** buf;
    size_t strings;
    size_t columns;
} *Matrix;

/*Menu Functions*/
retcode_t ManuallyMatrix();
retcode_t FileMatrix();
retcode_t GenRndMatrix();

/*Matrix Functions*/
retcode_t ScanMatrix(Matrix* ptrMatrix);
retcode_t GetMatrixFromFile(Matrix* ptrMatrix, const char* filename);
retcode_t RandomMatrix(Matrix* ptrMatrix);
long long DetMatrix(int** matrix, const size_t size);
void FreeMatrix(Matrix* matrix);
void PrintMatrix(Matrix matrix);

/*Other Functions*/
int my_exception(int code);
char* ReadLine();

#endif

