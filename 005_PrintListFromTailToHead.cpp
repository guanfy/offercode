#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

vector<int> printListFromTailToHead(ListNode* head) {
	/*
	//栈实现方法
	stack<int> values;
	vector<int> result;
	while(head != NULL){
	values.push(head->val);
	head = head->next;
	}
	while(!values.empty()){
	int value = values.top();
	result.push_back(value);
	values.pop();
	}
	return result;
	*/

	//递归方法实现
	vector<int> result;
	if (head != NULL){
		if (head->next != NULL){
			result = printListFromTailToHead(head->next);
		}
		result.push_back(head->val);
	}
	return result;
}