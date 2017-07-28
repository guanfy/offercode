#include<iostream>
using namespace std;

int numberof1(int n)
{
	int count = 0;
	int *p;
	while (n)
	{
		++count;
		n = n & (n - 1);
	}
	return count;
}

union I{
	int n;
};

int main()
{
	long long n = 0xffffffff;

	cout << (unsigned int)n << endl;
	return 0;
}