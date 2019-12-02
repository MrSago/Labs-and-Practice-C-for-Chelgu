#pragma warning(disable:4033)
#pragma warning(disable:4098)
#pragma warning(disable:4716)
#pragma warning(disable:4133)


#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>


#define INDEX_ADD_FUNCTION				0	// Сложение
#define INDEX_SUB_FUNCTION				1	// Вычитание
#define INDEX_MULT_FUNCTION				2	// Умножение
#define INDEX_DIV_FUNCTION				3	// Деление
#define INDEX_PRINT_FUNCTION			4	// Вывод
#define INDEX_INIT_FUNCTION				5	// Инициализация
#define INDEX_RNG_FUNCTION				6	// Генерация случайного числа
#define INDEX_INIT_TABLE_FUNCTION		6	// инициализация по таблице и выделение памяти
#define INDEX_ZERO_FUNCTION				7	// обнуление
#define INDEX_ONE_FUNCTION				8	// присваивание единицы


// обобщённая структура
typedef struct _OperationsType OperationsType;

// тип указателя на обобщённую функцию сложения, вычитания, умножения и деления
typedef OperationsType * (*OperationProto) (OperationsType *a, OperationsType *b);
// тип указателя на обобщённую функцию вывода
typedef void (*OperationProtoPrint) (OperationsType *a);

// Обобщенная структура
struct _OperationsType
{
	OperationProto *vtable; // указатель на массив указателей на функции
};




// Матрица с коэффициентами типа INT
typedef struct _OperationsTypeInt {
	OperationsType head;
	int value;
} OperationsTypeInt;

// Матрица с коэффициентами типа DOUBLE
typedef struct _OperationsTypeDouble {
	OperationsType head;
	double value;
} OperationsTypeDouble;




// Полиморфная функция сложения
OperationsType* Add(OperationsType *a, OperationsType *b)
{
	if (a == NULL)
		return b;

	return ((OperationProto)a->vtable[INDEX_ADD_FUNCTION])(a, b);
}

OperationsTypeInt *AddInt(OperationsTypeInt *a, OperationsTypeInt *b)
{
	OperationsTypeInt *result=(OperationsTypeInt*)malloc(sizeof(OperationsTypeInt));
	result->head = a->head;
	result->value = a->value + b->value;
	return result;
}

OperationsTypeDouble *AddDouble(OperationsTypeDouble *a, OperationsTypeDouble *b)
{
	OperationsTypeDouble *result = (OperationsTypeDouble*)malloc(sizeof(OperationsTypeDouble));
	result->head = a->head;
	result->value = a->value + b->value;
	return result;
}




// Полиморфная функция вычитания
OperationsType* Sub(OperationsType *a, OperationsType *b)
{
	return ((OperationProto)a->vtable[INDEX_SUB_FUNCTION])(a, b);
}

OperationsTypeInt *SubInt(OperationsTypeInt *a, OperationsTypeInt *b)
{
	OperationsTypeInt *result = (OperationsTypeInt*)malloc(sizeof(OperationsTypeInt));
	result->head = a->head;
	result->value = a->value - b->value;
	return result;
}

OperationsTypeDouble *SubDouble(OperationsTypeDouble *a, OperationsTypeDouble *b)
{
	OperationsTypeDouble *result = (OperationsTypeDouble*)malloc(sizeof(OperationsTypeDouble));
	result->head = a->head;
	result->value = a->value - b->value;
	return result;
}




// Полиморфная функция умножения
OperationsType* Mult(OperationsType *a, OperationsType *b)
{
	return ((OperationProto)a->vtable[INDEX_MULT_FUNCTION])(a, b);
}
OperationsTypeInt *MultInt(OperationsTypeInt *a, OperationsTypeInt *b)
{
	OperationsTypeInt *result = (OperationsTypeInt*)malloc(sizeof(OperationsTypeInt));
	result->head = a->head;
	result->value = a->value * b->value;
	return result;
}
OperationsTypeDouble *MultDouble(OperationsTypeDouble *a, OperationsTypeDouble *b)
{
	OperationsTypeDouble *result = (OperationsTypeDouble*)malloc(sizeof(OperationsTypeDouble));
	result->head = a->head;
	result->value = a->value * b->value;
	return result;
}




