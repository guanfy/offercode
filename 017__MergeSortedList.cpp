#include<iostream>
using namespace std;

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* createList(int n)
{
	ListNode *phead, *pre;
	phead = (ListNode *)malloc(sizeof(ListNode));
	phead->m_pNext = NULL;
	pre = phead;

	for(int i = 1; i <= n;i++)
	{
		ListNode *pNode = (ListNode *)malloc(sizeof(ListNode));
		pNode->m_nValue = i;
		pNode->m_pNext = NULL;
		pre->m_pNext = pNode;
		pre = pNode;
	}
	return phead;
}


void PrintList(ListNode *phead)
{
	ListNode *pNode = phead->m_pNext;
	while (pNode != NULL)
	{
		cout << pNode->m_nValue<<"-->";
		pNode = pNode->m_pNext;
	}
	cout << "end"<< endl;
}

ListNode* MergeTwoSortedList(ListNode *L1, ListNode* L2)
{
	if (L1 == NULL)
		return L2;
	else if (L2 == NULL)
		return L1;
	ListNode *pMergeHead = NULL;
	if (L1->m_nValue <= L2->m_nValue)
	{
		pMergeHead = L1;
		pMergeHead->m_pNext = MergeTwoSortedList(L1->m_pNext, L2);
	}
	else
	{
		pMergeHead = L2;
		pMergeHead->m_pNext = MergeTwoSortedList(L1, L2->m_pNext);
	}
	return pMergeHead;
}


int main()
{
	ListNode *p = createList(3);
	PrintList(p);
	return 0;
}