#include "Header.h"
#include "stdio.h"
#include "process.h"

int main(int argc, char **argv)
{
	BigNum bigNum1 = GetBigNumByStr(argv[1]); //Инициализация 1-го числа
	if (bigNum1.buf == NULL) exit(ERARG);
	BigNum bigNum2 = GetBigNumByStr(argv[2]); //Инициализация 2-го числа
	if (bigNum2.buf == NULL) exit(ERARG);

	BigNum bigResult;

	printf("First Number:\t\t");
	PrintBigNum(bigNum1); //Вывод 1-го числа
	printf("\n");

	printf("Second Number:\t\t");
	PrintBigNum(bigNum2); //Вывод 2-го числа
	printf("\n");

	//Сложение больших чисел
	printf("Addiction Result:\t");
	bigResult = AddBigNum(bigNum1, bigNum2);
	PrintBigNum(bigResult);
	printf("\n");
	FreeBigNum(&bigResult);

	//Вычитание больших чисел
	printf("Subtraction Result:\t");
	bigResult = SubBigNum(bigNum1, bigNum2);
	PrintBigNum(bigResult);
	printf("\n");
	FreeBigNum(&bigResult);

	//Умножение больших чисел
	printf("Multiplication Result:\t");
	bigResult = MulBigNum(bigNum1, bigNum2);
	PrintBigNum(bigResult);
	printf("\n");
	FreeBigNum(&bigResult);

	////Деление больших чисел
	//printf("Divition Result:\t");
	//bigResult = DivBigNum(bigNum1, bigNum2);
	//PrintBigNum(bigResult);
	//printf("\n");
	//FreeBigNum(&bigResult);


	//Очистка памяти
	FreeBigNum(&bigNum1);
	FreeBigNum(&bigNum2);
	return SUCCESS;
}