// Полиморфная функция деления
OperationsType* Div(OperationsType *a, OperationsType *b)
{
	return ((OperationProto)a->vtable[INDEX_DIV_FUNCTION])(a, b);
}

OperationsTypeInt *DivInt(OperationsTypeInt *a, OperationsTypeInt *b)
{
	OperationsTypeInt *result = (OperationsTypeInt*)malloc(sizeof(OperationsTypeInt));
	result->head = a->head;
	if (b->value == 0)
		result->value = 0;
	else
		result->value = a->value / b->value;
	return result;
}

OperationsTypeDouble *DivDouble(OperationsTypeDouble *a, OperationsTypeDouble *b)
{
	OperationsTypeDouble *result = (OperationsTypeDouble*)malloc(sizeof(OperationsTypeDouble));
	result->head = a->head;
	result->value = a->value / b->value;
	return result;
}




// Полиморфная функция вывода
void Print(OperationsType *a)
{
	return ((OperationProtoPrint)a->vtable[INDEX_PRINT_FUNCTION])(a);
}

void *PrintInt(OperationsTypeInt *a)
{
	printf("%4d ", a->value);
	return;
}

void *PrintDouble(OperationsTypeDouble *a)
{
	printf("%15f ", a->value);
	return;
}




// Полиморфная функция генерации случайных чисел
void Random(OperationsType *a)
{
	return ((OperationProtoPrint)a->vtable[INDEX_RNG_FUNCTION])(a);
}

void *RandomInt(OperationsTypeInt *a)
{
	a->value = rand() % 20 - 10;
	return;
}

void *RandomDouble(OperationsTypeDouble *a)
{
	double fMax = 10.0, fMin = -10.0;
	double range = (fMax - fMin);
	double div = RAND_MAX / range;
	a->value = fMin + (rand() / div);
	return;
}




// Полиморфная функция инициализации
void Init(OperationsType *a)
{
	return ((OperationProtoPrint)a->vtable[INDEX_INIT_FUNCTION])(a);
}

void *InitInt(OperationsTypeInt *a)
{
	// a->value = 0;
	Random(a);
	return;
}

void *InitDouble(OperationsTypeDouble *a)
{
	//a->value = 0.0;
	Random(a);
	return;
}




// Полиморфная функция обнуления
void Zero(OperationsType *a)
{
	return ((OperationProtoPrint)a->vtable[INDEX_ZERO_FUNCTION])(a);
}

void *ZeroInt(OperationsTypeInt *a)
{
	a->value = 0;
	return;
}

void *ZeroDouble(OperationsTypeDouble *a)
{
	a->value = 0.0;
	return;
}




// Полиморфная функция присваивания единицы
void One(OperationsType *a)
{
	return ((OperationProtoPrint)a->vtable[INDEX_ONE_FUNCTION])(a);
}

void *OneInt(OperationsTypeInt *a)
{
	a->value = 1;
	return;
}

void *OneDouble(OperationsTypeDouble *a)
{
	a->value = 1.0;
	return;
}




// массив указателей на функции, работающих с OperationsTypeInt
OperationProto vtableInt[] =
{
	(OperationProto)AddInt,
	(OperationProto)SubInt,
	(OperationProto)MultInt,
	(OperationProto)DivInt,
	(OperationProto)PrintInt,
	(OperationProto)InitInt,
	(OperationProto)RandomInt,
	(OperationProto)ZeroInt,
	(OperationProto)OneInt
};

// массив указателей на функции, работающих с OperationsTypeDouble
OperationProto vtableDouble[] =
{
	(OperationProto)AddDouble,
	(OperationProto)SubDouble,
	(OperationProto)MultDouble,
	(OperationProto)DivDouble,
	(OperationProto)PrintDouble,
	(OperationProto)InitDouble,
	(OperationProto)RandomDouble,
	(OperationProto)ZeroDouble,
	(OperationProto)OneDouble
};


//-----------------------------
//------Матричные функции------
//-----------------------------

void InitMatrix(OperationsType ***matrix, size_t rows, size_t columns)
{
	size_t i, j;
	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < columns; ++j)
		{
			Init(matrix[i][j]);
		}
	}
}



