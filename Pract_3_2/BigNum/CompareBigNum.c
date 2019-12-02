#include "../Header.h"

//if (bigNum1 > bigNum2) return BOLSHE;
//else if (bigNum1 == bigNum2) return RAVNO;
//else if (bigNum1 < bigNum2) return MENSHE;

char CompareBigNum(IN const BigNum bigNum1, IN const BigNum bigNum2)
{
	if (bigNum1.size > bigNum2.size)
	{
		return BOLSHE;
	}
	else if (bigNum1.size == bigNum2.size)
	{
		for (size_t i = bigNum1.size; i > 0; --i)
		{
			size_t index = i - 1;

			if (bigNum1.buf[index] > bigNum2.buf[index])
			{
				return BOLSHE;
			}
			else if (bigNum1.buf[index] < bigNum2.buf[index])
			{
				return MENSHE;
			}
		}

		return RAVNO;
	}
	else //(bigNum1.size < bigNum2.size)
	{
		return MENSHE;
	}
}