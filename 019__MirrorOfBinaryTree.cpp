#include<iostream>
#include<stack>
using namespace std;

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void MirrorOfBinaryTreeRecursively(BinaryTreeNode *pRoot)
{
	if ((pRoot == NULL) || (pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL))
	{
		return;
	}
	BinaryTreeNode* ptemp = pRoot->m_pLeft;
	pRoot->m_pLeft = pRoot->m_pRight;
	pRoot->m_pRight = ptemp;

	if (pRoot->m_pLeft)
	{
		MirrorOfBinaryTreeRecursively(pRoot->m_pLeft);
	}
	if (pRoot->m_pRight)
	{
		MirrorOfBinaryTreeRecursively(pRoot->m_pRight);
	}
}

void MirrorOfBinaryTreeCirclely(BinaryTreeNode* pRoot)
{
	stack <BinaryTreeNode*> st;
	if (pRoot == NULL)
		return;
	st.push(pRoot);
	//如果栈不为空，仍需继续遍历
	while (!st.empty())
	{
		BinaryTreeNode* phead = st.top();
		st.pop();

		//若头结点的任意子树不为空，就需要交换
		if (phead->m_pLeft || phead->m_pRight)
		{
			BinaryTreeNode *ptemp;
			ptemp = phead->m_pLeft;
			phead->m_pLeft = phead->m_pRight;
			phead->m_pRight = ptemp;
		}
		if (phead->m_pLeft)
			st.push(phead->m_pLeft);
		if (phead->m_pRight)
			st.push(phead->m_pRight);
	}

}