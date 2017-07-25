#include<iostream>
#include<stdio.h>
using namespace std;

void Merger(int a1[],int m,int a2[],int n)
{
	int i = m-1;
	int j = n-1;
	for (j ;j >= 0; )
	{
		if (a2[j]>=a1[i])
		{
			m++;
			for(int p = m-1;p > i+1 ; p--)
			{
				a1[p] = a1[p-1];
			}
			a1[i+1] = a2[j]; 
			j--;
		}
		else
		{
			i--;
		}
	}
}
int main()
{
	int a1[20] = {1,2,5,8,9,16,27,29,39,46};
	int a2[20] = {0,2,4,5,6,7,8,13,27};
	Merger(a1,10,a2,9);
	for(int i=0;i<19;i++)
		cout<<a1[i]<<'\t';
	cout<<endl;
	return 0;
}