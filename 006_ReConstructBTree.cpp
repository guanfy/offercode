#include<iostream>
#include<vector>
using namespace std;

//typedef 是C语言的一种关键字，作用：为一种数据类型定义一个新名字。
typedef struct TreeNode{
	int val;
	struct TreeNode *pLeft;
	struct TreeNode *pRight;
	TreeNode(int x) :val(x), pLeft(NULL), pRight(NULL){}
}Bitree;


Bitree* reConstructBinaryTree(int pre[], int startpre, int endpre, int in[], int startin, int endin)
{
	//先序遍历和中序遍历的长度需相等
	if (endpre - startpre != endin - startin)
		return NULL;
	if (startpre > endpre)
		return NULL;
	//先序遍历的第一个节点为根节点
	Bitree* tree = new Bitree(pre[startpre]);

	//如果只有一个元素时，返回
	if (startpre == endpre)
		return tree;

	//在中序中找根节点
	int index, length;
	for (index = startin; index <= endin; index++)
	{
		if (in[index] == pre[startpre]) break;
	}

	//若未找到，返回空
	if (index > endin) return NULL;

	//有左子树，递归
	if (index > startin)
	{
		length = index - startin;
		tree->pLeft = reConstructBinaryTree(pre, startpre + 1, startpre + 1 + length - 1, in, startin, startin + length - 1);
	}

	//有右子树，递归
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