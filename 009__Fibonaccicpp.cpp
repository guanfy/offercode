#include<iostream>
using namespace std;

//不加思索的斐波那契亚递归算法
//时间复杂度是以n的指数的方式递增。
//直观，但是时间效率很低

int Fib1(int n)\
{
	if (n == 0 || n == 1)
		return n;
	return Fib1(n - 1) + Fib1(n - 2);
}

//从下往上计算，先计算f(2)=f(0)+f(1),保存f(3)=f(2)+f(1);
//保存前两个结果，时间复杂度为：o(n)
//循环实现，提高了时间效率

int Fib2(int n)
{
	int res[2] = { 0,1 };
	if (n < 2)
	{
		return res[n];
	}
	int pre1 = 1;
	int pre2 = 0;
	int fib = 0;
	for (int i = 2; i <= n; i++)
	{
		fib = pre1 + pre2;
		pre2 = pre1;
		pre1 = fib;
	}
	return fib;
}

/*变形题目：
一只青蛙一次可以跳上一个台阶，也可以跳上两个台阶，问青蛙跳上n个台阶共有多少种跳法？
分析：
当n = 1 时，一种跳法；
当n = 2 时，两种跳法；
当n > 2时，
第一次跳可以选择跳一个，剩下就是f(n-1)跳法；
第一次跳选择跳两个，剩下的就是f(n-2)跳法；
f(n) = f(n-1)+f(n-2);
*/

int FogJump(int n)
{
	int res[2] = { 1,2 };
	if (n <= 0)
		return -1;
	if (n < 3)
		return res[n - 1];
	int pre1 = 2;
	int pre2 = 1;
	int fogstep = 0;

	for (int i = 3; i <= n; i++)
	{
		fogstep = pre1 + pre2;
		pre2 = pre1;
		pre1 = fogstep;
	}
	return fogstep;
}

/*n级青蛙跳的高级跳法：
一次可以跳1台阶，也可以2台阶，也可以n台阶，问跳上n台阶共有多少种跳法？
当n = 1时，f(1) = 1;      2^0
当n = 2时，f(2) = 2;		  2^1
当n = 3时，f(3) = f(2)+f(1)+1;		2^2
当n = 4时，f(4) = f(3)+f(2)+f(1)+1;  2^3
...
当n = N时，f(n) = f(n-1)+f(n-2)+...+f(1)+1;   2^n-1
*/









int main()
{
	cout << "惩罚关关" << endl;
	int fib = Fib2(12);
	cout << fib << endl;

	return 0;
}