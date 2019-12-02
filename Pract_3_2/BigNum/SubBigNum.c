#include "../Header.h"


OUT BigNum SubBigNum(IN BigNum bigNum1, IN BigNum bigNum2)
{
	if (bigNum2.sign == PLUS)
	{
		bigNum2.sign = MINUS;
	}
	else
	{
		bigNum2.sign = PLUS;
	}

	return AddBigNum(bigNum1, bigNum2);
}