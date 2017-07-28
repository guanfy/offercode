#include<iostream>
#include<string.h>
using namespace std;


void ReorderOddEven(int *arr, int n)
{
	if (arr == NULL || n <= 0)
		return;
	int *p_left = arr;
	int *p_right = arr+n-1;
	while (p_left < p_right)
	{
		while (*p_left & 0x1 == 1)
			p_left++;
		while ((*p_right & 0x1 ) == 0)
			p_right--;
		if (p_left < p_right)
		{
			int temp = *p_left;
			*p_left = *p_right;
			*p_right = temp;
			p_left++;
			p_right--;
		}
	}
}

void ReorderArr(int *arr,int length)
{
	if (arr == NULL || length <= 0)
		return;
	int *p_left = arr;
	int *p_right = arr + length - 1;
	while (p_left < p_right)
	{
		while (p_left < p_right && (*p_left & 0x1) != 0)
			p_left++;
		while (p_left < p_right && (*p_right & 0x1) == 0)
			p_right--;
		if (p_left < p_right)
		{
			int temp = *p_left;
			*p_left = *p_right;
			*p_right = temp;
		}
	}
}

int main()
{
	//int a[10] = {4,1,6,2,1,5,7,9,3,6};
	int a[4] = { 2,1,2,1 };
	int	n = 4;
	ReorderOddEven(a, n);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
	}
	cout << endl;

	return 0;
}


