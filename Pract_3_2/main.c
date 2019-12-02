#include "Header.h"
#include "stdio.h"
#include "process.h"

int main(int argc, char **argv)
{
	BigNum bigNum1 = GetBigNumByStr(argv[1]); //������������� 1-�� �����
	if (bigNum1.buf == NULL) exit(ERARG);
	BigNum bigNum2 = GetBigNumByStr(argv[2]); //������������� 2-�� �����
	if (bigNum2.buf == NULL) exit(ERARG);

	BigNum bigResult;

	printf("First Number:\t\t");
	PrintBigNum(bigNum1); //����� 1-�� �����
	printf("\n");

	printf("Second Number:\t\t");
	PrintBigNum(bigNum2); //����� 2-�� �����
	printf("\n");

	//�������� ������� �����
	printf("Addiction Result:\t");
	bigResult = AddBigNum(bigNum1, bigNum2);
	PrintBigNum(bigResult);
	printf("\n");
	FreeBigNum(&bigResult);

	//��������� ������� �����
	printf("Subtraction Result:\t");
	bigResult = SubBigNum(bigNum1, bigNum2);
	PrintBigNum(bigResult);
	printf("\n");
	FreeBigNum(&bigResult);

	//��������� ������� �����
	printf("Multiplication Result:\t");
	bigResult = MulBigNum(bigNum1, bigNum2);
	PrintBigNum(bigResult);
	printf("\n");
	FreeBigNum(&bigResult);

	////������� ������� �����
	//printf("Divition Result:\t");
	//bigResult = DivBigNum(bigNum1, bigNum2);
	//PrintBigNum(bigResult);
	//printf("\n");
	//FreeBigNum(&bigResult);


	//������� ������
	FreeBigNum(&bigNum1);
	FreeBigNum(&bigNum2);
	return SUCCESS;
}