void PrintMatrix(OperationsType ***matrix, size_t rows, size_t columns)
{
	size_t i, j;
	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < columns; ++j)
		{
			Print(matrix[i][j]);
		}

		printf("\n");
	}
	return;
}



void RandomMatrix(OperationsType ***matrix, size_t rows, size_t columns)
{
	size_t i, j;
	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < columns; ++j)
		{
			Random(matrix[i][j]);
		}
	}
}



OperationsType ***AddMatrix(OperationsType ***a, OperationsType ***b, size_t rows, size_t columns)
{
	size_t i, j;

	OperationsType ***sum = (OperationsType***)malloc(sizeof(OperationsType**)*rows);

	for (i = 0; i < rows; ++i)
	{
		sum[i] = (OperationsType**)malloc(sizeof(OperationsType*)*columns);

		for (j = 0; j < columns; ++j)
		{
			sum[i][j] = Add(a[i][j], b[i][j]);
			sum[i][j]->vtable = a[i][j]->vtable;
		}
	}

	return sum;
}



OperationsType ***SubMatrix(OperationsType ***a, OperationsType ***b, size_t rows, size_t columns)
{
	size_t i, j;

	OperationsType ***sub = (OperationsType***)malloc(sizeof(OperationsType**)*rows);

	for (i = 0; i < rows; ++i)
	{
		sub[i] = (OperationsType**)malloc(sizeof(OperationsType*)*columns);

		for (j = 0; j < columns; ++j)
		{
			sub[i][j] = Sub(a[i][j], b[i][j]);
			sub[i][j]->vtable = a[i][j]->vtable;
		}
	}

	return sub;
}



OperationsType ***MultMatrix(OperationsType ***a, OperationsType ***b, size_t arows, size_t acolumns, size_t brows, size_t bcolumns)
{
	if (acolumns != brows)
	{
		printf("ERROR: Matrix has wrong sizes\n");
		return (OperationsType***)(NULL);
	}

	OperationProto *_vtable = a[0][0]->vtable;
	size_t i, j, k;

	OperationsType ***mult = (OperationsType***)malloc(sizeof(OperationsType**)*arows);

	for (i = 0; i < arows; ++i)
	{
		mult[i] = (OperationsType**)malloc(sizeof(OperationsType*)*bcolumns);

		for (j = 0; j < bcolumns; ++j)
		{
			OperationsType *tmp = 0;
			for (k = 0; k < acolumns; ++k)
			{
				tmp = Add(tmp, Mult(a[i][k], b[k][j]));
			}

			mult[i][j] = tmp;
			mult[i][j]->vtable = _vtable;
		}
	}
	return mult;
}



void GetMinor(OperationsType ***mass, OperationsType ***minor, size_t row, size_t column, size_t m)
{
	size_t offsetRow = 0, offsetCol;
	size_t i, j;

	for (i = 0; i < m - 1; ++i)
	{
		if (i == row) offsetRow = 1;
		offsetCol = 0;

		for (j = 0; j < m - 1; ++j)
		{
			if (j == column) offsetCol = 1;
			minor[i][j] = mass[i + offsetRow][j + offsetCol];
		}
	}
}


OperationsType ***InitMem(size_t r, size_t c)
{

	OperationsType ***mass = (OperationsType***)malloc(r*sizeof(OperationsType**));

	for (int i = 0; i < r; ++i)
	{
		mass[i] = (OperationsType**)malloc(sizeof(OperationsType*)*c);

		for (int j = 0; j < c; ++j)
		{
			mass[i][j] = (OperationsType*)malloc(sizeof(OperationsType));
		}
	}

	return mass;
}



