#include<iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;

};

bool Doestree1hastree2(BinaryTreeNode* ptree1, BinaryTreeNode* ptree2)
{
	if (ptree2 == NULL)
		return true;
	if (ptree1 == NULL)
		return false;

	if (ptree1->m_nValue != ptree2->m_nValue)
		return false;

	return (Doestree1hastree2(ptree1->m_pLeft, ptree2->m_pLeft)) && (Doestree1hastree2(ptree1->m_pRight, ptree2->m_pRight));

}


bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool isSubTree = false;
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		//前序递归遍历tree1
		if (pRoot1->m_nValue == pRoot2->m_nValue)
		{
			//判断其子结构是否相等
			isSubTree = Doestree1hastree2(pRoot1, pRoot2);
		}
		if (!isSubTree)
		{
			isSubTree = HasSubTree(pRoot1->m_pLeft, pRoot2);
		}
		if (!isSubTree)
		{
			isSubTree = HasSubTree(pRoot1->m_pRight, pRoot2);
		}
	}
	return isSubTree;
}



int main()
{

	return 0;
}