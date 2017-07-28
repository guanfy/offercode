#include<iostream>
using namespace std;

//����˼����쳲������ǵݹ��㷨
//ʱ�临�Ӷ�����n��ָ���ķ�ʽ������
//ֱ�ۣ�����ʱ��Ч�ʺܵ�

int Fib1(int n)\
{
	if (n == 0 || n == 1)
		return n;
	return Fib1(n - 1) + Fib1(n - 2);
}

//�������ϼ��㣬�ȼ���f(2)=f(0)+f(1),����f(3)=f(2)+f(1);
//����ǰ���������ʱ�临�Ӷ�Ϊ��o(n)
//ѭ��ʵ�֣������ʱ��Ч��

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

/*������Ŀ��
һֻ����һ�ο�������һ��̨�ף�Ҳ������������̨�ף�����������n��̨�׹��ж�����������
������
��n = 1 ʱ��һ��������
��n = 2 ʱ������������
��n > 2ʱ��
��һ��������ѡ����һ����ʣ�¾���f(n-1)������
��һ����ѡ����������ʣ�µľ���f(n-2)������
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

/*n���������ĸ߼�������
һ�ο�����1̨�ף�Ҳ����2̨�ף�Ҳ����n̨�ף�������n̨�׹��ж�����������
��n = 1ʱ��f(1) = 1;      2^0
��n = 2ʱ��f(2) = 2;		  2^1
��n = 3ʱ��f(3) = f(2)+f(1)+1;		2^2
��n = 4ʱ��f(4) = f(3)+f(2)+f(1)+1;  2^3
...
��n = Nʱ��f(n) = f(n-1)+f(n-2)+...+f(1)+1;   2^n-1
*/









int main()
{
	cout << "�ͷ��ع�" << endl;
	int fib = Fib2(12);
	cout << fib << endl;

	return 0;
}