#include<iostream>
#include<string.h>
using namespace std;

/*1.不假思索版，未考虑当n很大时，会超出int表示范围。*/
void PrintMaxNumofNbit1(int n)
{
	/* 考虑特殊输入，0，-1*/
	if (n <= 0)
		return;
	int max_num = 1;
	for (int i = 0; i < n; i++)
	{
		max_num *= 10;
	}
	for (int i = 1; i < max_num; i++)
		cout << i << '\t' << endl;
}

/*2.字符串模拟数字*/

bool Increment(char *num); //字符串模拟数字加法
void PrintNum(char *num);  //输出字符串数字

void PrintOneToMax2(int n)
{
	if (n <= 0)
	{
		cout << "请输入合理的数字n" << endl;
		return;
	}
	char *num = new char[n + 1];
	for (int i = 0; i < n; i++)
	{
		num[i] = '0';
	}
	num[n] = '\0';

	while (!Increment(num))
		PrintNum(num);

	delete []num;
}

bool Increment(char *num)
{
	int len = strlen(num);
	bool isOverflow = false;
	int TakeOver = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		int nSum = num[i] - '0'+ TakeOver;
		if (i == len-1)
			nSum++;

		if (nSum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
				nSum -= 10;
			TakeOver = 1;
			num[i] = '0' + nSum;
		}
		else
		{
			num[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}

void PrintNum(char *num)
{
	int len = strlen(num);
	bool isPrint = true;
	for(int i = 0; i < len; i++)
	{
		if (isPrint && num[i] != '0')
			isPrint = false;
		if (!isPrint)
			cout << num[i];
	}
	cout << '\t';
}

int main()
{
	int n1 = 0, n2 = -2, n3 = 3;
	//PrintOneToMax2(n1);
	//PrintOneToMax2(n2);
	PrintOneToMax2(n3);

	return 0;
}