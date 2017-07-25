#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct BTreeNode{
	char data;
	BTreeNode* pLchild;
	BTreeNode* pRchild;
}BTNode,*BTree;

//递归实现
//前序，根-左-右
void pre_traverse(BTree pTree)
{
	if (pTree)
	{
		cout << pTree->data;
		if (pTree->pLchild)
			pre_traverse(pTree->pLchild);
		if (pTree->pRchild)
			pre_traverse(pTree->pRchild);
	}
}

//中序，左-根-右
void in_traverse(BTree pTree)
{
	if (pTree)
	{
		if (pTree->pLchild)
			pre_traverse(pTree->pLchild);
		cout << pTree->data;
		if (pTree->pRchild)
			pre_traverse(pTree->pRchild);
	}
}

//后序，左-右-根
void beh_traverse(BTree pTree)
{
	if (pTree)
	{
		if (pTree->pLchild)
			beh_traverse(pTree->pLchild);
		if (pTree->pRchild)
			beh_traverse(pTree->pRchild);
		cout << pTree->data;
	}
}

//非递归实现
