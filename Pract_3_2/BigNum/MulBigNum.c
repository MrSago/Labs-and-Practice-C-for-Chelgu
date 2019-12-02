#include "../Header.h"
#include "limits.h"
#include "process.h"
#include "malloc.h"


OUT BigNum MulBigNum(IN BigNum bigNum1, IN BigNum bigNum2)
{
	const Word WORD_MAX = UINT_MAX;
	const unsigned long long WORD_BASE = (unsigned long long)WORD_MAX + 1;
	BigNum bigResult;
	BigNum bigMax, bigMin;
	BigNum *bigAdd;


	//if (bigNum1 > bigNum2)
	if (CompareBigNum(bigNum1, bigNum2) == BOLSHE)
	{
		bigMax = bigNum1;
		bigMin = bigNum2;
	}
	else //(bigNum1 < bigNum2)
	{
		bigMax = bigNum2;
		bigMin = bigNum1;
	}

	if (bigMax.sign == MINUS || bigMin.sign == MINUS)
	{
		if (bigMax.sign == MINUS && bigMin.sign == MINUS)
		{
			bigResult.sign = PLUS;
		}
		else
		{
			bigResult.sign = MINUS;
		}
	}
	else
	{
		bigResult.sign = PLUS;
	}

	bigAdd = (BigNum*)malloc(bigMin.size * sizeof(BigNum));
	if (bigAdd == NULL)
	{
		exit(ERMALLOC);
	}

	for (size_t i = 0; i < bigMin.size; ++i)
	{
		bigAdd[i].size = bigMax.size + i;
		bigAdd[i].sign = PLUS;

		bigAdd[i].buf = (Word*)malloc(bigAdd[i].size * sizeof(Word));
		if (bigAdd[i].buf == NULL)
		{
			exit(ERMALLOC);
		}

		for (size_t j = 0; j < i; ++j)
		{
			bigAdd[i].buf[j] = 0;
		}
	}

	for (size_t i = 0; i < bigMin.size; ++i)
	{
		Word digit = 0;

		for (size_t j = 0; j < bigMax.size; ++j)
		{
			unsigned long long tmp = ((unsigned long long)bigMax.buf[j] * (unsigned long long)bigMin.buf[i]) + digit;
			digit = (Word)(tmp / WORD_BASE);
			bigAdd[i].buf[j + i] = (Word)(tmp % WORD_BASE);
		}

		if (digit)
		{
			Word *bigTmp = (Word*)realloc(bigAdd[i].buf, (++bigAdd[i].size) * sizeof(Word));
			if (bigTmp == NULL)
			{
				exit(ERMALLOC);
			}

			bigAdd[i].buf = bigTmp;
			bigAdd[i].buf[bigAdd[i].size - 1] = digit;
		}
	}

	if (bigMin.size == 1)
	{
		bigResult.buf = bigAdd[0].buf;
		bigResult.size = bigAdd[0].size;
	}
	else //(bigMin.size > 1)
	{
		bigResult = AddBigNum(bigAdd[0], bigAdd[1]);

		for (size_t i = 2; i < bigMin.size; ++i)
		{
			Word *ptr = bigResult.buf;
			bigResult = AddBigNum(bigResult, bigAdd[i]);
			free(ptr);
		}

		for (size_t i = 0; i < bigMin.size; ++i)
			FreeBigNum(&bigAdd[i]);
		free(bigAdd);
	}


	return bigResult;
}