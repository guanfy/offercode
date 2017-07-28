#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
	stack<int> sta;
	stack<int> minsta;
	void push(int x)
	{
		sta.push(x);
		if (minsta.empty())
		{	 
			minsta.push(x);
		}
		else
		{
			sta.push(x);
			if (x <= minsta.top())
			{
				minsta.push(x);
			}
			else
			{
				minsta.push(minsta.top());
			}
		}
	}

	void pop()
	{
		if (!sta.empty())
		{
			sta.pop();
			minsta.pop();
		}
	}
	int top()
	{
		if (!sta.empty())
		{
			return sta.top();
		}
		
	}
	int minvalue()
	{
		if (!minsta.empty())
		{
			return minsta.top();
		}
		else
		{
			return -1;
		}
	}
};


int main()
{
	MinStack s1;
	s1.push(2);
	cout << s1.minvalue() << endl;
	s1.push(1);
	cout << s1.minvalue() << endl;
	s1.push(0);
	cout << s1.minvalue() << endl;
	s1.pop();
	cout << s1.minvalue() << endl;
	s1.pop();
	cout << s1.minvalue() << endl;
	s1.pop();
	cout << s1.minvalue() << endl;
	return 0;
}