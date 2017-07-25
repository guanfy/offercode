/*********************************
# File Name: 005_1List.cpp
*********************************/

#include<iostream>
using namespace std;

struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
};
ListNode* CreateList(int n)
{
	if (n <= 0)
	{
		cout << "输入结点个数有误！" << endl;
		exit(EXIT_FAILURE);
	}
	ListNode *pHead;
	ListNode *pCur, *pPre;
	int i;
	pHead = new ListNode();
	pHead->m_pNext = NULL;
	pPre = pHead;
	for (i = 1; i <= n; i++)
	{
		cout << "请输入第" << i << "个结点的值" << endl;
		pCur = new ListNode();
		cin >> pCur->m_nValue;
		pCur->m_pNext = NULL;
		pPre->m_pNext = pCur;
		pPre = pCur;
	}
	return pHead;
}

void AddToTail(ListNode** pHead,int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if(*pHead == NULL)
    {
	*pHead = pNew;
    }
    else
    {
	ListNode* pNode = *pHead;
	while(pNode ->m_pNext != NULL)
	{
	    pNode = pNode->m_pNext;
	}
	pNode->m_pNext = pNew;
    }
}

void DelNode(ListNode **pHead,int value)
{
	if (*pHead == NULL)
		return;
	ListNode* pNode = *pHead;
	if (pNode->m_pNext->m_pNext == NULL)
	{
		if (pNode->m_pNext->m_nValue == value)
		{
			pNode = pNode->m_pNext;
			*pHead = pNode->m_pNext;
			delete pNode;	
		}
	}
	else
	{
		while (pNode->m_pNext->m_pNext != NULL)
		{
			if (pNode->m_pNext->m_nValue != value)
			{
				pNode = pNode->m_pNext;
				continue;
			}
			else
			{
				ListNode* pDel = pNode->m_pNext;
				pNode->m_pNext = pNode->m_pNext->m_pNext;
				delete pDel;
			}
		}
		if (pNode->m_pNext->m_nValue == value)
		{
			ListNode* pDel = pNode->m_pNext;
			pNode->m_pNext = NULL;
			delete pDel;
		}
	}
}

void PrintList(ListNode *pHead)
{
	if (pHead == NULL)
		return;
	ListNode *p = pHead->m_pNext;
	while (p->m_pNext != NULL)
	{
		cout << p->m_nValue << '\t';
		p = p->m_pNext;
	}
	cout << p->m_nValue << endl;;
}


int main()
{
	ListNode *head;
	head = CreateList(1);
	PrintList(head);
	DelNode(&head,5);
	PrintList(head);
	return 0;
}





