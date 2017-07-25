#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
public:
	void push(int value)
	{
		q1.push(value);
	}
	void pop()
	{
		if (!q1.empty())
		{
			int size = q1.size();
			for (int i = 0; i < size - 1; i++){
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
			while (!q2.empty())
			{
				q1.push(q2.front());
				q2.pop();
			}
		}
		else
		{
			cout << "Error:Stack is empty!" << endl;
			return;
		}
		
	}
	void Print()
	{
		if (!q1.empty())
		{
			int size = q1.size();
			for (int i = 0; i < size;i++)
			{
				int tmp = q1.front();
				cout << tmp << ' ';
				q1.pop();
				q1.push(tmp);
			}
		}
		cout << endl;
	}

private:
	queue<int> q1;
	queue<int> q2;
};
int main()
{
	Solution c;
	c.push(1);
	c.pop();
	c.push(2);
	c.pop();
	c.push(3);
	//c.pop();
	//c.pop();
	c.Print();

	return 0;
}
