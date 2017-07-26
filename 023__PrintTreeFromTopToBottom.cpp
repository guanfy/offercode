#include<iostream>
#include<queue>
using namespace std;

struct BinaryTreeNode {
	int m_data;
	BinaryTreeNode * pLeft;
	BinaryTreeNode * pRight;
};

void PrintTreeFromTopToBottom(BinaryTreeNode *pTreeRoot)
{
	if (pTreeRoot == nullptr)
		return;
	queue<BinaryTreeNode *> que;
	que.push(pTreeRoot);

	while (!que.empty())
	{
		BinaryTreeNode *pNode = que.front();
		que.pop();
		cout << pNode->m_data;
		if (pNode->pLeft)
		{
			que.push(pNode->pLeft);
		}
		if (pNode->pRight)
		{
			que.push(pNode->pRight);
		}
	}

}

int main()
{


	return 0;
}