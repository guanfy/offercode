#include<iostream>
#include<stack>
using namespace std;

class StackMin {
public:
	void push(const int x) {
		m_data.push(x);
		if (m_min.empty() || x < m_min.top())
		{
			m_min.push(x);
		}
		else
		{			
				m_min.push(m_min.top());
		}
	}

	void pop()
	{
		if (!m_data.empty())
		{
			m_data.pop();
			m_min.pop();
		}
	}

	int min() const 
	{
		if (!m_min.empty())
			return m_min.top();
		else
			return -1;
	}
private:
	stack<int> m_data;
	stack<int> m_min;
};




int main()
{
	StackMin s1;
	s1.push(2);
	cout << s1.min() << endl;
	s1.push(5);
	cout << s1.min() << endl;
	s1.push(0);
	cout << s1.min() << endl;
	s1.push(10);
	cout << s1.min() << endl;
	s1.push(1);
	cout << s1.min() << endl;
	s1.pop();
	cout << s1.min() << endl;
	s1.pop();
	cout << s1.min() << endl;
	s1.pop();
	cout << s1.min() << endl;
	s1.pop();
	cout << s1.min() << endl;
	s1.pop();
	cout << s1.min() << endl;

	return 0;
}