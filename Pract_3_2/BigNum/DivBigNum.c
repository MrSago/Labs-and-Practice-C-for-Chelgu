#include "../Header.h"
#include "limits.h"
#include "process.h"
#include "malloc.h"

OUT BigNum CopyBigNum (IN BigNum bigNum);
OUT BigNum Otsech (IN BigNum *bigNum1, IN BigNum bigNum2);
Word Perebor (IN BigNum Del, IN BigNum bigNum);

void LevelUp (IN BigNum *bigNum);
OUT BigNum MulBigNumWord (IN BigNum bigNum, Word n, char flag);
void AddDivBigNum(IN BigNum *bigNum);
void SubDivBigNum(IN BigNum *bigNum1, IN BigNum *bigNum2);

OUT BigNum DivBigNum(IN BigNum bigNum1, IN BigNum bigNum2)
{
	BigNum bigResult;
	bigResult.buf = NULL;
	BigNum bigCurValue;
	char cmp;
	
	/*bigResult.buf = (Word*)malloc(sizeof (Word));
	bigResult.buf[0] = 1;
	bigResult.size = 1;

	if (bigNum1.sign == MINUS || bigNum2.sign == MINUS)
	{
		if (bigNum1.sign == MINUS && bigNum2.sign == MINUS)
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

	switch (CompareBigNum(bigNum1, bigNum2))
	{
	case RAVNO:
		return bigResult;

	case MENSHE:
		bigResult.buf[0] = 0;
		bigResult.sign = PLUS;
		return bigResult;
	}

	bigNum1.sign = PLUS;
	bigNum2.sign = PLUS;

	bigCurValue.buf = (Word*)malloc(sizeof(Word));
	bigCurValue.buf[0] = 0;
	bigCurValue.size = 1;
	bigCurValue.sign = PLUS;

	for (size_t i = bigNum1.size - 1; i >= 0; --i)
	{
		LevelUp(&bigCurValue);
		bigCurValue.buf[0] = bigNum1.buf[i];

		unsigned long long x = 0, l = 0;
		unsigned long long r = UINT_MAX; ++r;

		while (l <= r)
		{
			unsigned long long m = ((unsigned long long)l + r) >> 1;
			BigNum cur = MulBigNumWord (bigNum2, m , 0);

			cmp = CompareBigNum (cur, bigCurValue);
			if (cmp == MENSHE || cmp == RAVNO)
			{
				x = m;
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}

			FreeBigNum(&cur);
		}

		bigResult.buf[i] = (Word)x;
		bigCurValue = SubBigNum(bigCurValue, MulBigNumWord(bigNum2, x, 1));
	}*/

	




	//BigNum Rev = CopyBigNum(bigNum1);

	//while (bigNum1.size >= bigNum2.size)
	//{
	//	BigNum Del = Otsech(&Rev, bigNum2);

	//	if (CompareBigNum(Del, bigNum2) == MENSHE)
	//	{
	//		Word *tmp = realloc(Del.buf, sizeof(Word) * (++Del.size));
	//		if (tmp == NULL)
	//		{
	//			exit(ERMALLOC);
	//		}
	//		Del.buf[Del.size - 1] = Rev.buf[Rev.size - 1];
	//	}

	//	Word *tmp = (Word*)realloc(bigResult.buf, sizeof(Word) * (++bigResult.size));
	//	if (tmp == NULL)
	//	{
	//		exit(ERMALLOC);
	//	}
	//	bigResult.buf = tmp;
	//	bigResult.buf[bigResult.size - 1] = Perebor(Del, bigNum2);
	//}


	return bigResult;
}

OUT BigNum MulBigNumWord (IN BigNum bigNum, Word n, char flag)
{
	const Word WORD_MAX = UINT_MAX;
	const unsigned long long WORD_BASE = (unsigned long long)WORD_MAX + 1;
	Word digit = 0;
	BigNum bigRes;
	bigRes.buf = (Word*)malloc(sizeof(Word) * bigNum.size);
	bigRes.size = bigNum.size;
	bigRes.sign = PLUS;

	for (size_t i = 0; i < bigNum.size; ++i)
	{
		unsigned long long tmp = ((unsigned long long)bigNum.buf[i] * (unsigned long long)n) + digit;
		bigRes.buf[i] = (Word)(tmp % WORD_BASE);
		digit = (Word)(tmp / WORD_BASE);
	}

	if (digit)
	{
		bigRes.buf = (Word*)realloc (bigRes.buf, (++bigRes.size) * sizeof (Word));
		bigRes.buf[bigRes.size - 1] = digit;
	}

	//if (flag) FreeBigNum(&bigNum);

	return bigRes;
}

