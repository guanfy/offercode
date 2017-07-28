#include<iostream>
using namespace std;

struct ListNode {
	int n_value;
	ListNode * p_next;
};
void DeleteNode(ListNode **head, ListNode *ToBeDeleted)
{
	if (!head || !ToBeDeleted)
		return;
	// 若为中间节点
	if (ToBeDeleted->p_next != NULL)
	{
		ListNode *pNextNode = ToBeDeleted->p_next;
		ToBeDeleted->n_value = pNextNode->n_value;
		ToBeDeleted->p_next = pNextNode->p_next;
		delete pNextNode;
		pNextNode = NULL;
	 }//若为尾节点，也是头节点
	else if (*head == ToBeDeleted)
	{
		delete ToBeDeleted;
		*head = NULL;
		ToBeDeleted = NULL;
	}//若不是头节点，是尾节点
	else
	{
		ListNode *PreNode = *head;
		while (PreNode->p_next != ToBeDeleted)
			PreNode = PreNode->p_next;
		PreNode->p_next = NULL;
		delete ToBeDeleted;
		ToBeDeleted = NULL;
	}

}

int main()
{

	return 0;
}