
#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* CreateList(int n)
{
	ListNode *head;
	ListNode *pre;
	head = (ListNode *)malloc(sizeof(ListNode));
	head->m_pNext = NULL;
	pre = head;
	for (int i = 1; i <= n; i++)
	{
		//printf("请输入第%d个节点:", i);
		ListNode *pNode = (ListNode *)malloc(sizeof(ListNode));
		pNode->m_pNext = NULL;
		//fflush(stdin);
		//scanf("%d", &pNode->m_nValue);
		pNode->m_nValue = i;
		pre->m_pNext = pNode;
		pre = pNode;
	}	
	return head;
}
void PrintList(ListNode *pHead)
{
	ListNode *p = pHead->m_pNext;
	while (p)
	{
		cout << p->m_nValue << "--->";
		p = p->m_pNext;
	}
	cout << "END" << endl;
}



ListNode* ReverseList(ListNode *pHead)
{
	ListNode *ReverseHead = (ListNode *)malloc(sizeof(ListNode));
	ReverseHead->m_pNext = NULL;
	ListNode *pNode = pHead->m_pNext;
	ListNode *pPre = NULL;

	while (pNode != NULL)
	{
		ListNode *pNext = pNode->m_pNext;
		if (pNext == NULL)
			ReverseHead->m_pNext = pNode;
		pNode->m_pNext = pPre;
		pPre = pNode;
		pNode = pNext;
	}
	return ReverseHead;
}

int main()
{
	ListNode *pHead = CreateList(10);
	PrintList(pHead);
	pHead = ReverseList(pHead);
	PrintList(pHead);

	return 0;
}