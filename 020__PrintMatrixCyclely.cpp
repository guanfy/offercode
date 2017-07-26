#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
#define M 3
#define N 4

void PrintMatrix(vector<vector<int> >matrix)
{
	if (matrix.empty())
		return;
	int m_row = matrix.size();
	int m_col = matrix[0].size();

	
}
void PrintVector(vector<vector<int> >vec)
{
	//vector迭代器输出
	for (std::vector<vector<int> >::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		vector<int> temp_vec = *iter;
		for (vector<int>::iterator ite = temp_vec.begin(); ite != temp_vec.end(); ite++)
		{
			cout << *ite << '\t';
		}
		cout << endl;
	}
	//二维数组形式输出
	//int m_row = vec.size();
	//int m_col = vec[0].size();
	//for (int i = 0; i < m_row; i++)
	//{
	//	for (int j = 0; j < m_col; j++)
	//	{
	//		cout << vec[i][j] << '\t';
	//	}
	//	cout << "\n";
	//}

}

int main()
{
	int a[M][N] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	vector<vector<int> > vec(M,vector<int>(N)); //二维vector初始化
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			vec[i][j] = a[i][j];
		}
	}

	PrintVector(vec);
	return 0;
}