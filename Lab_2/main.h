#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define FILENAME_A "A.txt"
#define FILENAME_B "B.txt"

typedef enum __retcode {
	SUCCESS,
	EFOPEN,
	EINCORMATR,
	EMALLOC
} retcode_t;

typedef struct __matrix {
	int** buf;
	size_t strings;
	size_t columns;
} *Matrix;

int my_exception(int code);

retcode_t GetMatrixFromFile(Matrix* ptrMatrix, const char* filename);
retcode_t TransMatrix(Matrix* ptrDst, Matrix src);
retcode_t MultiMatrix(Matrix* ptrRes, Matrix first, Matrix second);
void FreeMatrix(Matrix* ptrMatrix);
void PrintMatrix(Matrix matrix);

#endif //_MAIN_H
