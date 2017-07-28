#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

bool Equal_double(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 -num2 < 0.0000001))
		return true;
	else
		return false;
}
/* 指数为正的时候*/
double Power_with_unsigned_int(double base, unsigned int exponent)
{
	double res = 1.0;
	for(unsigned int i = 1; i <= exponent; i++)
	{
		res *= base;
	}
	return res;
}

bool g_InvalidInput = false;  //设置一个全局变量表示无效输入
double Pow1(double base, int exponent)
{
	/*考虑基数为0.0的情况*/
	if (Equal_double(base, 0.0) && exponent <= 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	else if (Equal_double(base, 0.0) && exponent > 0)
	{
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}

	double res = Power_with_unsigned_int(base, absExponent);
	if (exponent < 0)
		res = 1.0 / (res);
	return res;
}


double PowerWithUnsignedExponent(double base, int exponent)
{
	if (exponent == 0)
		return 1.0;
	if (exponent == 1)
		return base;
	double res = PowerWithUnsignedExponent(base, exponent << 1);
	res *= res;
	if (exponent & 0x1 == 1)
		res *= base;
	return res;
}

int main()
{
	double base = 0;
	int ex = 0;
	//cout << Pow1(base, ex) << endl;
	//for(int i = 0 ;i < 10;i++)
	//{
		//fflush(stdin);
		scanf("%lf,%d", &base, &ex);
		double res = Pow1(base, ex);
		cout << res;
	//}
	return 0;
}