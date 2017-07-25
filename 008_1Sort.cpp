#include<iostream>
using namespace std;

//冒泡排序
void Bubble(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0;j < n-1-i; j++)
		{
			if (a[j]>a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

//选择排序
void Selectsort(int a[], int n)
{
	for (int i = 0; i < n-1 ; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			int tmp = a[i];
			a[i] = a[min_index];
			a[min_index] = tmp;
		}
	}
}

//插入排序
void InsertSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int value = a[i];
		int j = i - 1;
		while (j >= 0)
		{
			if (value<a[j])
			{
				a[j + 1] = a[j];
				j--;
			}
			else
			{
				break;
			}
		}
		a[j + 1] = value;
	}
}

//快速排序

void QuickSort(int a[], int left, int right)
{
	if (left < right)
	{
		int i = left, j = right;
		int value=a[left];
		while (i < j)
		{
			while (i<j && a[j]>=value)
				j--;
			if (i<j)
				a[i++] = a[j];
			while (i < j && a[i] <= value)
				i++;
			if (i<j)
				a[j--] = a[i];
		}
		a[i] = value;
		QuickSort(a, left, i-1);
		QuickSort(a, i + 1, right);

	}
}


//归并排序

//堆排序
/*
建立一个堆，
调整堆为最大堆，最小堆
排序
*/


void HeapSort(int a[], int n)
{
	int i;
	BuildHeap(a, n);
	for (i = n - 1; i >= 0; i--)
		HeapAjust(a, 0, i);
}

void Print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

}



int main()
{
	int n = 10;
	int a[] = { 23, 3, 67, 0, 8,87, 5, 56, 6, 13 };
	//Bubble(a, n);
	//Selectsort(a, n);
	//InsertSort(a, n);
	QuickSort(a, 0, n-1);
	Print(a, n);
	return 0;
}