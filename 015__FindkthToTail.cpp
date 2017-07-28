#include<iostream>
using namespace std;

struct ListNode {
	int m_nValue;
	ListNode * m_pNext;
};

ListNode * FindkthToTail(ListNode *p_Head, unsigned int k)
{
	if (p_Head == NULL || k == 0)
		return NULL;
	ListNode *p_fast = p_Head;
	ListNode *p_slow = p_Head;
	for (int i = 0; i < k - 1; i++)
	{
		if (p_fast->m_pNext != NULL)
			p_fast = p_fast->m_pNext;
		else
			return NULL;
	}
	while (p_fast->m_pNext != NULL)
	{
		p_slow = p_slow->m_pNext;
		p_fast = p_fast->m_pNext;
	}
	return p_slow;
	
}

int main()
{

	return 0;
}