OperationsType *Det(OperationsType ***a, size_t rows, size_t columns)
{
	if (rows != columns)
	{
		printf("ERROR: Matrix isn't square\n");
		return (OperationsType*)(NULL);
	}

	size_t dim = rows;
	size_t i;
	int sign = 1;
	OperationsType *determinant = 0;

	OperationsType ***minor = 0;
	minor = InitMem(dim - 1, dim - 1);

	if (dim == 1)
	{
		determinant = Add(determinant, a[0][0]);
		return determinant;
	}
	else if (dim == 2)
	{
		determinant = Add(determinant, Sub( Mult(a[0][0], a[1][1]), Mult(a[0][1],a[1][0]) ) );
		return determinant;
	}
	else if (dim > 2)
	{
		for (i = 0; i < dim; ++i)
		{
			GetMinor(a, minor, i, 0, dim);

			if (sign > 0)
			{
				determinant = Add(determinant, Mult( a[i][0], Det(minor, dim-1, dim-1) ) );
			}
			if (sign < 0)
			{
				determinant = Sub(determinant, Mult( a[i][0], Det(minor, dim-1, dim-1) ) );
			}

			sign = -sign;
		}
	}
	

	determinant->vtable = a[0][0]->vtable;

	return determinant;
}



OperationsType ***Invert(OperationsType ***a, size_t rows, size_t columns)
{
	OperationsType ***invertedMatrix = (OperationsType***)malloc(rows * sizeof(OperationsType**));
	for (size_t i = 0; i < rows; ++i)
	{
		invertedMatrix[i] = (OperationsType**)malloc(sizeof(OperationsType*)*columns);

		for (size_t j = 0; j < columns; ++j)
		{
			invertedMatrix[i][j] = (OperationsType*)malloc(sizeof(OperationsType));
		}
	}

	size_t N = rows;
	OperationsType *temp = 0;

	
	// Левая матрица в методе Жордана-Гаусса
	OperationsType ***A = (OperationsType***)malloc(rows * sizeof(OperationsType**));
	for (size_t i = 0; i < rows; ++i)
	{
		A[i] = (OperationsType**)malloc(sizeof(OperationsType*)*columns);
		for (size_t j = 0; j < columns; ++j)
		{
			A[i][j] = (OperationsType*)malloc(sizeof(OperationsType));
		}
	}
	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			A[i][j] = a[i][j];
		}
	}

	// Правая(единичная) матрица в методе Жордана-Гаусса
	OperationsType ***B = 0;
	B = InitMem(rows, columns);
	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			B[i][j]->vtable = a[0][0]->vtable;
			Zero(B[i][j]);
			if (i == j)	One(B[i][j]);
		}
	}

	for (size_t k = 0; k < N; ++k)
	{
		temp = A[k][k];
		for (size_t j = 0; j < N; ++j)
		{
			A[k][j] = Div( A[k][j], temp );
			B[k][j] = Div( B[k][j], temp );
		}

		for (size_t i = k + 1; i < N; ++i)
		{
			temp = A[i][k];

			for (size_t j = 0; j < N; ++j)
			{
				A[i][j] = Sub(A[i][j], Mult(A[k][j], temp));
				B[i][j] = Sub(B[i][j], Mult(B[k][j], temp));
			}
		}
	}

	for (int k = N - 1; k > 0; --k)
	{
		for (int i = k - 1; i >= 0; --i)
		{
			temp = A[i][k];

			for (int j = 0; j < N; ++j)
			{
				A[i][j] = Sub(A[i][j], Mult( A[k][j], temp ));
				B[i][j] = Sub(B[i][j], Mult( B[k][j], temp ));
			}
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			invertedMatrix[i][j] = B[i][j];
			invertedMatrix[i][j]->vtable = a[0][0]->vtable;
		}
	}

	return invertedMatrix;
}