void LevelUp(IN BigNum *bigNum)
{
	Word *res = (Word*)malloc(sizeof(Word) * (++bigNum->size));
	for (size_t i = 1; i < bigNum->size; ++i)
		res[i] = bigNum->buf[i];
	res[0] = 0;
	free(bigNum->buf);
	bigNum->buf = res;
}




OUT BigNum CopyBigNum(IN BigNum bigNum)
{
	BigNum res;
	res.buf = (Word*)malloc(sizeof(Word) * bigNum.size);
	if (res.buf == NULL)
	{
		exit (ERMALLOC);
	}
	res.size = bigNum.size;
	res.sign = bigNum.sign;

	for (size_t i = 0; i < bigNum.size; ++i)
		res.buf[i] = bigNum.buf[i];

	return res;
}

OUT BigNum Otsech(IN BigNum *bigNum1, IN BigNum bigNum2)
{
	BigNum res;

	res.size = bigNum2.size;
	res.sign = PLUS;
	res.buf = (Word*)malloc(sizeof(Word) * res.size);
	if (res.buf == NULL)
	{
		exit(ERMALLOC);
	}

	for (size_t i = 0; i < bigNum2.size; ++i)
		res.buf[bigNum2.size - 1 - i] = bigNum1->buf[bigNum1->size - 1 - i];

	Word *rev = (Word*)malloc(sizeof(Word) * (bigNum1->size - bigNum2.size));
	if (rev == NULL)
	{
		exit(ERMALLOC);
	}

	for (size_t i = 0; i < bigNum1->size - bigNum2.size; ++i)
		rev[i] = bigNum1->buf[i];

	free(bigNum1->buf);
	bigNum1->buf = rev;
	bigNum1->size -= bigNum2.size;

	return res;
}

Word Perebor (IN BigNum Del, IN BigNum bigNum)
{
	Word Res = 0;
	char cmp;
	BigNum bigRes = CopyBigNum(Del);
	
	while (1)
	{
		bigRes = SubBigNum(bigRes, bigNum);
		cmp = CompareBigNum(bigRes, bigNum);
		if (cmp == BOLSHE)
		{
			++Res;
		}
		else
		{
			break;
		}
	}

	return Res;
}








void AddDivBigNum(IN BigNum *bigNum)
{
	for (size_t i = 0; i < bigNum->size; ++i)
	{
		if (bigNum->buf[i] != UINT_MAX)
		{
			++bigNum->buf[i];
			return;
		}
	}

	Word *tmp = (Word*)realloc(bigNum->buf, (++bigNum->size) * sizeof(Word));
	if (tmp == NULL)
	{
		exit(ERMALLOC);
	}
	
	bigNum->buf = tmp;
	bigNum->buf[bigNum->size - 1] = 1;

	for (size_t i = 0; i < bigNum->size - 1; ++i)
	{
		bigNum->buf[i] = 0;
	}
}
void SubDivBigNum(IN BigNum *bigNum1, IN BigNum *bigNum2)
{
	const Word WORD_MAX = UINT_MAX;
	unsigned char digit = FALSE;

	for (size_t i = 0; i < bigNum1->size; ++i)
	{
		if (i < bigNum2->size)
		{
			if (digit)
			{
				if (bigNum1->buf[i] < digit)
				{
					bigNum1->buf[i] = WORD_MAX - bigNum2->buf[i];
				}
				else
				{
					Word tmp = bigNum1->buf[i] - digit;
					digit = FALSE;

					if (tmp < bigNum2->buf[i])
					{
						bigNum1->buf[i] = WORD_MAX - bigNum2->buf[i] + tmp + 1;
						digit = TRUE;
					}
					else
					{
						bigNum1->buf[i] = tmp - bigNum2->buf[i];
					}
				}
			}
			else //(!digit)
			{
				if (bigNum1->buf[i] < bigNum2->buf[i])
				{
					bigNum1->buf[i] = WORD_MAX - bigNum2->buf[i] + bigNum1->buf[i] + 1;
					digit = TRUE;
				}
				else
				{
					bigNum1->buf[i] = bigNum1->buf[i] - bigNum2->buf[i];
				}
			}
		}
		else //(i >= bigMin.size)
		{
			if (digit)
			{
				if (bigNum1->buf[i] < digit)
				{
					bigNum1->buf[i] = WORD_MAX;
				}
				else
				{
					bigNum1->buf[i] = bigNum1->buf[i] - digit;
					digit = FALSE;
				}
			}
			else //(!digit)
			{
				bigNum1->buf[i] = bigNum1->buf[i];
			}
		}
	}
}