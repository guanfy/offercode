#include<iostream>
#include<stack>
using namespace std;

bool IsPopOrder(const int *pPush, const int *pPop, int nlength)
{
	bool ispop = false;
	if (pPush == nullptr || pPop == nullptr || nlength <= 0)
	{
		return ispop;
	}
	stack<int> stk;
	int i, j;
	
	for (i = 0,j = 0; i < nlength,j < nlength;)
	{
		if (i == 0)
		{
			stk.push(pPush[i]);
		}
			
		if (stk.top() == pPop[j])
		{
			stk.pop();
			j++;
		}
		else
		{
			i++;
			if (i < nlength)
			{
				stk.push(pPush[i]);
			}
			else {
				break;
			}
		}
	}
	if (j == nlength)
	{
		ispop = true;
	}
	return ispop;
}

int main()
{
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 4,5,3,2,1 };
	int c[5] = { 4,1,3,5,2 };
	bool is = IsPopOrder(a, b, 5);
	cout << is << endl;
	is = IsPopOrder(a, c, 5);
	cout << is << endl;



	//int a[1] = { 1 };
	//int b[1] = { 1 };
	//int c[1] = { 2 };

	//bool is = IsPopOrder(a, b, 1);
	//cout << is << endl;
	//is = IsPopOrder(a, c, 1);
	//cout << is << endl;
	return 0;
}