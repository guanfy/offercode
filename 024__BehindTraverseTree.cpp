#include<iostream>
using namespace std;
/*
��Ŀ�� ����ĳ�������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
*/

struct BinaryTreeNode {
	int m_data;
	BinaryTreeNode *pLeft;
	BinaryTreeNode *pRight;
};

bool IsBehindTraverseSequence(int *str,int nlength)
{
	if (str == nullptr || nlength <= 0)
		return false;
	int root = str[nlength - 1];
	int i_left = 0;
	while (str[i_left] < root && i_left < nlength - 1)
	{
		i_left++;
	}
	int i_right = i_left;
	//�����������������ȸ��ڵ�С�ģ�˵��ʧ���ˡ�
	for (; i_right < nlength - 1; i_right++)
	{
		if (str[i_right] < root)
		{
			return false;
		}
	}
	//�ж�������
	bool left = true;
	if (i_left > 0)
	{
		left = IsBehindTraverseSequence(str, i_left);
	}
	bool right = true;
	if (i_left < nlength - 1)
	{
		right = IsBehindTraverseSequence(str + i_left, nlength - i_left - 1);
	}
	return (left && right);

}

int main()
{
	int str[6] = { 1,7,4,6,5,8 };
	cout << IsBehindTraverseSequence(str, 6) << endl;
	int str1[7] = { 5,7,6,9,11,10,8 };
	cout << IsBehindTraverseSequence(str1, 7) << endl;
	int str2[5] = { 5,4,3,2,1 };
	cout << IsBehindTraverseSequence(str2, 5) << endl;
	int str3[5] = { 5,6,7,8,9 };
	cout << IsBehindTraverseSequence(str3, 5) << endl;
	int str4[1] = { 1 };
	cout << IsBehindTraverseSequence(str4, 1) << endl;
	int str5[5] = {5,1,3,2,4};
	cout << IsBehindTraverseSequence(str5, 5) << endl;

	return 0;
}