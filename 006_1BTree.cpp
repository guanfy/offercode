#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct BTreeNode{
	char data;
	BTreeNode* pLchild;
	BTreeNode* pRchild;
}BTNode,*BTree;

//�ݹ�ʵ��
//ǰ�򣬸�-��-��
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

//������-��-��
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

//������-��-��
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

//�ǵݹ�ʵ��
