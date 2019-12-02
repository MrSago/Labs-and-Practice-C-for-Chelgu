#include "../Header.h"
#include "limits.h"
#include "process.h"
#include "malloc.h"


OUT BigNum AddBigNum (IN BigNum bigNum1, IN BigNum bigNum2)
{
	const Word WORD_MAX = UINT_MAX;
	const Word WORD_MIN = 0;
	BigNum bigResult;
	BigNum bigMax, bigMin;
	unsigned char digit = FALSE;


	//if (bigNum1 > bigNum2)
	if (CompareBigNum (bigNum1, bigNum2) == BOLSHE)
	{
		bigMax = bigNum1;
		bigMin = bigNum2;
	}
	else //(bigNum1 < bigNum2)
	{
		bigMax = bigNum2;
		bigMin = bigNum1;
	}

	if (bigMax.sign == MINUS)
	{
		bigResult.sign = MINUS;
		bigMax.sign = PLUS;

		if (bigMin.sign == MINUS)
		{
			bigMin.sign = PLUS;
		}
		else //(bigMin.sign == PLUS)
		{
			bigMin.sign = MINUS;
		}
	}
	else //(bigMax.sign == PLUS)
	{
		bigResult.sign = PLUS;
	}

	bigResult.size = bigMax.size;

	bigResult.buf = (Word*)malloc (bigResult.size * sizeof (Word));
	if (bigResult.buf == NULL)
	{
		exit (ERMALLOC);
	}

	if (bigMin.sign == MINUS)
	{
		for (size_t i = 0; i < bigMax.size; ++i)
		{
			if (i < bigMin.size)
			{
				if (digit)
				{
					if (bigMax.buf[i] > WORD_MIN)
					{
						Word MaxTmp = bigMax.buf[i];

						if (MaxTmp > WORD_MIN + bigMin.buf[i])
						{
							bigResult.buf[i] = MaxTmp - bigMin.buf[i];
							digit = FALSE;
						}
						else // overflowing
						{
							bigResult.buf[i] = (WORD_MAX - bigMin.buf[i]) + 1 + MaxTmp;
						}
					}
					else // overflowing
					{
						bigResult.buf[i] = WORD_MAX - bigMin.buf[i];
					}
				}
				else //(!digit)
				{
					if (bigMax.buf[i] > WORD_MIN + bigMin.buf[i])
					{
						bigResult.buf[i] = bigMax.buf[i] - bigMin.buf[i];
					}
					else // overflowing
					{
						bigResult.buf[i] = (WORD_MAX - bigMin.buf[i]) + 1 + bigMax.buf[i];
						digit = TRUE;
					}
				}
			}
			else //(i >= bigMin.size)
			{
				if (digit)
				{
					if (bigMax.buf[i] > WORD_MIN)
					{
						bigResult.buf[i] = bigMax.buf[i];
						digit = FALSE;
					}
					else // overflowing
					{
						bigResult.buf[i] = WORD_MAX;
					}
				}
				else //(!digit)
				{
					bigResult.buf[i] = bigMax.buf[i];
				}
			}
		}
	}
	else //bigMin.sign != MINUS
	{
		for (size_t i = 0; i < bigMax.size; ++i)
		{
			if (i < bigMin.size)
			{
				if (digit)
				{
					if (bigMax.buf[i] < WORD_MAX - digit)
					{
						Word MaxTmp = bigMax.buf[i] + digit;
						digit = FALSE;

						if (MaxTmp < WORD_MAX - bigMin.buf[i])
						{
							bigResult.buf[i] = MaxTmp + bigMin.buf[i];
						}
						else // overflowing
						{
							Word tmpMax = WORD_MAX - MaxTmp;
							Word tmpMin = WORD_MAX - bigMin.buf[i];

							bigResult.buf[i] = WORD_MAX - (tmpMax + tmpMin + 1) + digit;
							digit = TRUE;
						}
					}
					else // overflowing
					{
						bigResult.buf[i] = bigMin.buf[i];
					}
				}
				else //(!digit)
				{
					if (bigMax.buf[i] < WORD_MAX - bigMin.buf[i])
					{
						bigResult.buf[i] = bigMax.buf[i] + bigMin.buf[i];
					}
					else // overflowing
					{
						Word tmpMax = WORD_MAX - bigMax.buf[i];
						Word tmpMin = WORD_MAX - bigMin.buf[i];

						bigResult.buf[i] = WORD_MAX - (tmpMax + tmpMin + 1);
						digit = TRUE;
					}
				}
			}
			else //(i >= bigMin.size)
			{
				if (digit)
				{
					if (bigMax.buf[i] < WORD_MAX - digit)
					{
						bigResult.buf[i] = bigMax.buf[i] + digit;
						digit = FALSE;
					}
					else // overflowing
					{
						bigResult.buf[i] = 0;
					}
				}
				else //(!digit)
				{
					bigResult.buf[i] = bigMax.buf[i];
				}
			}
		}

		if (digit)
		{
			Word *bigTmp = (Word*)realloc (bigResult.buf, (++bigResult.size) * sizeof (Word));
			if (bigTmp == NULL)
			{
				exit (ERMALLOC);
			}

			bigResult.buf = bigTmp;
			bigResult.buf[bigResult.size - 1] = digit;
		}
	}

	if (bigResult.size == 1 && bigResult.buf[0] == 0)
	{
		bigResult.sign = PLUS;
	}


	return bigResult;
}