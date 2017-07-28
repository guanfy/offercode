#include<iostream>
#include<string.h>
using namespace std;

/*×Ö·û´®´úÌæint*/
bool Increase(char *num);
void PrintNum(char *num);

void PrintOnetoMax(int n)
{
	if (n <= 0)
	{
		return;
	}
	char *number = new char[n + 1];
	for (int i = 0; i < n; i++)
	{
		number[i] = '0';
	}
	number[n] = '\0';
	while (!Increase(number))
	{
		PrintNum(number);
	}
}

bool Increase(char *num) {
	int isOverflow = false;
	int len = strlen(num);
	int TakeOver = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		int nSum = num[i] - '0' + TakeOver;
		if (i == len - 1)
		{
			nSum++;
		}

		if (nSum >= 10)
		{
			if (i == 0)
			{
				isOverflow = true;
			}
			else
			{
				TakeOver = 1;
				nSum -= 10;
				num[i] = nSum + '0';
			}
		}
		else
		{
			num[i] = nSum + '0';
			break;
		}
	}
	return isOverflow;
}

void PrintNum(char *num)
{
	bool isBegin0 = true;
	int len = strlen(num);
	for (int i = 0; i < len; i++)
	{
		if (isBegin0 && num[i] != '0')
		{
			isBegin0 = false;
		}
		if (!isBegin0)
		{
			cout << num[i];
		}
	}
	cout << " ";
}

//µÝ¹éÐ´·¨
void PrintOneToMax_Re(char *num, int nbit,int n)
{
	if (nbit == n)
	{
		PrintNum(num);
		//getchar();
		return;
	}
	for (char c = '0'; c <= '9'; c++)
	{
		num[nbit] = c;
		PrintOneToMax_Re(num, nbit+1,n);
	}
}

void PrintOneToMax2(int n)
{
	char *number = new char[n + 1];
	number[n] = '\0';
	PrintOneToMax_Re(number, 0,n);
}



int main()
{
	int n = 3;
	PrintOneToMax2(3);

	return 0;
}