#include<iostream>
#include<vector>
using namespace std;

//typedef ��C���Ե�һ�ֹؼ��֣����ã�Ϊһ���������Ͷ���һ�������֡�
typedef struct TreeNode{
	int val;
	struct TreeNode *pLeft;
	struct TreeNode *pRight;
	TreeNode(int x) :val(x), pLeft(NULL), pRight(NULL){}
}Bitree;


Bitree* reConstructBinaryTree(int pre[], int startpre, int endpre, int in[], int startin, int endin)
{
	//�����������������ĳ��������
	if (endpre - startpre != endin - startin)
		return NULL;
	if (startpre > endpre)
		return NULL;
	//��������ĵ�һ���ڵ�Ϊ���ڵ�
	Bitree* tree = new Bitree(pre[startpre]);

	//���ֻ��һ��Ԫ��ʱ������
	if (startpre == endpre)
		return tree;

	//���������Ҹ��ڵ�
	int index, length;
	for (index = startin; index <= endin; index++)
	{
		if (in[index] == pre[startpre]) break;
	}

	//��δ�ҵ������ؿ�
	if (index > endin) return NULL;

	//�����������ݹ�
	if (index > startin)
	{
		length = index - startin;
		tree->pLeft = reConstructBinaryTree(pre, startpre + 1, startpre + 1 + length - 1, in, startin, startin + length - 1);
	}

	//�����������ݹ�
	if (index < endin)
	{
		length = endin - index;
		tree->pRight = reConstructBinaryTree(pre, endpre - length + 1, endpre, in, endin - length + 1, endin);
	}
	return tree;
}
void postTraverse(Bitree* tree)
{
	if (tree->pLeft != NULL) postTraverse(tree->pLeft);
	if (tree->pRight != NULL) postTraverse(tree->pRight);
	printf("%d ", tree->val);
}

int main()
{
	int preOrder[] = { 1, 2, 4, 5, 3, 6 };
	int inOrder[] = { 4, 2, 5, 1, 6, 3 };
	Bitree* tree = reConstructBinaryTree(preOrder, 0, 5, inOrder, 0, 5);
	postTraverse(tree);
	printf("\n");
	return 0;
	return 0;
}