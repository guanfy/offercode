#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define M 5

bool Isstackpop(const int* pPush,const int* pPop, int length)
{
	bool Ispop = false;
	stack<int> sta;
	if (pPush != NULL && pPop != NULL && length > 0)
	{
		for (int i_push = 0, j_pop = 0; i_push < length;)
		{
			sta.push(pPush[i_push++]);
			while (j_pop < length && pPop[j_pop] == sta.top())
			{
				sta.pop();
				j_pop++;
			}
			if (j_pop == length)
				Ispop = true;
		}	
	}
	return Ispop;
}




int main()
{
	int a[M] = { 1,2,3,4,5 };
	int b[M] = { 4,5,3,2,1 };
	int c[M] = { 5,4,2,1,3 };
	int d[M] = { 3,5,4,2,1 };
	cout << Isstackpop(a, b, M)<<endl;
	cout << Isstackpop(a, c, M) << endl;
	cout << Isstackpop(a, d, M) << endl;
	int a1[1] = { 1 };
	int b1[1] = { 1 };
	int c1[1] = { 2 };
	cout << Isstackpop(a1, b1, 1) << endl;
	cout << Isstackpop(a1, c1, 1) << endl;

	//cout << Isstackpop(a, d, M) << endl;


	return 0;
}