void TestInt()
{
	printf("DOUBLE MATRIX TEST\n");
	size_t i;
	size_t rows = 3, cols = 3;
	OperationsType ***matrixA = (OperationsType***)malloc(sizeof(OperationsType**)*rows);
	for (i = 0; i < rows; ++i)
	{
		matrixA[i] = (OperationsType**)malloc(sizeof(OperationsType*)*cols);
		for (int j = 0; j < cols; ++j)
		{
			matrixA[i][j] = (OperationsType*)malloc(sizeof(OperationsTypeInt));
			matrixA[i][j]->vtable = vtableInt;
		}
	}

	OperationsType ***matrixB = (OperationsType***)malloc(sizeof(OperationsType**)*rows);
	for (i = 0; i < rows; ++i)
	{
		matrixB[i] = (OperationsType**)malloc(sizeof(OperationsType*)*cols);
		for (int j = 0; j < cols; ++j)
		{
			matrixB[i][j] = (OperationsType*)malloc(sizeof(OperationsTypeInt));
			matrixB[i][j]->vtable = vtableInt;
		}
	}

	OperationsType ***sum;

	OperationsType ***sub;

	OperationsType ***mult;

	OperationsType ***invertA;

	OperationsType ***invertB;

	InitMatrix(matrixA, rows, cols);
	InitMatrix(matrixB, rows, cols);

	printf("A:\n");
	PrintMatrix(matrixA, rows, cols);
	printf("B:\n");
	PrintMatrix(matrixB, rows, cols);

	sum = AddMatrix(matrixA, matrixB, rows, cols);
	printf("Sum:\n");
	PrintMatrix(sum, rows, cols);

	sub = SubMatrix(matrixA, matrixB, rows, cols);
	printf("Sub:\n");
	PrintMatrix(sub, rows, cols);

	mult = MultMatrix(matrixA, matrixB, rows, cols, rows, cols);
	printf("Mult:\n");
	PrintMatrix(mult, rows, cols);
	OperationsType *determinantA = Det(matrixA, rows, cols);
	printf("Determinant A:\n");
	Print(determinantA);
	printf("\n");
	free(determinantA);

	OperationsType *determinantB = Det(matrixB, rows, cols);
	printf("Determinant B:\n");
	Print(determinantB);
	printf("\n");
	free(determinantB);

	invertA = Invert(matrixA, rows, cols);
	printf("Inverted A:\n");
	PrintMatrix(invertA, rows, cols);
}

void TestDouble()
{
	printf("INTEGER MATRIX TEST:\n");
	size_t i, j;
	size_t rows = 3, cols = 3;
	OperationsType ***matrixA = (OperationsType***)malloc(sizeof(OperationsType**)*rows);
	for (i = 0; i < rows; ++i)
	{
		matrixA[i] = (OperationsType**)malloc(sizeof(OperationsType*)*cols);
		for (j = 0; j < cols; ++j)
		{
			matrixA[i][j] = (OperationsType*)malloc(sizeof(OperationsTypeInt));
			matrixA[i][j]->vtable = vtableDouble;
		}
	}

	OperationsType ***matrixB = (OperationsType***)malloc(sizeof(OperationsType**)*rows);
	for (i = 0; i < rows; ++i) {
		matrixB[i] = (OperationsType**)malloc(sizeof(OperationsType*)*cols);
		for (j = 0; j < cols; ++j)
		{
			matrixB[i][j] = (OperationsType*)malloc(sizeof(OperationsTypeInt));
			matrixB[i][j]->vtable = vtableDouble;
		}
	}

	OperationsType ***sum;

	OperationsType ***sub;

	OperationsType ***mult;

	OperationsType ***invertA;

	OperationsType ***invertB;

	InitMatrix(matrixA, rows, cols);
	InitMatrix(matrixB, rows, cols);

	printf("A:\n");
	PrintMatrix(matrixA, rows, cols);
	printf("B:\n");
	PrintMatrix(matrixB, rows, cols);

	sum = AddMatrix(matrixA, matrixB, rows, cols);
	printf("Sum:\n");
	PrintMatrix(sum, rows, cols);

	sub = SubMatrix(matrixA, matrixB, rows, cols);
	printf("Sub:\n");
	PrintMatrix(sub, rows, cols);

	mult = MultMatrix(matrixA, matrixB, rows, cols, rows, cols);
	printf("Mult:\n");
	PrintMatrix(mult, rows, cols);
	OperationsType *determinantA = Det(matrixA, rows, cols);
	printf("Determinant A:\n");
	Print(determinantA);
	printf("\n");
	free(determinantA);

	OperationsType *determinantB = Det(matrixB, rows, cols);
	printf("Determinant B:\n");
	Print(determinantB);
	printf("\n");
	free(determinantB);

	invertA = Invert(matrixA, rows, cols);
	printf("Inverted A:\n");
	PrintMatrix(invertA, rows, cols);
}


int main() {
	srand((unsigned)time(NULL));
	
	TestInt();
	printf("\n\n");
	TestDouble();
		
	system("pause");
	return 0;
}