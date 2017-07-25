#include<iostream>
using namespace std;

bool Equal_double(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
	{
		return true;
	}
	else
		return false;
}

/* 指数为正的时候*/
double Power_with_unsigned_int(double base, unsigned int exponent)
{
	double res = 1.0;
	for (int i = 1; i <= exponent; i++)
	{
		res *= base;
	}
	return res;
}
double Power_with_unsigned_int_efficiently(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	//减少重复计算，2^16 = (2^8)^2 = 2^4^2^2 = 2^2^2^2^2;
	//位运算，无符号数，右移 = 除以 2， 与运算 代替取余（%2）来判断是否是奇数。
	double res = Power_with_unsigned_int_efficiently(base, exponent >> 1);
	res *= res;
	if (exponent & 0x1 == 1) //如果是奇数，再乘以一个base, %2 == 0,等于0表示是偶数；
		res *= res;
	return res;
}

/*设置全局变量来表示无效输入*/
bool g_InvalidInput = false;
double Power1(double base, int exponent)
{
	/*考虑基数为0.0的情况,定义：0的正数次幂为0，其余无效，定义为0.0*/
	if (Equal_double(base, 0.0) && exponent <= 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	else if (Equal_double(base, 0.0) && exponent > 0)
	{
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)exponent;
	cout << absExponent << endl;

	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
		cout << "absExponent = " << absExponent << endl;
	}

	double res = Power_with_unsigned_int(base, absExponent);
	/*指数部位正的时候，结果倒置*/
	if (exponent < 0)
	{
		res = 1.0 / res;
	}
	return res;
}

int main()
{
	double base = 0.0;
	int ex = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> base;
		cin >> ex;

		cout << "res = " << Power1(base, ex) << endl;
	}

	return 0;
}
